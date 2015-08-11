#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "EntityAI.h"
#include "Coin.h"
#include "GamePauseLayer.h"
#include "GamePauseLayerReader.h"
#include "GameResultLayer.h"
#include "GameResultLayerReader.h"
#include "TutorialLayer.h"
#include "TutorialLayerReader.h"
#include "ScoreLabel.h"
#include "ScoreLabelReader.h"
#include "CoinLabel.h"
#include "CoinLabelReader.h"

#include "JSONPacker.h"
#include "EntityFactory.h"
#include "GameSceneManager.h"
#include "UserDataManager.h"
#include "FlurryHelper.h"

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
    CSLoader::getInstance()->registReaderObject("CoinLabelReader", (ObjectFactory::Instance)CoinLabelReader::getInstance);

    auto rootNode = CSLoader::createNode("GameScene.csb");

    Size visibleSize = Director::getInstance()->getVisibleSize();
    rootNode->setContentSize(visibleSize);
    ui::Helper::doLayout(rootNode);

    this->field = rootNode->getChildByName<Sprite*>("Field");
    this->coinContainer = std::unique_ptr<CoinContainer>(new CoinContainer());
    this->scoreLabel = this->field->getChildByName<ScoreLabel*>("ScoreLabel");
    this->coinLabel = this->field->getChildByName<CoinLabel*>("CoinLabel");
    this->totalCoinCount = 0;
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

    this->entityFactory = std::unique_ptr<EntityFactory>(new EntityFactory());
    this->entityContainer = std::unique_ptr<EntityContainer>(new EntityContainer());

    this->networkedSession = false;
    this->gameState = GameState::PREPARE;
    this->counterToForceSpawnEnemy = 0.0f;
    this->defeatEnemyCount = 0;
    this->nextEnemyIndex = ENEMY_INITIAL_IDENTIFIER;

    return true;
}

#pragma mark Entity setup

// TODO: multi の時の味方のポジション同期をなんとかする
void GameScene::setCharacterByEntityType(EntityType entityType)
{
    bool isHost = GameSceneManager::getInstance()->isHost();
    EntityParameterLevel parameterLevel = UserDataManager::getInstance()->getEntityParameterLevel(entityType);
    this->character = this->entityFactory->createFriend(isHost, entityType, parameterLevel);
    this->character->setNormalizedPosition(Vec2(0.3f, 0.5f));
    this->character->setRotation(0.0f);
    this->field->addChild(this->character, 2);

    if (this->networkedSession) {
        // sync settings for myself
        this->character->synchronizer->setIsSendData(true);
        this->character->synchronizer->setIsHost(isHost);
        this->character->synchronizer->setIsMyself(true);
    }

    this->entityContainer->addFriend(this->character->getIdentifier(), this->character);
}

void GameScene::setFriendCharacter(EntityType entityType, EntityParameterLevel parameterLevel)
{
    if (! this->networkedSession) {
        return;
    }
    bool isHost = GameSceneManager::getInstance()->isHost();

    this->friendCharacter = this->entityFactory->createFriend(! isHost, entityType, parameterLevel);
    this->friendCharacter->setNormalizedPosition(Vec2(0.3f, 0.5f));
    this->friendCharacter->setRotation(0.0f);
    this->field->addChild(this->friendCharacter, 1);

    // sync settigns for another player
    // TODO: player は二人だと思ってる
    this->friendCharacter->synchronizer->setIsSendData(false); // receive only
    this->friendCharacter->synchronizer->setIsHost(! isHost);

    this->entityContainer->addFriend(this->friendCharacter->getIdentifier(), this->friendCharacter);
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
    this->entityContainer->pauseAllEntity();
}

void GameScene::resumeGame()
{
    if (this->gameState != GameState::PLAYING) {
        return;
    }

    this->resume();
    this->entityContainer->resumeAllEntity();
}

#pragma mark Networking

