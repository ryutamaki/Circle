#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "Character.h"
#include "CharacterReader.h"
#include "Enemy.h"
#include "EnemyReader.h"

#include "EnemyAI.h"

#include "JSONPacker.h"
#include "SceneManager.h"

USING_NS_CC;

using namespace cocostudio::timeline;

#pragma mark - Public methods

#pragma mark Initializer

bool GameScene::init()
{
    if (! Layer::init()) {
        return false;
    }

    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("CharacterReader", (ObjectFactory::Instance)CharacterReader::getInstance);
    instance->registReaderObject("EnemyReader", (ObjectFactory::Instance)EnemyReader::getInstance);

    auto rootNode = CSLoader::createNode("GameScene.csb");

    this->background = dynamic_cast<Sprite*>(rootNode->getChildByName("Background"));
    this->field = dynamic_cast<Sprite*>(this->background->getChildByName("Field"));
    this->character = dynamic_cast<Character*>(this->field->getChildByName("Character"));
    this->enemy = dynamic_cast<Enemy*>(this->field->getChildByName("Enemy"));

    this->lobbyButton = dynamic_cast<ui::Button*>(this->background->getChildByName("LobbyButton"));
    this->lobbyButton->addTouchEventListener(CC_CALLBACK_2(GameScene::readyToStart, this));

    addChild(rootNode);

    this->networkedSession = false;
    this->gameState = GameState::PREPARE;

    return true;
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

        log("%s, %d, %d, %d, %s, %d", entityState.identifier.c_str(), entityState.hp, entityState.moveState, entityState.attackState, entityState.damage.identifier.c_str(), entityState.damage.volume);
        target->setHp(entityState.hp);
        target->setPosition(entityState.position);
        target->stateMachine->move(entityState.moveState);

        if (entityState.attackState == EntityAttackState::READY) {
            target->attack("Attack");
        }

        if (entityState.damage.volume != 0) {
            Entity* damagedTarget = this->getTargetEntityByTargetString(entityState.damage.identifier);

            if (damagedTarget != nullptr) {
                damagedTarget->receiveDamage(entityState.damage.volume);
            }
        }
    }
}

#pragma mark - Private methods

#pragma mark View lifecycle

void GameScene::onEnter()
{
    Layer::onEnter();

    if (this->networkedSession) {
        bool isHost = SceneManager::getInstance()->isHost();

        this->friendCharacter = dynamic_cast<Character*>(CSLoader::createNode("Character.csb"));
        // TODO: magic number
        this->friendCharacter->setNormalizedPosition(Vec2(0.2f, 0.5f));
        this->friendCharacter->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
        this->field->addChild(this->friendCharacter);

        // sync settings for myself
        this->character->synchronizer->setIsSendData(true);
        this->character->synchronizer->setIsHost(isHost);
        this->character->synchronizer->setIsMyself(true);

        // sync settigns for another player
        // TODO: player は二人だと思ってる
        this->friendCharacter->synchronizer->setIsSendData(false); // receive only
        this->friendCharacter->synchronizer->setIsHost(! isHost);
        this->friendCharacter->synchronizer->setIsMyself(false);

        // sync settings for an enemy
        this->enemy->setIdentifier("Enemy");
        this->enemy->synchronizer->setIsSendData(isHost);
        this->enemy->synchronizer->setIsHost(false);
        this->enemy->synchronizer->setIsMyself(false);

        if (isHost) {
            cocos2d::Vector<Entity*> opponents;
            opponents.pushBack(this->character);
            this->enemyAI = new EnemyAI(this->enemy, opponents);
            this->addChild(this->enemyAI);
        }
    } else {
        cocos2d::Vector<Entity*> opponents;
        opponents.pushBack(this->character);
        this->enemyAI = new EnemyAI(this->enemy, opponents);
        this->addChild(this->enemyAI);
    }

    this->setupTouchHandling();

    this->scheduleUpdate();
}

