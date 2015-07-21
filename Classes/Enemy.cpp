//
//  Enemy.cpp
//  DotWar
//
//  Created by ryutamaki on 2015/07/15.
//
//

#include "Enemy.h"

using namespace cocostudio::timeline;

#pragma mark - Public methods

#pragma mark Initializer

bool Enemy::init() {
    if (!Entity::init()) {
        return false;
    }

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("Enemy.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->timeline->retain();

    this->initialHp = 300;
    this->hp = this->initialHp;
    this->velocityFactor = 200.0f;

    return true;
}

#pragma mark Game logic

#pragma mark - Private methods

#pragma mark View lifecycle

void Enemy::onEnter()
{
    Entity::onEnter();
}