void GameScene::setNetworkedSession(bool networkedSession)
{
    this->networkedSession = networkedSession;

    if (this->networkedSession) {
        this->pauseButton->removeFromParent();
    }
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

        if (! this->friendCharacter) {
            this->setFriendCharacter(entityReadyState.entityType, entityReadyState.parameterLevel);
            this->friendCharacter->synchronizer->setIsReadyToPlay(entityReadyState.isReady);
        }

        this->tryToStart();
    } else if (this->gameState == GameState::PLAYING) {
        JSONPacker::EntityState entityState = JSONPacker::unpackEntityStateJSON(json);

        if (! GameSceneManager::getInstance()->isHost()) {
            if (entityState.globalState == EntityGlobalState::READY) {
                this->nextEnemyInitialPosition = entityState.position;

                if (entityState.identifier == this->nextEnemyIndex) {
                    this->spawnNextEnemy(this->enemyParameterLevel(this->nextEnemyIndex));
                }
            }
        }

        Entity* target = this->entityContainer->findEntity(entityState.identifier);

        if (target == nullptr || target->stateMachine->getGlobalState() != EntityGlobalState::ALIVE) {
            return;
        }

        if (target->getPosition().distance(entityState.position) > 80.0f) {
            target->setPosition(entityState.position);
        }

        // log("identifier: %s, hp: %d, move: %d, attack: %d, damage target: %s, damage volume: %d, position: {%f, %f}", entityState.identifier.c_str(), entityState.hp, entityState.moveState, entityState.attackState, entityState.damage.identifier.c_str(), entityState.damage.volume, entityState.position.x, entityState.position.y);
        target->setHp(entityState.hp);

        // TODO: magic number
        if (entityState.moveState == EntityMoveState::NONE) {
            target->stateMachine->stop();
        } else if (entityState.moveState == EntityMoveState::MOVING) {
            target->stateMachine->move(entityState.direction);
        }

        if (entityState.attackState == EntityAttackState::READY) {
            target->attack(entityState.attackName);
        } else if (entityState.attackState == EntityAttackState::CHARGING) {
            target->startCharging();
        }

        if (entityState.damage.volume != 0) {
            Entity* damagedTarget = this->entityContainer->findEntity(entityState.damage.identifier);

            if (damagedTarget != nullptr) {
                damagedTarget->receiveDamage(entityState.damage.volume, entityState.position);
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

    this->setupTouchHandling();
    this->showTutorialBasicIfNeverSeen();

    // log for analytics
    if (this->networkedSession) {
        FlurryHelper::logTransitionScene(FlurryHelper::SCENE_NAME_GAME_MULTI);
    } else {
        FlurryHelper::logTransitionScene(FlurryHelper::SCENE_NAME_GAME_SINGLE);
    }
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

            EntityDirection direction = EntityHelper::directionFromStartPositionAndEndPosition(lastTouchPosition, currentTouchPosition);

            if (direction != this->character->stateMachine->getDirection()) {
                this->character->stateMachine->move(direction);
            }
            lastTouchPosition = currentTouchPosition;
        };
    touchListenerForMove->onTouchCancelled = [this](Touch* touch, Event* event) {
            this->character->stateMachine->stop();
        };
    touchListenerForMove->onTouchEnded = [this](Touch* touch, Event* event) {
            this->character->stateMachine->stop();
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
                this->character->attack("ChargeAttack");
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

        if (entity->stateMachine->isDead()) {
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
            entity->stateMachine->stop();
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

    this->checkGameOver();
}

void GameScene::damageEnemyFromCharacter()
{
    // そもそも攻撃していなかった
    if (this->character->stateMachine->getAttackState() != EntityAttackState::ATTACKING) {
        return;
    }

    std::vector<Rect> characterRects = this->character->getRectsUseForAttackInWorldSpace();

    for (auto& kv : this->entityContainer->getAllEnemies()) {
        Entity* enemy = static_cast<Entity*>(kv.second);
        std::vector<Rect> enemyRects = enemy->getRectsUseForDamageInWorldSpace();

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
            continue;
        }

        // 攻撃が当たった！
        std::string currentAttackName = this->character->getCurrentAttackName();
        EntityAttackParams attackParams = this->character->getAttackParamsByName(currentAttackName);
        int damage = attackParams.damageFactor * this->character->getEntityParameter().attackFactor;

        JSONPacker::EntityState currentEntityState = this->character->currentEntityState();
        currentEntityState.damage.identifier = enemy->getIdentifier();
        currentEntityState.damage.volume = damage;
        this->character->synchronizer->sendData(currentEntityState);

        enemy->receiveDamage(damage, this->character->getPosition());
        enemy->synchronizer->sendData(enemy->currentEntityState());

        // Change attack state at last
        this->character->stateMachine->hitAttack();
    }
}

void GameScene::checkDeadEnemy(float dt)
{
    // log("before: alive: %lu   dead:%zd", this->aliveEnemyAndAiList.size(), this->deadEnemyList.size());

    std::map<EntityIdentifier, Entity*> enemies = this->entityContainer->getAllEnemies();

    for (auto& kv : enemies) {
        Entity* enemy = static_cast<Entity*>(kv.second);

        if (enemy && ! enemy->stateMachine->isDead()) {
            continue;
        }

        this->entityContainer->moveEnemyToCemetery(kv.first);

        // give voin to user when defeat some of enemy
        // いつ終了しても、そこまでのコインの付与が完了しているようにしたいため、敵が死んだのを確認した時点でコインを付与する
        int coinCountToGive = enemy->getEntityParameterLevel().rank + 1;
        this->giveCoin(enemy->getEntityParameterLevel().rank + 1);
        this->totalCoinCount += coinCountToGive;

        // update gamestate
        this->defeatEnemyCount++;
        this->scoreLabel->setScore(this->defeatEnemyCount);
    }

    // log("before: alive: %lu   dead:%zd", this->aliveEnemyAndAiList.size(), this->deadEnemyList.size());
}

void GameScene::damageCharacterFromEntity()
{
    std::vector<Rect> characterRects = this->character->getRectsUseForDamageInWorldSpace();
    std::map<EntityIdentifier, Entity*> enemies = this->entityContainer->getAllEnemies();

    for (auto& kv : enemies) {
        Entity* enemy = static_cast<Entity*>(kv.second);

        // そもそも攻撃していなかった
        if (enemy->stateMachine->getAttackState() != EntityAttackState::ATTACKING) {
            continue;
        }

        std::vector<Rect> enemyRects = enemy->getRectsUseForAttackInWorldSpace();

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
            continue;
        }

        std::string currentAttackName = enemy->getCurrentAttackName();
        EntityAttackParams attackParams = enemy->getAttackParamsByName(currentAttackName);
        int damage = attackParams.damageFactor * enemy->getEntityParameter().attackFactor;

        JSONPacker::EntityState currentEntityState = enemy->currentEntityState();
        currentEntityState.damage.identifier = this->character->getIdentifier();
        currentEntityState.damage.volume = damage;
        enemy->synchronizer->sendData(currentEntityState);

        this->character->receiveDamage(damage, enemy->getPosition());
        JSONPacker::EntityState currentCharacterState = this->character->currentEntityState();
        this->character->synchronizer->sendData(currentCharacterState);

        enemy->stateMachine->hitAttack();
    }
}

EntityAI* GameScene::attachAI(Entity* entity)
{
    cocos2d::Vector<Entity*> opponents;

    if (this->character && ! this->character->stateMachine->isDead()) {
        opponents.pushBack(this->character);
    }

    if (this->networkedSession && this->friendCharacter && ! this->friendCharacter->stateMachine->isDead()) {
        opponents.pushBack(this->friendCharacter);
    }
    EntityAI* enemyAi = new EntityAI(entity, opponents);
    this->addChild(enemyAi);

    return enemyAi;
}

EntityParameterLevel GameScene::enemyParameterLevel(int nextEnemyIndex)
{
    int maxRank = EntityHelper::getMaxRank();
    int rank = MIN(static_cast<int>(floor(nextEnemyIndex / 10.0f)), maxRank);
    int hpLevel = nextEnemyIndex;
    int attackLevel = nextEnemyIndex;

    EntityParameterLevel paramterLevel = {rank, hpLevel, attackLevel};
    return paramterLevel;
}

void GameScene::tryToSpawnNextEnemy(float dt)
{
    EntityParameterLevel nextEnemyParameterLevel = this->enemyParameterLevel(this->nextEnemyIndex);

    this->counterToForceSpawnEnemy += dt;

    // force spawn duration を越えてたら強制的に spawn する
    if (this->counterToForceSpawnEnemy > ENEMY_FORCE_SPAWN_DURATION) {
        this->counterToForceSpawnEnemy = 0.0f;
        this->spawnNextEnemy(this->enemyParameterLevel(this->nextEnemyIndex));
        return;
    }

    // force spawn duration を越えてなくても、ememy が上限に達していない場合は spawn する
    if (this->entityContainer->canSpawnEnemy(this->character->getEntityParameterLevel().rank, nextEnemyParameterLevel.rank)) {
        this->counterToForceSpawnEnemy = 0.0f;
        this->spawnNextEnemy(this->enemyParameterLevel(this->nextEnemyIndex));
        return;
    }
}

void GameScene::spawnNextEnemy(EntityParameterLevel parameterLevel)
{
    Entity* newEnemy = this->entityFactory->createEnemy(
            this->enemyEntityType,
            parameterLevel
        );
    EntityAI* enemyAi = GameSceneManager::getInstance()->isHost() ? this->attachAI(newEnemy) : nullptr;
    this->entityContainer->addEnemy(newEnemy->getIdentifier(), newEnemy);
    this->entityContainer->addAi(newEnemy->getIdentifier(), enemyAi);

    // set properties
    Size fieldSize = this->field->getContentSize();

    if (GameSceneManager::getInstance()->isHost()) {
        this->nextEnemyInitialPosition = Vec2(
                fieldSize.width * 0.5 + CCRANDOM_MINUS1_1() * fieldSize.width * 0.3f,
                fieldSize.height * 0.5 + CCRANDOM_MINUS1_1() * fieldSize.height * 0.3f + fieldSize.height * 2.0f
            );
    }

    newEnemy->setPosition(this->nextEnemyInitialPosition);
    this->nextEnemyInitialPosition = Vec2::ZERO;

    // sync settings for an enemy
    if (this->networkedSession) {
        newEnemy->synchronizer->setIsSendData(GameSceneManager::getInstance()->isHost());
        newEnemy->synchronizer->setIsHost(false);
        newEnemy->synchronizer->setIsMyself(false);
    }

    this->field->addChild(newEnemy);
    newEnemy->stateMachine->ready();

    // animate next entity
    float spawnDuration = 1.5f;
    newEnemy->setScale(3.0f);
    auto moveTo = MoveTo::create(
            spawnDuration,
            Vec2(
                newEnemy->getPosition().x,
                newEnemy->getPosition().y - fieldSize.height * 2.0f
            )
        );
    auto scaleTo = ScaleTo::create(spawnDuration, 1.0f);
    auto spawn = Spawn::create(moveTo, scaleTo, NULL);
    auto bounceEaseOut = EaseBounceInOut::create(spawn);
    auto sequence = Sequence::create(
            bounceEaseOut,
            CallFunc::create([newEnemy, enemyAi]() {
        newEnemy->activate();

        if (enemyAi) {
            enemyAi->start();
        }
    }),
            NULL);
    newEnemy->runAction(sequence);

    // update index
    ++this->nextEnemyIndex;
}

void GameScene::gameover()
{
    /* TODO: あげたコインの数が正しいかここで確認したい。
     *  dead を判定して、コインをあげている関数が 0.2 秒間隔で回っているため、コインの付与に誤差が生じる可能性がある。
     * そのため、ここで、dead をもう一度判定して、足り無い分は足してあげたい。
     */
    // First: Change state and stop this game
    this->gameState = GameState::RESULT;
    this->unscheduleAllCallbacks();

    // Second: Pause all entities
    this->entityContainer->pauseAllEntity();

    // Third:
    int score = this->defeatEnemyCount;
    int currentHighScore = UserDataManager::getInstance()->getHighScoreByEntityType(this->enemyEntityType);
    bool isNewRecord = score > currentHighScore ? true : false;
    int highScore = isNewRecord ? score : currentHighScore;
    this->showResultLayer(score, highScore, isNewRecord, this->totalCoinCount);
}

void GameScene::checkGameOver()
{
    if (this->networkedSession) {
        if (this->character->stateMachine->isDead() && this->friendCharacter->stateMachine->isDead()) {
            this->gameover();
        }
    } else {
        if (this->character->stateMachine->isDead()) {
            this->gameover();
        }
    }
}

void GameScene::giveCoin(int coinCount)
{
    int currentCoinCount = UserDataManager::getInstance()->getCoinCount();
    int newCoinCount = currentCoinCount + coinCount;
    UserDataManager::getInstance()->setCoinCount(newCoinCount);
    this->coinLabel->setCoinCount(newCoinCount);
}

#pragma mark Transitions

void GameScene::showTutorialBasicIfNeverSeen()
{
    if (UserDataManager::getInstance()->getIsShownTutorial(TutorialType::BASIC_CONTROL)) {
        return;
    }

    if (! this->lobbyButton) {
        return;
    }

    CSLoader::getInstance()->registReaderObject("TutorialLayerReader", (ObjectFactory::Instance)TutorialLayerReader::getInstance);
    TutorialLayer* tutorialLayer = dynamic_cast<TutorialLayer*>(CSLoader::createNode("TutorialLayer.csb"));

    this->lobbyButton->addChild(tutorialLayer);
    tutorialLayer->show(TutorialType::BASIC_CONTROL);
}

void GameScene::showPauseLayer()
{
    CSLoader::getInstance()->registReaderObject("GamePauseLayerReader", (ObjectFactory::Instance)GamePauseLayerReader::getInstance);
    GamePauseLayer* pauseLayer = dynamic_cast<GamePauseLayer*>(CSLoader::createNode("GamePauseLayer.csb"));
    pauseLayer->show(this->field);
}

void GameScene::showResultLayer(int score, int highscore, bool isNewRecord, int coinCount)
{
    CSLoader::getInstance()->registReaderObject("GameResultLayerReader", (ObjectFactory::Instance)GameResultLayerReader::getInstance);
    GameResultLayer* gameResult = dynamic_cast<GameResultLayer*>(CSLoader::createNode("GameResultLayer.csb"));

    gameResult->show(this->field);

    gameResult->setScore(score);
    gameResult->setHighScore(highscore, isNewRecord);
    gameResult->setCoinCount(coinCount);
    gameResult->setNetworked(this->networkedSession);
}

void GameScene::readyToStart(Ref* pSender, ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        this->character->synchronizer->setIsReadyToPlay(true);

        Entity* myself = this->entityContainer->findMyself();

        JSONPacker::EntityReadyState entityReadyState;
        entityReadyState.identifier = myself->getIdentifier();
        entityReadyState.isReady = this->character->synchronizer->getIsReadyToPlay();
        entityReadyState.entityType = this->character->getEntityType();
        entityReadyState.parameterLevel = this->character->getEntityParameterLevel();

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
        if (! this->character->synchronizer->getIsReadyToPlay()) {
            return;
        }

        if (! this->friendCharacter || ! this->friendCharacter->synchronizer->getIsReadyToPlay()) {
            return;
        }
        this->start();
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

    // Initial enemy
    if (GameSceneManager::getInstance()->isHost()) {
        // this->spawnNextEnemy(0.0f);
        this->schedule(CC_SCHEDULE_SELECTOR(GameScene::tryToSpawnNextEnemy));
    }
    this->schedule(CC_SCHEDULE_SELECTOR(GameScene::checkDeadEnemy), 0.2f);

    this->lobbyButton->removeFromParent();
    this->lobbyButton = nullptr;

    this->scheduleUpdate();

    if (this->character) {
        log("%d, host: %d, myself: %d, senddata: %d, isdead: %d",
            this->character->getIdentifier(),
            this->character->synchronizer->getIsHost(),
            this->character->synchronizer->getIsMyself(),
            this->character->synchronizer->getIsSendData(),
            this->character->stateMachine->isDead());
    }

    if (this->friendCharacter) {
        log("%d, host: %d, myself: %d, senddata: %d, isdead: %d",
            this->friendCharacter->getIdentifier(),
            this->friendCharacter->synchronizer->getIsHost(),
            this->friendCharacter->synchronizer->getIsMyself(),
            this->friendCharacter->synchronizer->getIsSendData(),
            this->friendCharacter->stateMachine->isDead());
    }
}

#pragma mark networking

void GameScene::disconnected()
{
    if (! this->networkedSession) {
        return;
    }

    if (this->gameState == GameState::RESULT) {
        GameSceneManager::getInstance()->exitGameScene();
        return;
    }

    // kill friend character
    this->friendCharacter->setHp(0);

    // attach AI if you are not a host user
    if (! this->character->synchronizer->getIsHost()) {
        for (auto& kv : this->entityContainer->getAllEnemies()) {
            EntityIdentifier identifier = kv.first;
            Entity* enemy = static_cast<Entity*>(kv.second);

            EntityAI* ai = this->entityContainer->findAi(identifier);

            if (! ai) {
                enemy->stateMachine->cancelAttack();
                enemy->stateMachine->stop();
                EntityAI* ai = this->attachAI(enemy);
                ai->start();
                this->entityContainer->addAi(identifier, ai);
            }
        }

        this->character->synchronizer->setIsHost(true);
    }

    // unable network session
    this->setNetworkedSession(false);
    this->character->synchronizer->setIsSendData(false);

    this->schedule(CC_SCHEDULE_SELECTOR(GameScene::tryToSpawnNextEnemy));
}
