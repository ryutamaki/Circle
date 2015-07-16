//
//  Enemy.cpp
//  DotWar
//
//  Created by ryutamaki on 2015/07/15.
//
//

#include "Enemy.h"

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

    return true;
}

#pragma mark Game logic

void Enemy::recieveDamage(int damage, Vec2 knockback)
{
    Entity::receiveDamage(damage, knockback);
}


#pragma mark - Private methods

#pragma mark View lifecycle

void Enemy::onEnter()
{
    Entity::onEnter();

}