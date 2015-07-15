#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "Character.h"
#include "CharacterReader.h"
#include "Enemy.h"
#include "EnemyReader.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
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

    ui::Button* attackButton = dynamic_cast<ui::Button*>(rootNode->getChildByName("AButton"));
    attackButton->addTouchEventListener(CC_CALLBACK_2(HelloWorld::attackButtonPushed, this));

    addChild(rootNode);

    this->setupTouchHandling();

    return true;
}

#pragma mark - Private methods

void HelloWorld::onEnter()
{
    Layer::onEnter();

    Size visibleSize = Director::getInstance()->getVisibleSize();
}

void HelloWorld::setupTouchHandling()
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
        // TODO: Define sensitivity
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

#pragma mark Callbacks

void HelloWorld::attackButtonPushed(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED)
    {
        this->character->attack();
        // TODO: temporary
        if (this->character->getPosition().distance(this->enemy->getPosition()) < 60.0f)
        {
            this->enemy->recieveAttack(10);
            if (this->enemy->getHp() < 0)
            {
                MessageBox("Enemy hit point is 0", "YOU WIN");
            }
        }
    }
}