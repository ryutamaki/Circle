//
// Circle.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/15.
//
//

#include "Circle.h"

#pragma mark - Public methods

#pragma mark Initializer

bool Circle::init()
{
    if (! Entity::init()) {
        return false;
    }

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("Circle.csb");
    // retain the haracter animation timeline so it doesn't get deallocated
    this->timeline->retain();

    return true;
}

#pragma mark Game logic

#pragma mark - Protected methods

#pragma mark Override methods

void Circle::setupEntityParamerterByLevel(struct EntityParameterLevel parameterLevel)
{
    EntityParameter initialParameter = ENTITY_INITIAL_PARAMETER.at(EntityType::CIRCLE);
    EntityParameterMultipler parameterMultipler = ENTITY_PARAMETER_MULTIPLER_BY_RANK.at(parameterLevel.rank);

    this->entityParameter = {
        static_cast<int>(initialParameter.initialHp + parameterLevel.hp * parameterMultipler.hp * 5),
        static_cast<int>(initialParameter.attackFactor + parameterLevel.attack * parameterMultipler.attack * 1),
    };
}
