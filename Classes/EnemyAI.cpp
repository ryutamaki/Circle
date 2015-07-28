//
// EnemyAI.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/20.
//
//

#include "EnemyAI.h"

#include "EntityHelper.h"

USING_NS_CC;

#pragma mark - Public methods

EnemyAI::EnemyAI(Entity* entity, cocos2d::Vector<Entity*> opponents)
{
    this->entity = entity;
    this->opponents = opponents;

    this->decideTarget();
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
    Vec2 targetPosition = this->target->getPosition();
    Vec2 myPosition = this->entity->getPosition();
    float distance = targetPosition.distance(myPosition);

    EntityMoveState moveState = EntityHelper::moveStateFromStartPositionAndEndPosition(myPosition, targetPosition);

    std::vector<std::string> attackNameList = this->entity->getAttackNameList();
    int index = std::rand() % attackNameList.size();

    // TODO: magic number
    if (distance < 120.0f) {
        this->move(moveState, 0.01f);
        this->attack(attackNameList.at(index));
    } else {
        this->move(moveState, 0.5f);
    }
}

void EnemyAI::move(EntityMoveState moveState, float dulation)
{
    this->entity->runAction(
        Sequence::create(
            CallFunc::create([this, moveState]() {this->entity->stateMachine->move(moveState); }),
            DelayTime::create(dulation),
            CallFunc::create([this]() {this->entity->stateMachine->move(EntityMoveState::NONE); }),
            NULL
        )
    );
}

void EnemyAI::attack(std::string attackName)
{
    this->entity->attack(attackName);
}

void EnemyAI::decideTarget()
{
    this->target = opponents.at(0);
}
