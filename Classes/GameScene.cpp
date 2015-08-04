#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "EnemyAI.h"
#include "Coin.h"
#include "GamePauseLayer.h"
#include "GamePauseLayerReader.h"
#include "GameResultLayer.h"
#include "GameResultLayerReader.h"
#include "ScoreLabel.h"
#include "ScoreLabelReader.h"

#include "JSONPacker.h"
#include "EntityFactory.h"
#include "GameSceneManager.h"
#include "UserDataManager.h"

USING_NS_CC;

using namespace cocostudio::timeline;

#pragma mark - Public methods

#pragma mark Initializer

bool GameScene::init()
{
    if (! Layer::init()) {
        return false;
    }

    CSLoader::getInstance()->registReaderObject("ScoreLabelReader", (ObjectFactory::Instance)ScoreLabelReader::getInstance);

    auto rootNode = CSLoader::createNode("GameScene.csb");

    Size visibleSize = Director::getInstance()->getVisibleSize();
    rootNode->setContentSize(visibleSize);
    ui::Helper::doLayout(rootNode);

    this->field = rootNode->getChildByName<Sprite*>("Field");
    this->coinContainer = std::unique_ptr<CoinContainer>(new CoinContainer());
    this->scoreLabel = this->field->getChildByName<ScoreLabel*>("ScoreLabel");
    this->lobbyButton = rootNode->getChildByName<ui::Button*>("LobbyButton");
    this->lobbyButton->addTouchEventListener(CC_CALLBACK_2(GameScene::readyToStart, this));

    this->pauseButton = this->field->getChildByName<ui::Button*>("PauseButton");
    this->pauseButton->addTouchEventListener([this](Ref* pSender, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            GameSceneManager::getInstance()->pauseGameScene();
            this->showPauseLayer();
        }
    });

    this->addChild(rootNode);

    this->networkedSession = false;
    this->gameState = GameState::PREPARE;
    this->defeatEnemyCount = 0;

    return true;
}

#pragma mark Entity setup

// TODO: multi の時の味方のポジション同期をなんとかする
void GameScene::setCharacterByEntityType(EntityType entityType)
{
    this->character = EntityFactory::createUserEntity(entityType);
    this->character->setNormalizedPosition(Vec2(0.2f, 0.5f));
    this->character->setRotation(0.0f);
    this->field->addChild(this->character);
}

void GameScene::setFriendCharacter(EntityType entityType)
{
    this->friendCharacter = EntityFactory::createEntity(entityType);
    this->friendCharacter->setNormalizedPosition(Vec2(0.2f, 0.5f));
    this->friendCharacter->setRotation(0.0f);
    this->field->addChild(this->friendCharacter);
}

void GameScene::setEnemyEntityType(EntityType entityType)
{
    this->enemyEntityType = entityType;
}

EntityType GameScene::getEnemyEntityType()
{
    return this->enemyEntityType;
}

#pragma mark Game lifecycle

void GameScene::pauseGame()
{
    if (this->gameState != GameState::PLAYING) {
        return;
    }

    this->pause();

    this->character->pause();
    this->currentEnemy->pause();
    this->enemyAI->stop();

    if (this->friendCharacter && ! this->friendCharacter->getIsDead()) {
        this->friendCharacter->pause();
    }
}

void GameScene::resumeGame()
{
    if (this->gameState != GameState::PLAYING) {
        return;
    }

    this->resume();

    this->character->resume();
    this->currentEnemy->resume();
    this->enemyAI->start();

    if (this->friendCharacter && ! this->friendCharacter->getIsDead()) {
        this->friendCharacter->resume();
    }
}

#pragma mark Networking

void GameScene::setNetworkedSession(bool networkedSession)
{
    this->networkedSession = networkedSession;
}

