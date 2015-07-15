//
//  MenuScene.cpp
//  DotWar
//
//  Created by ryutamaki on 2015/07/15.
//
//

#include "MenuScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "HelloWorldScene.h"

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
    if ( !Layer::init() )
    {
        return false;
    }

    auto rootNode = CSLoader::createNode("MenuScene.csb");
    ui::Button* singlePlayerButton = dynamic_cast<ui::Button*>(rootNode->getChildByName("SinglePlayerButton"));
    ui::Button* multiplayerButton = dynamic_cast<ui::Button*>(rootNode->getChildByName("MultiplayerButton"));

    singlePlayerButton->addTouchEventListener(CC_CALLBACK_2(MenuScene::singlePlayerButtonPushed, this));
    multiplayerButton->addTouchEventListener(CC_CALLBACK_2(MenuScene::multiplayerButtonPushed, this));

    this->addChild(rootNode);

    return true;
}


#pragma mark - Private methods

#pragma mark Callback

void MenuScene::singlePlayerButtonPushed(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED)
    {
        Scene* gameScenen = HelloWorld::createScene();
        Director::getInstance()->pushScene(gameScenen);
    }
}

void MenuScene::multiplayerButtonPushed(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED)
    {
        Scene* gameScenen = HelloWorld::createScene();
        Director::getInstance()->pushScene(gameScenen);
    }
}
