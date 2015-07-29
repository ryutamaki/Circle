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

void GameResultLayer::setScore(int score)
{
    ui::TextBMFont* scoreLabel = this->getChildByName<ui::TextBMFont*>("ScoreLabel");
    scoreLabel->setString(scoreLabel->getString() + std::to_string(score));
}

void GameResultLayer::setHighScore(int highScore)
{
    ui::TextBMFont* highScoreLabel = this->getChildByName<ui::TextBMFont*>("HighScoreLabel");
    highScoreLabel->setString(highScoreLabel->getString() + std::to_string(highScore));
}

#pragma mark - Private methods

#pragma mark View lifecycle

void GameResultLayer::onEnter()
{
    Layer::onEnter();

    ui::Button* backButton = this->getChildByName<ui::Button*>("BackButton");
    backButton->addTouchEventListener(CC_CALLBACK_2(GameResultLayer::backToMenu, this));
}

#pragma mark Callbacks

void GameResultLayer::backToMenu(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        GameSceneManager::getInstance()->exitGameScene();
    }
}
