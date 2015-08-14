//
// PowerUpButton.cpp
// Circle
//
// Created by ryutamaki on 2015/08/13.
//
//

#include "PowerUpButton.h"
#include "PowerUpScene.h"
#include "Entity.h"

#include "UserDataManager.h"

#pragma mark - Public methods

bool PowerUpButton::init()
{
    if (! Node::init()) {
        return false;
    }

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("PowerUpButton.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->timeline->retain();

    return true;
}

#pragma mark Setter

void PowerUpButton::setNotifierByEntity(Entity* entity)
{
    int countOfStatusUserCanLevelUp = 0;

    int currentCoinCount = UserDataManager::getInstance()->getCoinCount();
    int coinCountForRankUp = entity->getCoinCountToRankUp();
    int coinCountForHpLevelUp = entity->getCoinCountToHpLevelUp();
    int coinCountForAttackUp = entity->getCoinCountToAttackLevelUp();

    countOfStatusUserCanLevelUp += currentCoinCount >= coinCountForRankUp  ? 1 : 0;
    countOfStatusUserCanLevelUp += currentCoinCount >= coinCountForHpLevelUp ? 1 : 0;
    countOfStatusUserCanLevelUp += currentCoinCount >= coinCountForAttackUp ? 1 : 0;

    if (countOfStatusUserCanLevelUp > 0) {
        this->notifier->setVisible(true);
    } else {
        this->notifier->setVisible(false);
    }
}

#pragma mark - Private methods

#pragma mark View lifecycle

void PowerUpButton::onEnter()
{
    Node::onEnter();

    this->powerUpButton = this->getChildByName<ui::Button*>("PowerUpButton");
    this->powerUpButton->addTouchEventListener([this](Ref* pRef, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::BEGAN) {
            this->notifier->setPosition(this->notifier->getPosition() + Vec2(0.0f, -10.0f));
        } else if (eEventType == ui::Widget::TouchEventType::CANCELED) {
            this->notifier->setPosition(this->notifier->getPosition() + Vec2(0.0f, 10.0f));
        } else if (eEventType == ui::Widget::TouchEventType::ENDED) {
            PowerUpScene* powerUpScene = PowerUpScene::create();
            powerUpScene->setEntityType(EntityType::CIRCLE);
            Scene* scene = Scene::create();
            scene->addChild(powerUpScene);
            TransitionFade* transition = TransitionFade::create(SCENE_TRANSITION_DURATION, scene, SCENE_TRANSITION_COLOR);
            Director::getInstance()->pushScene(transition);
        }

        if (this->powerUpButton->isHighlighted()) {
            this->notifier->setPosition(Vec2(90.0f, 90.0f));
        } else {
            this->notifier->setPosition(Vec2(90.0f, 98.0f));
        }
    });

    this->notifier = this->powerUpButton->getChildByName<Sprite*>("Notifier");
}

void PowerUpButton::onExit()
{
    Node::onExit();
}
