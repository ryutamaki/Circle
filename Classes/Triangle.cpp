//
// Triangle.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/15.
//
//

#include "Triangle.h"

using namespace cocostudio::timeline;

#pragma mark - Public methods

#pragma mark Initializer

bool Triangle::init()
{
    if (! Entity::init()) {
        return false;
    }

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("Triangle.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->timeline->retain();

    return true;
}

#pragma mark Game logic

#pragma mark - Protected methods

void Triangle::setupAttackMap()
{
    this->attackMap = {
        {"Attack", {10, Rect(0.0f, -20.0f, 160.0f, 80.0f)}},
    };
}

void Triangle::setupEntityParamerterByLevel(EntityLevelParameter levelParameter)
{
    this->entityParameter = {
        this->entityLevelParameter.hp * 15,
        this->entityLevelParameter.attack * 1,
        this->entityLevelParameter.speed * 15,
    };
}
