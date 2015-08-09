//
// TutorialLayer.cpp
// DotWar
//
// Created by ryutamaki on 2015/08/05.
//
//

#include "TutorialLayer.h"
#include "CocosGUI.h"

#include "UserDataManager.h"

#pragma mark - Public methods

bool TutorialLayer::init()
{
    if (! Layer::init()) {
        return false;
    }

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("TutorialLayer.csb");
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

#pragma mark Control methods

void TutorialLayer::show(TutorialType tutorialType)
{
    this->timeline->play("Show", false);

    std::string tutorialNodeName = TUTOTIAL_NODE_NAME.at(tutorialType);
    Sprite* tutorialNode = this->tutorialLayout->getChildByName<Sprite*>(tutorialNodeName);
    tutorialNode->setVisible(true);

    bool isShown = true;
    UserDataManager::getInstance()->setIsShownTutorial(tutorialType, isShown);
}

void TutorialLayer::hide()
{
    this->timeline->play("Hide", false);
    this->timeline->setLastFrameCallFunc([this]() {
        this->removeFromParent();
    });
}

#pragma mark - Private methods

#pragma mark View lifecycle

void TutorialLayer::onEnter()
{
    Layer::onEnter();

    this->runAction(this->timeline);

    // Set overlay as a close button
    ui::Button* overlay = this->getChildByName<ui::Button*>("Overlay");
    overlay->addTouchEventListener([this, overlay](Ref* pSender, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            this->hide();
            overlay->setTouchEnabled(false);
        }
    });
    this->setContentSize(overlay->getContentSize());

    this->tutorialLayout = this->getChildByName<ui::Layout*>("TutorialLayout");
}
