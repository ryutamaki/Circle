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

#include "UserDataManager.h"
#include "StageSelectScene.h"
#include "EntityFactory.h"

#include "FlurryHelper.h"

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
    log("%f, %f", visibleSize.width, visibleSize.height);
    rootNode->setContentSize(visibleSize);
    ui::Helper::doLayout(rootNode);

    ui::Button* singlePlayerButton = rootNode->getChildByName<ui::Button*>("SinglePlayerButton");
    ui::Button* multiplayerButton = rootNode->getChildByName<ui::Button*>("MultiplayerButton");
    ui::Button* powerUpButton = rootNode->getChildByName<ui::Button*>("PowerUpButton");

    singlePlayerButton->addTouchEventListener(CC_CALLBACK_2(MenuScene::singlePlayerButtonPushed, this));
    multiplayerButton->addTouchEventListener(CC_CALLBACK_2(MenuScene::multiplayerButtonPushed, this));
    powerUpButton->addTouchEventListener(CC_CALLBACK_2(MenuScene::powerUpButtonPushed, this));

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

    // log for analytics
    FlurryHelper::logTransitionScene(FlurryHelper::SCENE_NAME_MENU);
}

void MenuScene::putEntityByEntityType(EntityType entityType)
{
    // put character
    EntityParameterLevel parameterLevel = UserDataManager::getInstance()->getEntityParameterLevel(entityType);
    std::unique_ptr<EntityFactory> factory = std::unique_ptr<EntityFactory>(new EntityFactory());
    bool isHost = true;
    Entity* entity = factory->createFriend(isHost, entityType, parameterLevel);
    entity->setNormalizedPosition(Vec2(0.5f, 0.6f));
    this->addChild(entity);
}

#pragma mark Callbacks

void MenuScene::singlePlayerButtonPushed(Ref* pSender, ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        auto scene = StageSelectScene::createScene();
        TransitionFade* transition = TransitionFade::create(SCENE_TRANSITION_DURATION, scene, SCENE_TRANSITION_COLOR);
        Director::getInstance()->replaceScene(transition);
    }
}

void MenuScene::multiplayerButtonPushed(Ref* pSender, ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        GameSceneManager::getInstance()->showPeerList();
    }
}

void MenuScene::powerUpButtonPushed(Ref* pSender, ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        PowerUpScene* powerUpScene = PowerUpScene::create();
        powerUpScene->setEntityType(EntityType::CIRCLE);
        Scene* scene = Scene::create();
        scene->addChild(powerUpScene);
        TransitionFade* transition = TransitionFade::create(SCENE_TRANSITION_DURATION, scene, SCENE_TRANSITION_COLOR);
        Director::getInstance()->pushScene(transition);
    }
}
