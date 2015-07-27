//
// GameResultLayer.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/27.
//
//

#include "GameResultLayer.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "GameSceneManager.h"

USING_NS_CC;

#pragma mark - Public methods

#pragma mark Initializer

bool GameResultLayer::init()
{
    if (! Layer::init()) {
        return false;
    }

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("GameResultLayer.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->timeline->retain();

    return true;
}

#pragma mark Accessors

void GameResultLayer::setIsWin(bool isWin)
{
    this->isWin = isWin;

    ui::TextBMFont* resultLabel = dynamic_cast<ui::TextBMFont*>(this->getChildByName("ResultLabel"));

    if (isWin) {
        resultLabel->setString("YOU WIN");
    } else {
        resultLabel->setString("YOU LOSE");
    }
}

#pragma mark - Private methods

#pragma mark View lifecycle

void GameResultLayer::onEnter()
{
    Layer::onEnter();

    ui::Button* backButton = dynamic_cast<ui::Button*>(this->getChildByName("BackButton"));
    backButton->addTouchEventListener(CC_CALLBACK_2(GameResultLayer::backToMenu, this));
}

#pragma mark Callbacks

void GameResultLayer::backToMenu(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        GameSceneManager::getInstance()->exitGameScene();
    }
}
