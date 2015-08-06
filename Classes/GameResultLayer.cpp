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

    // Prevent propagation into the layers below
    EventListenerTouchOneByOne* eventListener = EventListenerTouchOneByOne::create();
    eventListener->setSwallowTouches(true);
    eventListener->onTouchBegan = [](Touch* touch, Event* event) -> bool {
            return true;
        };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, this);

    return true;
}

void GameResultLayer::show(Node* parent)
{
    parent->addChild(this, Z_ORDER_FOR_MODAL);
    this->timeline->play("Show", false);
}

void GameResultLayer::hide(std::function<void()> lastFrameCallback)
{
    this->timeline->play("Hide", false);
    this->timeline->setLastFrameCallFunc(lastFrameCallback);
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

    this->runAction(this->timeline);

    Sprite* overlay = this->getChildByName<Sprite*>("Overlay");
    this->setContentSize(overlay->getContentSize());

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
            GameSceneManager::getInstance()->restartGameScene();
        }
    });
}
