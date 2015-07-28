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

    this->initialHp = 300;
    this->setHp(this->initialHp);
    this->velocityFactor = 200.0f;

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

#pragma mark - Private methods

#pragma mark View lifecycle

void Triangle::onEnter()
{
    Entity::onEnter();
}
