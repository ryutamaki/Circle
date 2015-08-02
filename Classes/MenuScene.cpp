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

    // put character
    this->putEntityByEntityType(EntityType::CIRCLE);

    // This will start observing to find peers.
    // Set self.peerID in NetworkManager also.
    GameSceneManager::getInstance()->receiveMultiplayerInvitations();
}

void MenuScene::putEntityByEntityType(EntityType entityType)
{
    // put character
    Entity* entity = EntityFactory::createUserEntity(entityType);
    entity->setNormalizedPosition(Vec2(0.5f, 0.5f));

    this->addChild(entity);

    EventListenerTouchOneByOne* eventListener = EventListenerTouchOneByOne::create();
    eventListener->setSwallowTouches(true);
    eventListener->onTouchBegan = [this](Touch* touch, Event* event) {
            return true;
        };
    eventListener->onTouchEnded = [this](Touch* touch, Event* event) {
            PowerUpScene* powerUpScene = PowerUpScene::create();
            powerUpScene->setEntityType(EntityType::CIRCLE);
            Scene* scene = Scene::create();
            scene->addChild(powerUpScene);
            TransitionFade* transition = TransitionFade::create(SCENE_TRANSITION_DURATION, scene, SCENE_TRANSITION_COLOR);
            Director::getInstance()->pushScene(transition);
        };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, this);
}

#pragma mark Callbacks

void MenuScene::singlePlayerButtonPushed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        auto scene = StageSelectScene::createScene();
        TransitionFade* transition = TransitionFade::create(SCENE_TRANSITION_DURATION, scene, SCENE_TRANSITION_COLOR);
        Director::getInstance()->replaceScene(transition);
    }
}

void MenuScene::multiplayerButtonPushed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        GameSceneManager::getInstance()->showPeerList();
    }
}