void GameScene::setupTouchHandling()
{
    static Vec2 firstTouchPosition;
    static Vec2 lastTouchPosition;

    EventListenerTouchOneByOne* touchListenerForMove = EventListenerTouchOneByOne::create();
    touchListenerForMove->onTouchBegan = [this](Touch* touch, Event* event) {
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

            this->character->setMoveStateByStartPositionAndCurrentPosition(lastTouchPosition, currentTouchPosition);

            lastTouchPosition = currentTouchPosition;
        };
    touchListenerForMove->onTouchCancelled = [this](Touch* touch, Event* event) {
            this->character->stateMachine->move(EntityMoveState::NONE);
        };
    touchListenerForMove->onTouchEnded = [this](Touch* touch, Event* event) {
            this->character->stateMachine->move(EntityMoveState::NONE);
        };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListenerForMove, this);

    EventListenerTouchOneByOne* touchListenerForAttack = EventListenerTouchOneByOne::create();
    touchListenerForAttack->onTouchBegan = [&](Touch* touch, Event* event) {
            Vec2 position = this->convertTouchToNodeSpace(touch);

            if (position.x >= Director::getInstance()->getVisibleSize().width * 0.5f) {
                return true;
            }
            return false;
        };
    touchListenerForAttack->onTouchEnded = [&](Touch* touch, Event* event) {
            this->character->attack("Attack");
        };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListenerForAttack, this);
}

#pragma mark Game logic

void GameScene::update(float dt)
{
    // log("%f, %f", this->friendCharacter->getVelocity().x, this->friendCharacter->getVelocity().y);

    Vector<Node*> fieldChildren = this->field->getChildren();

    for (int index = 0; index < fieldChildren.size(); ++index) {
        Entity* entity = dynamic_cast<Entity*>(fieldChildren.at(index));

        if (! entity) {
            return;
        }

        Rect entityRect = entity->getRect();
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

    // this rects does not effected by animations
    Rect characterRect = this->character->getRect();
    Rect enemyRect = this->enemy->getRect();

    // TODO: magic number
    if (this->character->stateMachine->getAttackState() == EntityAttackState::ATTACKING &&
        enemyRect.origin.distance(characterRect.origin) < 160.0f) {
        JSONPacker::EntityState currentEntityState = this->character->currentEntityState();
        currentEntityState.damage.identifier = "Enemy";
        currentEntityState.damage.volume = 10;
        this->character->synchronizer->sendData(currentEntityState);

        if (this->character->synchronizer->getIsHost()) {
            // TODO: magic number
            this->enemy->receiveDamage(10);

            JSONPacker::EntityState currentEntityState = this->enemy->currentEntityState();
            this->enemy->synchronizer->sendDataIfNotHost(currentEntityState);
        }

        // Change attack state at last
        this->character->stateMachine->hitAttack();
    }
    // TODO: magic number
    else if (this->enemy->stateMachine->getAttackState() == EntityAttackState::ATTACKING &&
             enemyRect.origin.distance(characterRect.origin) < 160.0f) {
        this->enemy->stateMachine->hitAttack();
        // TODO: magic number
        this->character->receiveDamage(10);
        JSONPacker::EntityState currentCharacterState = this->character->currentEntityState();
        this->character->synchronizer->sendData(currentCharacterState);
    }

    this->checkGameOver();
}

void GameScene::checkGameOver()
{
    if (this->networkedSession) {
        if (this->character->getIsDead() && this->friendCharacter->getIsDead()) {
            this->showResultLayerWithString("YOU LOSE");
        }
    } else {
        if (this->character->getIsDead()) {
            this->showResultLayerWithString("YOU LOSE");
        }
    }

    if (this->enemy->getIsDead()) {
        this->showResultLayerWithString("YOU WIN");
    }
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

void GameScene::showResultLayerWithString(std::string result)
{
    Node* gameResult = dynamic_cast<Node*>(CSLoader::createNode("GameResult.csb"));
    gameResult->setPosition(Vec2::ZERO);
    ui::TextBMFont* resultLabel = dynamic_cast<ui::TextBMFont*>(gameResult->getChildByName("ResultLabel"));
    resultLabel->setString(result);
    ui::Button* backButton = dynamic_cast<ui::Button*>(gameResult->getChildByName("BackButton"));
    backButton->addTouchEventListener(CC_CALLBACK_2(GameScene::backToMenu, this));
    this->background->addChild(gameResult);
}

void GameScene::readyToStart(Ref* pSender, ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        this->character->synchronizer->setIsReadyToPlay(true);

        JSONPacker::EntityReadyState entityReadyState;
        entityReadyState.identifier = SceneManager::getInstance()->getUniqueIdentifier();
        entityReadyState.isReady = this->character->synchronizer->getIsReadyToPlay();

        this->character->setIdentifier(SceneManager::getInstance()->getUniqueIdentifier());
        this->character->synchronizer->sendData(entityReadyState);
        this->tryToStart();
    }
}

void GameScene::backToMenu(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SceneManager::getInstance()->exitGameScene();
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

    if (this->enemyAI) {
        this->enemyAI->start();
    }
    this->background->removeChildByName("LobbyButton");

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