void GameScene::receivedData(const void* data, unsigned long length)
{
    if (! this->networkedSession) {
        return;
    }

    const char* cstr = reinterpret_cast<const char*>(data);
    std::string json = std::string(cstr, length);

    if (this->gameState == GameState::PREPARE) {
        JSONPacker::EntityReadyState entityReadyState = JSONPacker::unpackEntityReadyStateJSON(json);

        if (this->friendCharacter) {
            this->friendCharacter->setIdentifier(entityReadyState.identifier);
            this->friendCharacter->synchronizer->setIsReadyToPlay(entityReadyState.isReady);
        }

        this->tryToStart();
    } else if (this->gameState == GameState::PLAYING) {
        JSONPacker::EntityState entityState = JSONPacker::unpackEntityStateJSON(json);

        Entity* target = this->getTargetEntityByTargetString(entityState.identifier);

        if (target == nullptr) {
            return;
        }

        // log("identifier: %s, hp: %d, move: %d, attack: %d, damage target: %s, damage volume: %d, position: {%f, %f}", entityState.identifier.c_str(), entityState.hp, entityState.moveState, entityState.attackState, entityState.damage.identifier.c_str(), entityState.damage.volume, entityState.position.x, entityState.position.y);
        target->setHp(entityState.hp);
        target->setPosition(entityState.position);
        target->stateMachine->move(entityState.moveState);

        if (entityState.attackState == EntityAttackState::READY) {
            target->attack("Attack");
        }

        if (entityState.damage.volume != 0) {
            Entity* damagedTarget = this->getTargetEntityByTargetString(entityState.damage.identifier);

            if (damagedTarget != nullptr) {
                int currentHp = damagedTarget->getHp();
                damagedTarget->setHp(currentHp - entityState.damage.volume);
            }
        }
    }
}

#pragma mark - Private methods

#pragma mark View lifecycle

void GameScene::onEnter()
{
    Layer::onEnter();

    // TODO: field should be a custom object
    float fieldScaleFactor = 1.0f;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Size fieldSize = this->field->getContentSize();

    fieldScaleFactor = MIN(visibleSize.height / fieldSize.height, visibleSize.width / fieldSize.width);
    this->field->setScale(fieldScaleFactor);

    if (this->networkedSession) {
        bool isHost = GameSceneManager::getInstance()->isHost();
        // sync settings for myself
        this->character->synchronizer->setIsSendData(true);
        this->character->synchronizer->setIsHost(isHost);
        this->character->synchronizer->setIsMyself(true);

        // sync settigns for another player
        // TODO: player は二人だと思ってる
        this->friendCharacter->synchronizer->setIsSendData(false); // receive only
        this->friendCharacter->synchronizer->setIsHost(! isHost);
    }

    this->setupTouchHandling();
}

void GameScene::setupTouchHandling()
{
    static Vec2 firstTouchPosition;
    static Vec2 lastTouchPosition;

    EventListenerTouchOneByOne* touchListenerForMove = EventListenerTouchOneByOne::create();
    touchListenerForMove->onTouchBegan = [this](Touch* touch, Event* event) {
            if (this->gameState == GameState::RESULT) {
                return false;
            }
            Vec2 position = this->convertTouchToNodeSpace(touch);

            if (position.x < Director::getInstance()->getVisibleSize().width * 0.5f) {
                firstTouchPosition = this->convertTouchToNodeSpace(touch);
                lastTouchPosition = firstTouchPosition;
                return true;
            }
            return false;
        };
    touchListenerForMove->onTouchMoved = [this](Touch* touch, Event* event) {
            Vec2 currentTouchPosition = this->convertTouchToNodeSpace(touch);

            if (lastTouchPosition.distance(currentTouchPosition) < SENSITIVITY_TO_CONTROL_PLAYER) {
                return;
            }

            EntityMoveState moveState = EntityHelper::moveStateFromStartPositionAndEndPosition(lastTouchPosition, currentTouchPosition);

            if (moveState == this->character->stateMachine->getMoveState()) {
                return;
            }

            this->character->stateMachine->move(moveState);

            lastTouchPosition = currentTouchPosition;
        };
    touchListenerForMove->onTouchCancelled = [this](Touch* touch, Event* event) {
            this->character->stateMachine->move(EntityMoveState::NONE);
        };
    touchListenerForMove->onTouchEnded = [this](Touch* touch, Event* event) {
            this->character->stateMachine->move(EntityMoveState::NONE);
        };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListenerForMove, this->field);

    EventListenerTouchOneByOne* touchListenerForAttack = EventListenerTouchOneByOne::create();
    touchListenerForAttack->onTouchBegan = [&](Touch* touch, Event* event) {
            if (this->gameState == GameState::RESULT) {
                return false;
            }
            Vec2 position = this->convertTouchToNodeSpace(touch);

            if (position.x >= Director::getInstance()->getVisibleSize().width * 0.5f) {
                this->isAttackTouching = true;
                this->touchStartTime = clock();
                return true;
            }
            return false;
        };
    touchListenerForAttack->onTouchEnded = [&](Touch* touch, Event* event) {
            this->isAttackTouching = false;

            if (this->character->stateMachine->isCharging()) {
                this->character->endCharging();
            } else {
                this->character->attack("Attack");
            }
            this->touchStartTime = 0;
        };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListenerForAttack, this->field);
}

