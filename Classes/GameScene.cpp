#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "GameConstants.h"

#include "Character.h"
#include "CharacterReader.h"
#include "Enemy.h"
#include "EnemyReader.h"

#include "JSONPacker.h"

USING_NS_CC;

using namespace cocostudio::timeline;

#pragma mark - Public methods

#pragma mark Initializer

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("CharacterReader", (ObjectFactory::Instance) CharacterReader::getInstance);
    instance->registReaderObject("EnemyReader", (ObjectFactory::Instance) EnemyReader::getInstance);

    auto rootNode = CSLoader::createNode("GameScene.csb");

    Sprite* background = dynamic_cast<Sprite*>(rootNode->getChildByName("Background"));
    this->field = dynamic_cast<Sprite*>(background->getChildByName("Field"));
    this->character = dynamic_cast<Character*>(this->field->getChildByName("Character"));
    this->enemy = dynamic_cast<Enemy*>(this->field->getChildByName("Enemy"));

    addChild(rootNode);

    this->setupUserInterfaces(rootNode);
    this->setupTouchHandling();
    this->networkedSession = false;

    return true;
}

#pragma mark Networking

void GameScene::setNetworkedSession(bool networkedSession)
{
    this->networkedSession = networkedSession;
}

void GameScene::receivedData(const void *data, unsigned long length)
{
    const char* cstr = reinterpret_cast<const char*>(data);
    std::string json = std::string(cstr, length);
    JSONPacker::EntityState entityState = JSONPacker::unpackEntityStateJSON(json);

    this->friendCharacter->stateMachine->setMoveState(entityState.moveState);
    this->friendCharacter->stateMachine->setAttackState(entityState.attackState);
}

#pragma mark - Private methods

#pragma mark View lifecycle

void GameScene::onEnter()
{
    Layer::onEnter();

    // Define battle field Rect
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Size fieldSize = this->field->getContentSize();

    if (this->networkedSession)
    {
        this->friendCharacter = dynamic_cast<Character*>(CSLoader::createNode("Character.csb"));
        this->friendCharacter->setNormalizedPosition(Vec2(0.2f, 0.5f));
        this->friendCharacter->setAnchorPoint(Vec2(0.5f, 0.5f));
        this->addChild(this->friendCharacter);
    }

    this->scheduleUpdate();
}

void GameScene::setupUserInterfaces(Node* rootNode)
{
    ui::Button* attackButton = dynamic_cast<ui::Button*>(rootNode->getChildByName("AButton"));
    attackButton->addTouchEventListener(CC_CALLBACK_2(GameScene::attackButtonPushed, this));
}

void GameScene::setupTouchHandling()
{
    static Vec2 firstTouchPosition;
    static Vec2 lastTouchPosition;

    EventListenerTouchOneByOne* touchListener = EventListenerTouchOneByOne::create();

    touchListener->onTouchBegan = [&](Touch* touch, Event* event)
    {
        firstTouchPosition = this->convertTouchToNodeSpace(touch);
        lastTouchPosition = firstTouchPosition;
        return true;
    };
    touchListener->onTouchMoved = [&](Touch* touch, Event* event)
    {
        Vec2 currentTouchPosition = this->convertTouchToNodeSpace(touch);
        // TODO: magic number
        if (lastTouchPosition.distance(currentTouchPosition) < 10.0f)
        {
            return;
        }

        this->character->setMoveStateByStartPositionAndCurrentPosition(lastTouchPosition, currentTouchPosition);

        lastTouchPosition = currentTouchPosition;
    };
    touchListener->onTouchCancelled = [&](Touch* touch, Event* event)
    {
        this->character->stateMachine->stopMoving();
    };
    touchListener->onTouchEnded = [&](Touch* touch, Event* event)
    {
        this->character->stateMachine->stopMoving();
    };

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    
}

#pragma mark Game logic

void GameScene::update(float dt)
{
    Vector<Node*> fieldChildren = this->field->getChildren();
    for (int index = 0; index < fieldChildren.size(); ++index)
    {
        Entity* entity = dynamic_cast<Entity*>(fieldChildren.at(index));
        if (!entity)
            return;

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
            entityNextRect.getMaxY() >= this->field->getContentSize().height - BATTLE_FIELD_FRAME_THICKNESS)
        {
            entity->stateMachine->stopMoving();
        }
        else
        {
            Vec2 nextEntityPosition = entity->getPosition() + entity->getVelocity();
            entity->setPosition(nextEntityPosition);
        }

    }

    if (this->character->stateMachine->getAttackState() == EntityAttackState::ATTAKING)
    {
        // TODO: magic number
        if (this->character->getPosition().distance(this->enemy->getPosition()) < 100.0f)
        {
            // TODO: magic number
            this->character->stateMachine->hitAttack();
            this->enemy->receiveDamage(10, (this->enemy->getPosition() - this->character->getPosition()) / 2.0f);
        }
    }

    if (this->enemy->stateMachine->getAttackState() == EntityAttackState::ATTAKING)
    {
        // TODO: magic number
        if (this->enemy->getPosition().distance(this->character->getPosition()) < 200.0f)
        {
            // TODO: magic number
            this->enemy->stateMachine->hitAttack();
            this->character->receiveDamage(10, (this->character->getPosition() - this->enemy->getPosition()) / 2.0f);
        }
    }

    Rect characterRect = this->character->getRect();
    Rect enemyRect = this->enemy->getRect();
    if (enemyRect.intersectsRect(characterRect))
    {
        // TODO: magic number
        this->character->receiveDamage(5, this->character->getPosition() - this->enemy->getPosition());
    }

    this->checkGameOver();
}

void GameScene::checkGameOver()
{
    if (this->character->isDead())
    {
        Director::getInstance()->popScene();
        MessageBox("Player hit point is 0", "YOU LOSE");
    }
    else if (this->enemy->isDead())
    {
        Director::getInstance()->popScene();
        MessageBox("Enemy hit point is 0", "YOU WIN");
    }
}

#pragma mark Callbacks

void GameScene::attackButtonPushed(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED)
    {
        this->character->attack("Attack");
    }
}