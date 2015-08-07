//
// EntityStateMachine.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/16.
//
//

#include "EntityStateMachine.h"
#include "Entity.h"

#pragma mark - Public methods

#pragma mark Initializers

EntityStateMachine::EntityStateMachine()
    : direction(0)
    , moveState(EntityMoveState::NONE)
    , attackState(EntityAttackState::NONE)
    , globalState(EntityGlobalState::READY)
{
}

EntityStateMachine::~EntityStateMachine()
{
}

#pragma mark Accessor

const EntityMoveState EntityStateMachine::getMoveState()
{
    return this->moveState;
}

void EntityStateMachine::setMoveState(const EntityMoveState moveState)
{
    this->moveState = moveState;
}

const EntityDirection EntityStateMachine::getDirection()
{
    return this->direction;
}

void EntityStateMachine::setDirection(const EntityDirection direction)
{
    this->direction = direction;
}

const EntityAttackState EntityStateMachine::getAttackState()
{
    return this->attackState;
}

void EntityStateMachine::setAttackState(const EntityAttackState attackState)
{
    this->attackState = attackState;
}

const EntityGlobalState EntityStateMachine::getGlobalState()
{
    return this->globalState;
}

void EntityStateMachine::setGlobalState(const EntityGlobalState globalState)
{
    this->globalState = globalState;
}

void EntityStateMachine::setDelegate(EntityStateMachineDelegate* delegate)
{
    this->delegate = delegate;
}

#pragma mark State functions

#pragma mark Move state

void EntityStateMachine::move(const EntityDirection direction)
{
    this->delegate->willStateChange(this->moveState, this->direction, this->attackState);

    if (this->attackState != EntityAttackState::NONE &&
        this->attackState != EntityAttackState::CHARGING) {
        return;
    }

    if (this->moveState == EntityMoveState::KNOCKBACK) {
        return;
    }

    this->setDirection(direction);
    this->setMoveState(EntityMoveState::MOVING);

    this->delegate->didStateChanged(this->moveState, this->direction, this->attackState);
}

void EntityStateMachine::stop()
{
    this->delegate->willStateChange(this->moveState, this->direction, this->attackState);

    if (! this->isMoving()) {
        return;
    }

    if (this->moveState == EntityMoveState::KNOCKBACK) {
        return;
    }

    this->setMoveState(EntityMoveState::NONE);

    this->delegate->didStateChanged(this->moveState, this->direction, this->attackState);
}

void EntityStateMachine::startKnockback()
{
    this->delegate->willStateChange(this->moveState, this->direction, this->attackState);

    this->setMoveState(EntityMoveState::KNOCKBACK);

    this->delegate->didStateChanged(this->moveState, this->direction, this->attackState);
}

void EntityStateMachine::stopKnockback()
{
    this->delegate->willStateChange(this->moveState, this->direction, this->attackState);

    if (this->moveState != EntityMoveState::KNOCKBACK) {
        return;
    }

    this->setMoveState(EntityMoveState::NONE);

    this->delegate->didStateChanged(this->moveState, this->direction, this->attackState);
}

#pragma mark Attack state

void EntityStateMachine::startCharging()
{
    this->delegate->willStateChange(this->moveState, this->direction, this->attackState);

    if (this->attackState != EntityAttackState::NONE) {
        return;
    }

    this->setAttackState(EntityAttackState::CHARGING);

    this->delegate->didStateChanged(this->moveState, this->direction, this->attackState);
}

void EntityStateMachine::readyToAttack()
{
    this->delegate->willStateChange(this->moveState, this->direction, this->attackState);

    if (this->attackState != EntityAttackState::NONE &&
        this->attackState != EntityAttackState::CHARGING) {
        return;
    }

    this->stop();
    this->setAttackState(EntityAttackState::READY);

    this->delegate->didStateChanged(this->moveState, this->direction, this->attackState);
}

void EntityStateMachine::startToAttack()
{
    this->delegate->willStateChange(this->moveState, this->direction, this->attackState);

    if (this->attackState != EntityAttackState::READY) {
        return;
    }

    this->setAttackState(EntityAttackState::ATTACKING);

    this->delegate->didStateChanged(this->moveState, this->direction, this->attackState);
}

void EntityStateMachine::hitAttack()
{
    this->delegate->willStateChange(this->moveState, this->direction, this->attackState);

    if (this->attackState != EntityAttackState::ATTACKING) {
        return;
    }

    this->setAttackState(EntityAttackState::HIT);

    this->delegate->didStateChanged(this->moveState, this->direction, this->attackState);
}

void EntityStateMachine::coolDownAttaking()
{
    this->delegate->willStateChange(this->moveState, this->direction, this->attackState);

    if (this->attackState != EntityAttackState::ATTACKING &&
        this->attackState != EntityAttackState::HIT) {
        return;
    }

    this->setAttackState(EntityAttackState::COOL_DOWN);

    this->delegate->didStateChanged(this->moveState, this->direction, this->attackState);
}

void EntityStateMachine::finishAttaking()
{
    this->delegate->willStateChange(this->moveState, this->direction, this->attackState);

    if (this->attackState != EntityAttackState::COOL_DOWN) {
        return;
    }

    this->setAttackState(EntityAttackState::NONE);

    this->delegate->didStateChanged(this->moveState, this->direction, this->attackState);
}

void EntityStateMachine::cancelAttack()
{
    this->delegate->willStateChange(this->moveState, this->direction, this->attackState);

    this->setAttackState(EntityAttackState::NONE);

    this->delegate->didStateChanged(this->moveState, this->direction, this->attackState);
}

#pragma mark Global state

void EntityStateMachine::ready()
{
    this->delegate->willStateChange(this->moveState, this->direction, this->attackState);

    this->setGlobalState(EntityGlobalState::READY);

    this->delegate->didStateChanged(this->moveState, this->direction, this->attackState);
}

void EntityStateMachine::alive()
{
    this->delegate->willStateChange(this->moveState, this->direction, this->attackState);

    if (this->globalState != EntityGlobalState::READY) {
        return;
    }

    this->setGlobalState(EntityGlobalState::ALIVE);

    this->delegate->didStateChanged(this->moveState, this->direction, this->attackState);
}

void EntityStateMachine::dead()
{
    this->delegate->willStateChange(this->moveState, this->direction, this->attackState);

    this->setGlobalState(EntityGlobalState::DEAD);

    this->delegate->didStateChanged(this->moveState, this->direction, this->attackState);
}

#pragma mark checker

bool EntityStateMachine::canAttack()
{
    if (this->attackState == EntityAttackState::NONE ||
        this->attackState == EntityAttackState::CHARGING) {
        return true;
    }
    return false;
}

bool EntityStateMachine::canCharge()
{
    if (this->attackState == EntityAttackState::NONE) {
        return true;
    }
    return false;
}

bool EntityStateMachine::isDead()
{
    return this->globalState == EntityGlobalState::DEAD;
}

bool EntityStateMachine::isMoving()
{
    return this->moveState == EntityMoveState::MOVING;
}

bool EntityStateMachine::isAttacking()
{
    if (this->attackState == EntityAttackState::NONE) {
        return false;
    } else if (this->isCharging()) {
        return false;
    } else {
        return true;
    }
    return true;
}

bool EntityStateMachine::isCharging()
{
    return this->attackState == EntityAttackState::CHARGING;
}