#pragma mark Game logic

void GameScene::update(float dt)
{
    Vector<Node*> fieldChildren = this->field->getChildren();

    for (int index = 0; index < fieldChildren.size(); ++index) {
        Entity* entity = dynamic_cast<Entity*>(fieldChildren.at(index));

        if (! entity) {
            continue;
        }

        if (entity->getIsDead()) {
            continue;
        }

        Rect entityRect = entity->getBodyRect();
        Rect entityNextRect = Rect(
                entityRect.origin.x + entity->getVelocity().x,
                entityRect.origin.y + entity->getVelocity().y,
                entityRect.size.width, entityRect.size.height
            );

        // if a character collide to
        if (entityNextRect.getMinX() <= BATTLE_FIELD_FRAME_THICKNESS ||
            entityNextRect.getMinY() <= BATTLE_FIELD_FRAME_THICKNESS ||
            entityNextRect.getMaxX() >= this->field->getContentSize().width - BATTLE_FIELD_FRAME_THICKNESS ||
            entityNextRect.getMaxY() >= this->field->getContentSize().height - BATTLE_FIELD_FRAME_THICKNESS) {
            entity->stateMachine->move(EntityMoveState::NONE);
        } else {
            Vec2 nextEntityPosition = entity->getPosition() + entity->getVelocity();
            entity->setPosition(nextEntityPosition);
        }
    }

    // FIXME: この辺の処理がよくない
    // touch end で、どの攻撃を出すか判定してる
    if (this->isAttackTouching) {
        float touchDuration = static_cast<float>(clock() - this->touchStartTime) / CLOCKS_PER_SEC;

        if (touchDuration > ENTITY_CHARGE_START_DURATION) {
            this->character->startCharging();
        }
    }

    this->damageEnemyFromCharacter();
    this->damageCharacterFromEntity();

    this->checkSpawnNextEnemy();
    this->checkGameOver();
}

void GameScene::damageEnemyFromCharacter()
{
    // そもそも攻撃していなかった
    if (this->character->stateMachine->getAttackState() != EntityAttackState::ATTACKING) {
        return;
    }

    // this rects does not effected by animations
    std::vector<Rect> characterRects = this->character->getRectsUseForAttackInWorldSpace();
    std::vector<Rect> enemyRects = this->currentEnemy->getRectsUseForDamageInWorldSpace();

    // collisions check
    bool hitFlag = false;

    for (Rect characterRect : characterRects) {
        for (Rect enemyRect : enemyRects) {
            if (characterRect.intersectsRect(enemyRect)) {
                hitFlag = true;
                break;
            }
        }
    }

    if (! hitFlag) {
        return;
    }

    // 攻撃が当たった！
    std::string currentAttackName = this->character->getCurrentAttackName();
    AttackParams attackParams = this->character->getAttackParamsByName(currentAttackName);
    int damage = attackParams.damageFactor * this->character->getEntityParameter().attackFactor;

    JSONPacker::EntityState currentEntityState = this->character->currentEntityState();
    currentEntityState.damage.identifier = this->currentEnemy->getIdentifier();
    currentEntityState.damage.volume = damage;
    this->character->synchronizer->sendData(currentEntityState);

    // for (int i = 0; i < 10; ++i) {
    // Coin* coin = this->coinContainer->fetchCoin();
    // coin->setPosition(this->currentEnemy->getCenter() + Vec2(CCRANDOM_MINUS1_1() * 10.0f, CCRANDOM_MINUS1_1() * 10.0f)));
    // this->field->addChild(coin);
    // }

    if (this->character->synchronizer->getIsHost()) {
        this->currentEnemy->setHp(this->currentEnemy->getHp() - damage);

        JSONPacker::EntityState currentEntityState = this->currentEnemy->currentEntityState();
        this->currentEnemy->synchronizer->sendDataIfNotHost(currentEntityState);
    }

    // Change attack state at last
    this->character->stateMachine->hitAttack();
}

