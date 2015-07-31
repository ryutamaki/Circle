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

#include "ColorConstants.h"

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

    this->setSwallowsTouches(true);

    return true;
}

#pragma mark Accessors

void GameResultLayer::setScore(int score)
{
    ui::TextBMFont* scoreCountLabel = this->resultLayout->getChildByName<ui::TextBMFont*>("ScoreCountLabel");
    scoreCountLabel->setString(std::to_string(score));
}

void GameResultLayer::setHighScore(int highScore, bool isNewRecord)
{
    ui::TextBMFont* highScoreCountLabel = this->resultLayout->getChildByName<ui::TextBMFont*>("HighScoreCountLabel");
    highScoreCountLabel->setString(std::to_string(highScore));

    if (isNewRecord) {
        highScoreCountLabel->setColor(Color3B(CIRCLE_DARK_BLUE));
    }
}

void GameResultLayer::setCoinCount(int coinCount)
{
    ui::TextBMFont* coinCountLabel = this->resultLayout->getChildByName<ui::TextBMFont*>("CoinCountLabel");
    coinCountLabel->setString(std::to_string(coinCount));
}

#pragma mark - Private methods

#pragma mark View lifecycle

void GameResultLayer::onEnter()
{
    Layer::onEnter();

    this->resultLayout = this->getChildByName<ui::Layout*>("ResultLayout");

    ui::Button* quitButton = this->resultLayout->getChildByName<ui::Button*>("QuitButton");
    quitButton->addTouchEventListener([](Ref* pSender, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            GameSceneManager::getInstance()->exitGameScene();
        }
    });

    ui::Button* retryButton = this->resultLayout->getChildByName<ui::Button*>("RetryButton");
    retryButton->addTouchEventListener([](Ref* pSender, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            // TODO: もう一度始まるようにする
            GameSceneManager::getInstance()->exitGameScene();
        }
    });
}
