//
//  EnemyAI.cpp
//  DotWar
//
//  Created by ryutamaki on 2015/07/20.
//
//

#include "EnemyAI.h"

USING_NS_CC;

#pragma mark - Public methods

EnemyAI::EnemyAI(Entity* entity, cocos2d::Vector<Entity*> opponents)
{
    this->entity = entity;
    this->opponents = opponents;
}

EnemyAI::~EnemyAI()
{
    this->entity = nullptr;
    this->target = nullptr;
}

#pragma mark Game logic

void EnemyAI::start()
{
    this->schedule(CC_SCHEDULE_SELECTOR(EnemyAI::running), 1.0f);
}

void EnemyAI::stop()
{
    this->unschedule(CC_SCHEDULE_SELECTOR(EnemyAI::running));
}

#pragma mark - Private methods

void EnemyAI::running(float dt)
{
    int random = CCRANDOM_0_1() * 8;
    this->move((EntityMoveState)random, 3.0f);
};

void EnemyAI::move(EntityMoveState moveState, float dulation)
{
    this->entity->runAction(Sequence::create(
                                             CallFunc::create([this, moveState](){this->entity->stateMachine->startMoving(moveState);}),
                                             DelayTime::create(dulation),
                                             CallFunc::create([this](){this->entity->stateMachine->stopMoving();}),
                                             NULL
                                             ));
}

void EnemyAI::attack(std::string attackName)
{
    this->entity->stateMachine->startToAttack();
}