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
    this->fieldRect = Rect(
                           (visibleSize.width - fieldSize.width) * 0.5f + BATTLE_FIELD_FRAME_THICKNESS,
                           (visibleSize.height - fieldSize.height) * 0.5f + BATTLE_FIELD_FRAME_THICKNESS,
                           fieldSize.width - BATTLE_FIELD_FRAME_THICKNESS * 2,
                           fieldSize.height - BATTLE_FIELD_FRAME_THICKNESS * 2
                           );

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

        Vec2 entityNextPosition = entity->getPosition() + entity->getVelocity();
        Size entityBodySize = entity->getBodySize();

        // if a character collide to
        if (entityNextPosition.x - entityBodySize.width * 0.5f <= BATTLE_FIELD_FRAME_THICKNESS
            || entityNextPosition.y - entityBodySize.height * 0.5f <= BATTLE_FIELD_FRAME_THICKNESS
            || entityNextPosition.x + entityBodySize.width * 0.5f >= BATTLE_FIELD_FRAME_THICKNESS + this->fieldRect.size.width
            || entityNextPosition.y + entityBodySize.height * 0.5f >= BATTLE_FIELD_FRAME_THICKNESS + this->fieldRect.size.height)
        {
            entity->stateMachine->stopMoving();
        }
        else
        {
            entity->setPosition(entityNextPosition);
        }
    }



    Vec2 enemyPosition = this->enemy->getPosition();
    Vec2 characterPosition = this->character->getPosition();
    Rect characterRect = Rect(
                              this->character->getPosition().x - this->character->getAnchorPoint().x * this->character->getBodySize().width,
                              this->character->getPosition().y - this->character->getAnchorPoint().y * this->character->getBodySize().height,
                              this->character->getBodySize().width, this->character->getBodySize().height
    );
    Rect enemyRect = Rect(
                              this->enemy->getPosition().x - this->enemy->getAnchorPoint().x * this->enemy->getBodySize().width,
                              this->enemy->getPosition().y - this->enemy->getAnchorPoint().y * this->enemy->getBodySize().height,
                              this->enemy->getBodySize().width, this->enemy->getBodySize().height
    );

    if (enemyRect.intersectsRect(characterRect))
    {
        // TODO: magic number
        this->character->receiveDamage(5, characterPosition - enemyPosition);
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
        this->character->attack();
        // TODO: magic number
        if (this->character->getPosition().distance(this->enemy->getPosition()) < 100.0f)
        {
            // TODO: magic number
            this->enemy->recieveDamage(10, (this->enemy->getPosition() - this->character->getPosition()) / 2.0f);
        }
    }
}