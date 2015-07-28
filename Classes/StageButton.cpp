//
// StageButton.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/26.
//
//

#include "StageButton.h"

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

    this->attachEntity(entityType);
    this->attachHighScoreLabel();
}

EntityType StageButton::getEntityType()
{
    return this->entityType;
}

#pragma mark - Private methods

void StageButton::attachEntity(EntityType eEntityType)
{
    Entity* entity = EntityFactory::createEntityWithEntityType(eEntityType);

    if (entity != nullptr) {
        this->addChild(entity);
    } else {
        // TODO: no object
    }
}

void StageButton::attachHighScoreLabel()
{
    int highScore = UserDataManager::getInstance()->getHighScoreByEntityType(this->getEntityType());

    std::string highScoreString = "HIGHSCORE: " + std::to_string(highScore);
    Label* highScoreLabel = Label::createWithBMFont("Fonts/myFont.fnt", highScoreString);
    this->addChild(highScoreLabel);
}
