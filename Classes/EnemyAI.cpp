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
    this->isPreActionAttack = false;
    this->isPreActionCharge = false;

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
    this->schedule(CC_SCHEDULE_SELECTOR(EnemyAI::running));
}

void EnemyAI::stop()
{
    this->unschedule(CC_SCHEDULE_SELECTOR(EnemyAI::running));
}

#pragma mark - Private methods

void EnemyAI::running(float dt)
{
    if (this->entity->stateMachine->isMoving()) {
        return;
    }

    if (this->entity->stateMachine->isAttacking()) {
        return;
    }

    if (this->isPreActionAttack) {
        this->stay(2.0f);
        this->isPreActionAttack = false;
        return;
    }

    if (this->isPreActionCharge) {
        for (std::string attackName : this->entity->getAttackNameList()) {
            EntityAttackParams attackParams = this->entity->getAttackParamsByName(attackName);

            if (attackParams.attackType == EntityAttackType::CHARGE) {
                this->attack(attackName);
                this->isPreActionAttack = true;
                this->isPreActionCharge = false;
                return;
            }
        }
    }

    float rand = CCRANDOM_0_1();

    if (rand < 0.05f) {
        this->entity->startCharging();
        this->stay(2.0f);
        this->isPreActionCharge = true;
        return;
    } else if (rand < 0.15f) {
        this->stay(1.0f);
        return;
    }

    Vec2 targetPosition = this->target->getPosition();
    Vec2 myPosition = this->entity->getPosition();
    float distance = targetPosition.distance(myPosition);

    // TODO: magic number
    if (distance < 120.0f) {
        std::vector<std::string> attackNameList = this->entity->getAttackNameList();
        int index = std::rand() % attackNameList.size();
        std::string attackName = attackNameList.at(index);
        EntityAttackParams attackParams = this->entity->getAttackParamsByName(attackName);

        if (attackParams.attackType == EntityAttackType::CHARGE && ! this->entity->stateMachine->isCharging()) {
            // do nothing
            return;
        }
        this->attack(attackName);
        this->isPreActionAttack = true;
    } else {
        EntityMoveState moveState = EntityHelper::moveStateFromStartPositionAndEndPosition(myPosition, targetPosition);

        this->move(moveState, 0.3f);
    }
}

void EnemyAI::stay(float dulation)
{
    this->move(EntityMoveState::NONE, dulation);
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
