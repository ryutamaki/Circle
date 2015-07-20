//
//  EntityStateMachine.cpp
//  DotWar
//
//  Created by ryutamaki on 2015/07/16.
//
//

#include "EntityStateMachine.h"
#include "Entity.h"

#include "JSONPacker.h"
#include "SceneManager.h"

#pragma mark - Public methods

#pragma mark Initializers

EntityStateMachine::EntityStateMachine()
:moveState(EntityMoveState::NONE)
,attackState(EntityAttackState::NONE)
{

}

EntityStateMachine::~EntityStateMachine()
{

}

#pragma mark Getter

const EntityMoveState EntityStateMachine::getMoveState()
{
    return this->moveState;
}

const EntityAttackState EntityStateMachine::getAttackState()
{
    return this->attackState;
}

#pragma mark State functions

void EntityStateMachine::stopMoving()
{
    this->setMoveState(EntityMoveState::NONE);

    this->sendCurrentEntityState();
}

void EntityStateMachine::startMoving(const EntityMoveState movingState)
{
    if (this->attackState != EntityAttackState::NONE)
        return;

    this->setMoveState(movingState);
    
    this->sendCurrentEntityState();
}

void EntityStateMachine::readyToAttack()
{
    if (this->attackState != EntityAttackState::NONE)
        return;

    this->setMoveState(EntityMoveState::NONE);
    this->setAttackState(EntityAttackState::READY);

    this->sendCurrentEntityState();
}

void EntityStateMachine::startToAttack()
{
    if (this->attackState != EntityAttackState::READY)
        return;

    this->setAttackState(EntityAttackState::ATTACKING);
}

void EntityStateMachine::hitAttack()
{
    if (this->attackState != EntityAttackState::ATTACKING)
        return;

    this->setAttackState(EntityAttackState::HIT);
}

void EntityStateMachine::coolDownAttaking()
{
    if (this->attackState != EntityAttackState::ATTACKING &&
        this->attackState != EntityAttackState::HIT)
        return;

    this->setAttackState(EntityAttackState::COOL_DOWN);
}

void EntityStateMachine::finishAttaking()
{
    if (this->attackState != EntityAttackState::COOL_DOWN)
        return;

    this->setAttackState(EntityAttackState::NONE);
}

bool EntityStateMachine::canAttack()
{
    if (this->attackState == EntityAttackState::NONE)
    {
        return true;
    }
    return false;
}

#pragma mark - Private methods

#pragma mark Setter

void EntityStateMachine::setMoveState(const EntityMoveState moveState)
{
    this->moveState = moveState;
}

void EntityStateMachine::setAttackState(const EntityAttackState attackState)
{
    this->attackState = attackState;
}

#pragma mark Networking

void EntityStateMachine::sendCurrentEntityState()
{
    JSONPacker::EntityState entityState;
    entityState.moveState = this->moveState;
    entityState.attackState = this->attackState;

    std::string json = JSONPacker::packEntityState(entityState);
    SceneManager::getInstance()->sendData(json.c_str(), json.length());
}