void GameScene::damageCharacterFromEntity()
{
    // そもそも攻撃していなかった
    if (this->currentEnemy->stateMachine->getAttackState() != EntityAttackState::ATTACKING) {
        return;
    }

    // this rects does not effected by animations
    std::vector<Rect> enemyRects = this->currentEnemy->getRectsUseForAttackInWorldSpace();
    std::vector<Rect> characterRects = this->character->getRectsUseForDamageInWorldSpace();

    // collisions check
    bool hitFlag = false;

    for (Rect characterRect : characterRects) {
        for (Rect enemyRect : enemyRects) {
            if (characterRect.intersectsRect(enemyRect)) {
                hitFlag = true;
                break;
            }
        }
    }

    if (! hitFlag) {
        return;
    }

    std::string currentAttackName = this->currentEnemy->getCurrentAttackName();
    AttackParams attackParams = this->currentEnemy->getAttackParamsByName(currentAttackName);
    int damage = attackParams.damageFactor * this->currentEnemy->getEntityParameter().attackFactor;

    JSONPacker::EntityState currentEntityState = this->currentEnemy->currentEntityState();
    currentEntityState.damage.identifier = this->character->getIdentifier();
    currentEntityState.damage.volume = damage;
    this->currentEnemy->synchronizer->sendData(currentEntityState);

    this->character->setHp(this->character->getHp() - damage);
    JSONPacker::EntityState currentCharacterState = this->character->currentEntityState();
    this->character->synchronizer->sendData(currentCharacterState);

    this->currentEnemy->stateMachine->hitAttack();
}

void GameScene::spawnNextEnemy()
{
    // decide a side enemy is spawn
    bool isRightSide = true;

    // Flash current enemy first
    if (this->currentEnemy) {
        Entity* tmpEntity = this->currentEnemy;
        tmpEntity->deactivate();

        this->currentEnemy = nullptr;

        if (this->enemyAI) {
            this->enemyAI->removeFromParent();
            this->enemyAI = nullptr;
        }

        // update score
        ++this->defeatEnemyCount;
        this->scoreLabel->setScore(this->defeatEnemyCount);

        isRightSide = CCRANDOM_MINUS1_1() < 0.0f;
    }

    // pop next enemy from enemy queue
    this->currentEnemy = EntityFactory::createEntity(this->enemyEntityType, this->defeatEnemyCount, CIRCLE_ORANGE);

    // set properties
    Size fieldSize = this->field->getContentSize();
    this->currentEnemy->setIdentifier("Enemy" + std::to_string(this->defeatEnemyCount));

    Vec2 initialPosition;
    float rotation;

    // TODO: magic number
    if (isRightSide) {
        initialPosition = Vec2(fieldSize.width * 0.8f, fieldSize.height * 2.0f);
        rotation = 180.0f;
    } else {
        initialPosition = Vec2(fieldSize.width * 0.2f, fieldSize.height * 2.0f);
        rotation = 0.0f;
    }
    this->currentEnemy->setPosition(initialPosition);
    this->currentEnemy->setRotation(rotation);
    this->field->addChild(this->currentEnemy);

    // animate next entity
    float spawnDuration = 1.5f;
    this->currentEnemy->setScale(3.0f);
    auto moveTo = MoveTo::create(spawnDuration, Vec2(this->currentEnemy->getPosition().x, fieldSize.height * 0.5f));
    auto scaleTo = ScaleTo::create(spawnDuration, 1.0f);
    auto spawn = Spawn::create(moveTo, scaleTo, NULL);
    auto bounceEaseOut = EaseBounceInOut::create(spawn);
    this->currentEnemy->runAction(bounceEaseOut);

    // activate enemy
    this->currentEnemy->activate();

    // setup enemyAI
    if (GameSceneManager::getInstance()->isHost()) {
        cocos2d::Vector<Entity*> opponents;
        opponents.pushBack(this->character);

        if (this->networkedSession) {
            opponents.pushBack(this->friendCharacter);
        }
        this->enemyAI = new EnemyAI(this->currentEnemy, opponents);
        this->addChild(this->enemyAI);

        this->enemyAI->start();
    }

    // sync settings for an enemy
    if (this->networkedSession) {
        this->currentEnemy->synchronizer->setIsSendData(GameSceneManager::getInstance()->isHost());
        this->currentEnemy->synchronizer->setIsHost(false);
        this->currentEnemy->synchronizer->setIsMyself(false);
    }
}

void GameScene::checkSpawnNextEnemy()
{
    if (this->currentEnemy->getIsDead()) {
        this->spawnNextEnemy();
    }
}

void GameScene::gameover()
{
    // First: Update user data because this is most important
    this->giveCoin();
    UserDataManager::getInstance()->setHighScoreByEntityType(this->defeatEnemyCount, this->enemyEntityType);

    // Second: Change state and stop this game
    this->gameState = GameState::RESULT;
    this->unscheduleUpdate();

    if (this->enemyAI) {
        this->enemyAI->stop();
    }

    // Third:
    int score = this->defeatEnemyCount;
    int currentHighScore = UserDataManager::getInstance()->getHighScoreByEntityType(this->enemyEntityType);
    bool isNewRecord = score > currentHighScore ? true : false;
    int highScore = isNewRecord ? score : currentHighScore;
    this->showResultLayer(score, highScore, isNewRecord);
}

