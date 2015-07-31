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

void Circle::setupAttackMap()
{
    this->attackMap = {
        {"Attack",		 {5,  Rect(0.0f, -20.0f, 160.0f, 80.0f)}},
        {"AttackNeedle", {10, Rect(0.0f, -20.0f, 160.0f, 80.0f)}},
    };
}

void Circle::setEntityParamerterByLevel(EntityLevelParameter levelParameter)
{
    this->entityParameter = {
        this->entityLevelParameter.levelHp * 10,
        this->entityLevelParameter.levelAttack * 1,
        this->entityLevelParameter.levelSpeed * 100.0f,
    };
}
