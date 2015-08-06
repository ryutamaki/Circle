//
// GamePauseLayer.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/31.
//
//

#include "GamePauseLayer.h"
#include "CocosGUI.h"

#include "GameSceneManager.h"

#pragma mark - Public methods

bool GamePauseLayer::init()
{
    if (! Layer::init()) {
        return false;
    }

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("GamePauseLayer.csb");
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

void GamePauseLayer::show(Node* parent)
{
    parent->addChild(this, Z_ORDER_FOR_MODAL);
    this->timeline->play("Show", false);
}

void GamePauseLayer::hide(std::function<void()> lastFrameCallback)
{
    this->timeline->play("Hide", false);
    this->timeline->setLastFrameCallFunc(lastFrameCallback);
}

#pragma mark - Private methods

#pragma mark View lifecycle

void GamePauseLayer::onEnter()
{
    Layer::onEnter();

    this->runAction(this->timeline);

    Sprite* overlay = this->getChildByName<Sprite*>("Overlay");
    this->setContentSize(overlay->getContentSize());

    this->pauseLayout = this->getChildByName<ui::Layout*>("PauseLayout");

    ui::Button* quitButton = this->pauseLayout->getChildByName<ui::Button*>("QuitButton");
    quitButton->addTouchEventListener([this](Ref* pSender, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            GameSceneManager::getInstance()->exitGameScene();
        }
    });

    ui::Button* resumeButton = this->pauseLayout->getChildByName<ui::Button*>("ResumeButton");
    resumeButton->addTouchEventListener([this](Ref* pSender, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            this->hide([this]() {
                GameSceneManager::getInstance()->resumeGameScene();
                this->removeFromParent();
            });
        }
    });
}
