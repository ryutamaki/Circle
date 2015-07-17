//
//  Character.cpp
//  DotWar
//
//  Created by ryutamaki on 2015/07/15.
//
//

#include "Character.h"

#pragma mark - Public methods

#pragma mark Initializer

bool Character::init() {
    if (!Entity::init()) {
        return false;
    }

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("Character.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->timeline->retain();

    return true;
}

#pragma mark Accessor

void Character::setMoveStateByStartPositionAndCurrentPosition(cocos2d::Vec2 startPosition, cocos2d::Vec2 currentPosition)
{
    EntityMoveState moveState = this->moveStateFromStartPositionAndEndPosition(startPosition, currentPosition);
    if (moveState == this->stateMachine->getMoveState())
    {
        return;
    }
    this->stateMachine->startMoving(moveState);
}

#pragma mark Game logic

void Character::attack()
{
    Entity::attack();
    bool isStartAttaking = this->stateMachine->startAttaking();
    if (!isStartAttaking)
    {
        return;
    }

    this->stopAllActions();
    this->runAction(this->timeline);
    this->timeline->play("Attack", false);
    this->timeline->setLastFrameCallFunc([&](){
        this->stateMachine->coolDownAttaking();
        this->stateMachine->finishAttaking();
    });
}

void Character::receiveDamage(int damage, Vec2 knockback)
{
    Entity::receiveDamage(damage, knockback);
}

#pragma mark - Prvate methods

#pragma mark View lifecycle

void Character::onEnter()
{
    Entity::onEnter();

    this->scheduleUpdate();
}

#pragma mark Game logic

void Character::update(float dt)
{
    Node::update(dt);

    if (this->stateMachine->getMoveState() == EntityMoveState::NONE)
    {
        this->velocity.setZero();
        return;
    }

    Vec2 direction = this->directionFromMoveState(this->stateMachine->getMoveState());
    this->velocity = CHARACTER_SPEED * direction * dt;
}

