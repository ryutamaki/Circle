#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "Character.h"
#include "CharacterReader.h"
#include "Enemy.h"
#include "EnemyReader.h"

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

    Sprite* field = dynamic_cast<Sprite*>(rootNode->getChildByName("Field"));
    this->character = dynamic_cast<Character*>(field->getChildByName("Character"));
    this->enemy = dynamic_cast<Enemy*>(field->getChildByName("Enemy"));

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
}

#pragma mark - Private methods

#pragma mark View lifecycle

void GameScene::onEnter()
{
    Layer::onEnter();

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
        this->character->setMoveState(CharacterMoveState::NONE);
    };
    touchListener->onTouchEnded = [&](Touch* touch, Event* event)
    {
        this->character->setMoveState(CharacterMoveState::NONE);
    };

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    
}

#pragma mark Game logic

void GameScene::update(float dt)
{
    Vec2 enemyPosition = this->enemy->getPosition();
    Vec2 characterPosition = this->character->getPosition();

    // TODO: magic number
    if (enemyPosition.distance(characterPosition) < 80.0f)
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