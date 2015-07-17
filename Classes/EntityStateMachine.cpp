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

EntityMoveState EntityStateMachine::getMoveState()
{
    return this->moveState;
}

EntityAttackState EntityStateMachine::getAttackState()
{
    return this->attackState;
}

#pragma mark State functions

bool EntityStateMachine::stopMoving()
{
    this->setMoveState(EntityMoveState::NONE);

    this->sendCurrentEntityState();

    return true;
}

bool EntityStateMachine::startMoving(EntityMoveState movingState)
{
    if (this->attackState != EntityAttackState::NONE)
        return false;

    this->setMoveState(movingState);
    
    this->sendCurrentEntityState();

    return true;
}

bool EntityStateMachine::startAttaking()
{
    if (this->attackState != EntityAttackState::NONE)
        return false;

    this->setMoveState(EntityMoveState::NONE);
    this->setAttackState(EntityAttackState::ATTAKING);

    this->sendCurrentEntityState();

    return true;
}

bool EntityStateMachine::coolDownAttaking()
{
    if (this->attackState != EntityAttackState::ATTAKING)
        return false;

    this->setMoveState(EntityMoveState::NONE);
    this->setAttackState(EntityAttackState::COOL_DOWN);

    this->sendCurrentEntityState();

    return true;
}

bool EntityStateMachine::finishAttaking()
{
    if (this->attackState != EntityAttackState::COOL_DOWN)
        return false;

    this->setMoveState(EntityMoveState::NONE);
    this->setAttackState(EntityAttackState::NONE);

    this->sendCurrentEntityState();

    return true;
}

#pragma mark - Private methods

#pragma mark Setter

void EntityStateMachine::setMoveState(EntityMoveState moveState)
{
    this->moveState = moveState;
}

void EntityStateMachine::setAttackState(EntityAttackState attackState)
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