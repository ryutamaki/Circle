//
// StageComponent.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/26.
//
//

#include "StageComponent.h"
#include "CocosGUI.h"

#include "EntityFactory.h"
#include "Entity.h"

#include "UserDataManager.h"

#pragma mark - Public methods

#pragma mark Initializer

bool StageComponent::init()
{
    if (! Node::init()) {
        return false;
    }

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("StageComponent.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->timeline->retain();

    return true;
}

#pragma mark Accessor

void StageComponent::setEntityType(EntityType entityType)
{
    this->entityType = entityType;
}

EntityType StageComponent::getEntityType() const
{
    return this->entityType;
}

#pragma mark - Private methods

#pragma mark View lifecycle

void StageComponent::onEnter()
{
    Node::onEnter();

    this->componentFrame = this->getChildByName<ui::Layout*>("StageComponent");
    this->componentFrame->setSwallowTouches(false);
    this->componentFrame->setPropagateTouchEvents(true);
    this->setContentSize(this->componentFrame->getContentSize());

    if (this->entityType != EntityType::NONE) {
        this->attachEntity(entityType);
        this->attachHighScoreLabel();
    }
}

void StageComponent::attachEntity(EntityType eEntityType)
{
    Entity* entity = EntityFactory::createEntity(eEntityType, ENTITY_INITIAL_LEVEL_PARAMETER.at(eEntityType), CIRCLE_LIGHT_RED);

    if (entity != nullptr) {
        entity->setNormalizedPosition(Vec2(0.5f, 0.6f));
        this->componentFrame->addChild(entity);
    } else {
        // TODO: no object
    }
}

void StageComponent::attachHighScoreLabel()
{
    int highScore = UserDataManager::getInstance()->getHighScoreByEntityType(this->getEntityType());

    std::string highScoreString = "BEST: " + std::to_string(highScore);
    Label* highScoreLabel = Label::createWithBMFont("Fonts/Menlo48.fnt", highScoreString);
    highScoreLabel->setNormalizedPosition(Vec2(0.5f, 0.2f));
    this->componentFrame->addChild(highScoreLabel);
}
