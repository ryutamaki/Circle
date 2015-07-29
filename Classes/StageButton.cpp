//
// StageButton.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/26.
//
//

#include "StageButton.h"

#include "CocosGUI.h"

#include "EntityFactory.h"
#include "Entity.h"

#include "UserDataManager.h"

#pragma mark - Public methods

#pragma mark Initializer

bool StageButton::init()
{
    if (! Node::init()) {
        return false;
    }

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("StageButton.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->timeline->retain();

    return true;
}

#pragma mark Accessor

void StageButton::setEntityType(EntityType entityType)
{
    this->entityType = entityType;
}

EntityType StageButton::getEntityType()
{
    return this->entityType;
}

#pragma mark - Private methods

#pragma mark View lifecycle

void StageButton::onEnter()
{
    Node::onEnter();

    ui::Button* buttonBase = dynamic_cast<ui::Button*>(this->getChildByName("StageButtonBase"));
    this->setContentSize(buttonBase->getContentSize());
    this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);

    if (this->entityType != EntityType::NONE) {
        this->attachEntity(entityType);
        this->attachHighScoreLabel();
    }
}

void StageButton::attachEntity(EntityType eEntityType)
{
    Entity* entity = EntityFactory::createEntityWithEntityType(eEntityType);

    if (entity != nullptr) {
        entity->setNormalizedPosition(Vec2(0.5f, 0.6f));
        this->addChild(entity);
    } else {
        // TODO: no object
    }
}

void StageButton::attachHighScoreLabel()
{
    int highScore = UserDataManager::getInstance()->getHighScoreByEntityType(this->getEntityType());

    std::string highScoreString = "HIGHSCORE: " + std::to_string(highScore);
    Label* highScoreLabel = Label::createWithBMFont("Fonts/Menlo36.fnt", highScoreString);
    highScoreLabel->setNormalizedPosition(Vec2(0.5f, 0.2f));
    this->addChild(highScoreLabel);
}
