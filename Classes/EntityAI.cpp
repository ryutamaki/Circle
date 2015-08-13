//
// EntityAI.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/20.
//
//

#include "EntityAI.h"

#include "EntityHelper.h"

USING_NS_CC;

#pragma mark - Public methods

EntityAI* EntityAI::create(Entity* entity, Vector<Entity*> opponents)
{
    EntityAI* pRet = new(std::nothrow)EntityAI(entity, opponents);

    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    } else {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

EntityAI::EntityAI(Entity* entity, cocos2d::Vector<Entity*> opponents)
{
    this->entity = entity;
    this->opponents = opponents;
    this->isPreActionAttack = false;
    this->isPreActionCharge = false;
    this->isMoving = false;

    this->decideTarget();
}

EntityAI::~EntityAI()
{
    this->entity = nullptr;
    this->target = nullptr;
}

#pragma mark Game logic

void EntityAI::start()
{
    this->schedule(CC_SCHEDULE_SELECTOR(EntityAI::running));
}

void EntityAI::stop()
{
    this->unschedule(CC_SCHEDULE_SELECTOR(EntityAI::running));
}

#pragma mark - Public methods

void EntityAI::running(float dt)
{

}

#pragma mark - Private methods

void EntityAI::stay(float dulation)
{
    this->entity->runAction(
        Sequence::create(
            CallFunc::create([this]() {this->isMoving = true; this->entity->stateMachine->stop(); }),
            DelayTime::create(dulation),
            CallFunc::create([this]() {this->isMoving = false; }),
            NULL
        )
    );
}

void EntityAI::move(EntityDirection direction, float dulation)
{
    this->entity->runAction(
        Sequence::create(
            CallFunc::create([this, direction]() {this->isMoving = true; this->entity->stateMachine->move(direction); }),
            DelayTime::create(dulation),
            CallFunc::create([this]() {this->entity->stateMachine->stop(); this->isMoving = false; }),
            NULL
        )
    );
}

void EntityAI::attack(std::string attackName)
{
    this->entity->attack(attackName);
}

void EntityAI::decideTarget()
{
    if (this->opponents.size() == 0) {
        return;
    }
    int index = std::rand() % opponents.size();
    this->target = opponents.at(index);
}