void GameScene::checkGameOver()
{
    if (this->networkedSession) {
        if (this->character->getIsDead() && this->friendCharacter->getIsDead()) {
            this->gameover();
        }
    } else {
        if (this->character->getIsDead()) {
            this->gameover();
        }
    }
}

void GameScene::giveCoin()
{
    int currentCoinCount = UserDataManager::getInstance()->getCoinCount();
    int newCoinCount = currentCoinCount + this->defeatEnemyCount;
    log("pre: %d, new: %d", currentCoinCount, newCoinCount);
    UserDataManager::getInstance()->setCoinCount(newCoinCount);
}

Entity* GameScene::getTargetEntityByTargetString(std::string targetString)
{
    Entity* target = nullptr;
    Vector<Node*> fieldChildren = this->field->getChildren();

    for (int index = 0; index < fieldChildren.size(); ++index) {
        Entity* entity = dynamic_cast<Entity*>(fieldChildren.at(index));

        if (! entity) {
            continue;
        }

        std::string identifier = entity->getIdentifier();

        if (identifier == targetString) {
            target = entity;
            return target;
        }
    }

    return target;
}

#pragma mark Transitions

void GameScene::showPauseLayer()
{
    CSLoader::getInstance()->registReaderObject("GamePauseLayerReader", (ObjectFactory::Instance)GamePauseLayerReader::getInstance);
    GamePauseLayer* pauseLayer = dynamic_cast<GamePauseLayer*>(CSLoader::createNode("GamePauseLayer.csb"));
    pauseLayer->show(this->field);
}

void GameScene::showResultLayer(int score, int highscore, bool isNewRecord)
{
    CSLoader::getInstance()->registReaderObject("GameResultLayerReader", (ObjectFactory::Instance)GameResultLayerReader::getInstance);
    GameResultLayer* gameResult = dynamic_cast<GameResultLayer*>(CSLoader::createNode("GameResultLayer.csb"));

    gameResult->show(this->field);

    gameResult->setScore(score);
    gameResult->setHighScore(highscore, isNewRecord);
    gameResult->setCoinCount(score);
}

void GameScene::readyToStart(Ref* pSender, ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        this->character->synchronizer->setIsReadyToPlay(true);

        JSONPacker::EntityReadyState entityReadyState;
        entityReadyState.identifier = GameSceneManager::getInstance()->getUniqueIdentifier();
        entityReadyState.isReady = this->character->synchronizer->getIsReadyToPlay();

        this->character->setIdentifier(GameSceneManager::getInstance()->getUniqueIdentifier());
        this->character->synchronizer->sendData(entityReadyState);
        this->tryToStart();
    }
}

void GameScene::tryToStart()
{
    if (this->gameState != GameState::PREPARE) {
        return;
    }

    if (this->networkedSession) {
        if (this->character->synchronizer->getIsReadyToPlay() &&
            this->friendCharacter->synchronizer->getIsReadyToPlay()) {
            this->start();
        }
    } else {
        if (this->character->synchronizer->getIsReadyToPlay()) {
            this->start();
        }
    }
}

void GameScene::start()
{
    this->gameState = GameState::PLAYING;

    this->character->activate();

    if (this->friendCharacter) {
        this->friendCharacter->activate();
    }

    this->spawnNextEnemy();

    this->lobbyButton->removeFromParent();
    this->lobbyButton = nullptr;

    this->scheduleUpdate();

    if (this->character) {
        log("%s, host: %d, myself: %d, senddata: %d, isdead: %d",
            this->character->getIdentifier().c_str(),
            this->character->synchronizer->getIsHost(),
            this->character->synchronizer->getIsMyself(),
            this->character->synchronizer->getIsSendData(),
            this->character->getIsDead());
    }

    if (this->friendCharacter) {
        log("%s, host: %d, myself: %d, senddata: %d, isdead: %d",
            this->friendCharacter->getIdentifier().c_str(),
            this->friendCharacter->synchronizer->getIsHost(),
            this->friendCharacter->synchronizer->getIsMyself(),
            this->friendCharacter->synchronizer->getIsSendData(),
            this->friendCharacter->getIsDead());
    }
}
