//
//  Entity.cpp
//  DotWar
//
//  Created by ryutamaki on 2015/07/15.
//
//

#include "Entity.h"

USING_NS_CC;

#pragma mark - Initilalizer

bool Entity::init()
{
    if (!Node::init())
    {
        return false;
    }

    this->hp = 100;
    this->moveState = CharacterMoveState::NONE;
    this->velocity = Vec2(0.0f, 0.0f);

    return true;
}

#pragma mark Accessor

int Entity::getHp()
{
    return this->hp;
}

void Entity::setMoveState(CharacterMoveState moveState)
{
    this->moveState = moveState;
}

#pragma mark Game logic

void Entity::attack()
{
    // override point
}

void Entity::receiveDamage(int damage, Vec2 knockback)
{
    // override point
}

#pragma mark - Protected method

#pragma mark View lifecycle

void Entity::onEnter()
{
    Node::onEnter();
}

void Entity::onExit()
{
    Node::onExit();
}
