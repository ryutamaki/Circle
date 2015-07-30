//
// MenuScene.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/15.
//
//

#include "MenuScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "GameScene.h"
#include "GameSceneManager.h"

#include "PowerUpScene.h"

#include "StageSelectScene.h"
#include "EntityFactory.h"

USING_NS_CC;

#pragma mark - Public methods

#pragma mark Initializer

Scene* MenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = MenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool MenuScene::init()
{
    if (! Layer::init()) {
        return false;
    }

    auto rootNode = CSLoader::createNode("MenuScene.csb");

    Size visibleSize = Director::getInstance()->getVisibleSize();
    rootNode->setContentSize(visibleSize);
    ui::Helper::doLayout(rootNode);

    this->field = rootNode->getChildByName<Sprite*>("Field");
    ui::Button* singlePlayerButton = rootNode->getChildByName<ui::Button*>("SinglePlayerButton");
    ui::Button* multiplayerButton = rootNode->getChildByName<ui::Button*>("MultiplayerButton");

    singlePlayerButton->addTouchEventListener(CC_CALLBACK_2(MenuScene::singlePlayerButtonPushed, this));
    multiplayerButton->addTouchEventListener(CC_CALLBACK_2(MenuScene::multiplayerButtonPushed, this));

    this->addChild(rootNode);

    return true;
}

#pragma mark - Private methods

#pragma mark View lifecycle

void MenuScene::onEnter()
{
    Layer::onEnter();

    // TODO: field should be a custom object
    float fieldScaleFactor = 1.0f;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Size fieldSize = this->field->getContentSize();

    fieldScaleFactor = MIN(visibleSize.height / fieldSize.height, visibleSize.width / fieldSize.width);
    this->field->setScale(fieldScaleFactor);

    // put character
    this->putEntityByEntityType(EntityType::CIRCLE);

    // This will start observing to find peers.
    // Set self.peerID in NetworkManager also.
    GameSceneManager::getInstance()->receiveMultiplayerInvitations();
}

void MenuScene::putEntityByEntityType(EntityType entityType)
{
    // put character
    Entity* entity = EntityFactory::createUserEntityWityEntityType(entityType);
    entity->setNormalizedPosition(Vec2(0.5f, 0.5f));

    this->field->addChild(entity);

    EventListenerTouchOneByOne* eventListerner = EventListenerTouchOneByOne::create();
    eventListerner->onTouchBegan = [this](Touch* touch, Event* event) {
            return true;
        };
    eventListerner->onTouchEnded = [this](Touch* touch, Event* evetn) {
            PowerUpScene* powerUpScene = PowerUpScene::create();
            powerUpScene->setEntityType(EntityType::CIRCLE);
            Scene* scene = Scene::create();
            scene->addChild(powerUpScene);
            Director::getInstance()->pushScene(scene);
        };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListerner, this->field);
}

#pragma mark Callbacks

void MenuScene::singlePlayerButtonPushed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        auto scene = StageSelectScene::createScene();
        Director::getInstance()->replaceScene(scene);
    }
}

void MenuScene::multiplayerButtonPushed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        GameSceneManager::getInstance()->showPeerList();
    }
}
