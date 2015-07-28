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

    this->initialHp = 20;
    this->setHp(this->initialHp);
    this->velocityFactor = 300.0f;

    return true;
}

#pragma mark Game logic

#pragma mark - Protected methods

void Circle::setupAttackMap()
{
    this->attackMap = {
        {"Attack", {10, Rect(0.0f, -20.0f, 160.0f, 80.0f)}},
    };
}

#pragma mark - Prvate methods

#pragma mark View lifecycle

void Circle::onEnter()
{
    Entity::onEnter();
}
