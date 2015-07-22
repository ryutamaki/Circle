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
    : moveState(EntityMoveState::NONE)
    , attackState(EntityAttackState::NONE)
{}

EntityStateMachine::~EntityStateMachine()
{}

#pragma mark Accessor

const EntityMoveState EntityStateMachine::getMoveState()
{
    return this->moveState;
}

void EntityStateMachine::setMoveState(const EntityMoveState moveState)
{
    this->moveState = moveState;
}

const EntityAttackState EntityStateMachine::getAttackState()
{
    return this->attackState;
}

void EntityStateMachine::setAttackState(const EntityAttackState attackState)
{
    this->attackState = attackState;
}

void EntityStateMachine::setDelegate(EntityStateMachineDelegate* delegate)
{
    this->delegate = delegate;
}

#pragma mark State functions

void EntityStateMachine::move(const EntityMoveState movingState)
{
    this->delegate->willStateChange(this->moveState, this->attackState);

    if (this->attackState != EntityAttackState::NONE) {
        return;
    }

    this->setMoveState(movingState);

    this->delegate->didStateChanged(this->moveState, this->attackState);
}

void EntityStateMachine::readyToAttack()
{
    this->delegate->willStateChange(this->moveState, this->attackState);

    if (this->attackState != EntityAttackState::NONE) {
        return;
    }

    this->setMoveState(EntityMoveState::NONE);
    this->setAttackState(EntityAttackState::READY);

    this->delegate->didStateChanged(this->moveState, this->attackState);
}

void EntityStateMachine::startToAttack()
{
    this->delegate->willStateChange(this->moveState, this->attackState);

    if (this->attackState != EntityAttackState::READY) {
        return;
    }

    this->setAttackState(EntityAttackState::ATTACKING);

    this->delegate->didStateChanged(this->moveState, this->attackState);
}

void EntityStateMachine::hitAttack()
{
    this->delegate->willStateChange(this->moveState, this->attackState);

    if (this->attackState != EntityAttackState::ATTACKING) {
        return;
    }

    this->setAttackState(EntityAttackState::HIT);

    this->delegate->didStateChanged(this->moveState, this->attackState);
}

void EntityStateMachine::coolDownAttaking()
{
    this->delegate->willStateChange(this->moveState, this->attackState);

    if (this->attackState != EntityAttackState::ATTACKING &&
        this->attackState != EntityAttackState::HIT) {
        return;
    }

    this->setAttackState(EntityAttackState::COOL_DOWN);

    this->delegate->didStateChanged(this->moveState, this->attackState);
}

void EntityStateMachine::finishAttaking()
{
    this->delegate->willStateChange(this->moveState, this->attackState);

    if (this->attackState != EntityAttackState::COOL_DOWN) {
        return;
    }

    this->setAttackState(EntityAttackState::NONE);

    this->delegate->didStateChanged(this->moveState, this->attackState);
}

bool EntityStateMachine::canAttack()
{
    if (this->attackState == EntityAttackState::NONE) {
        return true;
    }
    return false;
}
