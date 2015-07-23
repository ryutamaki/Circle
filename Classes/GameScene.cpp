#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "GameConstants.h"

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

    ui::Button* overlayButton = dynamic_cast<ui::Button*>(this->background->getChildByName("Overlay"));
    overlayButton->addTouchEventListener(CC_CALLBACK_2(GameScene::startGame, this));

    addChild(rootNode);

    this->networkedSession = false;

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
    JSONPacker::EntityState entityState = JSONPacker::unpackEntityStateJSON(json);

    Entity* target = this->getTargetEntityByTargetString(entityState.target);

    if (target == nullptr) {
        return;
    }

    log("%s, %d, %d, %d, %s, %d", entityState.target.c_str(), entityState.hp, entityState.moveState, entityState.attackState, entityState.damage.target.c_str(), entityState.damage.volume);
    target->setHp(entityState.hp);
    target->setPosition(entityState.position);
    target->stateMachine->move(entityState.moveState);

    if (entityState.attackState == EntityAttackState::READY) {
        target->attack("Attack");
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
        this->character->setIdentifier("Player");
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
        currentEntityState.damage.target = "Enemy";
        currentEntityState.damage.target = 10;
        this->character->synchronizer->sendData(currentEntityState);

        if (this->character->synchronizer->getIsHost()) {
            // TODO: magic number
            this->enemy->receiveDamage(10, Vec2::ZERO);

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
        this->character->receiveDamage(10, this->character->getPosition() - this->enemy->getPosition());
    }

    this->checkGameOver();
}

void GameScene::checkGameOver()
{
    if (this->networkedSession) {
        if (this->character->isDead() && this->friendCharacter->isDead()) {
            SceneManager::getInstance()->exitGameScene();
            MessageBox("Player hit point is 0", "YOU LOSE");
        }
    } else {
        if (this->character->isDead()) {
            SceneManager::getInstance()->exitGameScene();
            MessageBox("Player hit point is 0", "YOU LOSE");
        }
    }

    if (this->enemy->isDead()) {
        SceneManager::getInstance()->exitGameScene();
        MessageBox("Enemy hit point is 0", "YOU WIN");
    }
}

void GameScene::startGame(Ref* pSender, ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        if (this->enemyAI) {
            this->enemyAI->start();
        }
        this->background->removeChildByName("Overlay");
        this->background = nullptr;
    }
}

Entity* GameScene::getTargetEntityByTargetString(std::string targetString)
{
    // TODO: 2人対戦までしかできないようになってる
    // できることなら、Entity::identifier に UUID を突っ込んで、誰がどれを操作してるのかを明確にしたい
    // そうすれば、3人以上の対戦に対応できる
    Entity* target = nullptr;

    if (targetString == "Enemy") {
        target = this->enemy;
    } else if (targetString == "Player") {
        target = this->friendCharacter;
    }

    return target;
}
