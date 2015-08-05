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
    this->isMoving = false;
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
    if (isMoving) {
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
        this->entity->getAttackNameListForAi();

        for (std::string attackName : this->entity->getAttackNameListForAi()) {
            AttackParams attackParams = this->entity->getAttackParamsForAiByName(attackName);

            if (attackParams.attackType == EntityAttackType::CHARGE) {
                this->attack(attackName);
                this->isPreActionAttack = true;
                this->isPreActionCharge = false;
                return;
            }
        }
    }

    float rand = CCRANDOM_0_1();
    log("%f", rand);

    if (rand < 0.05f) {
        this->entity->startCharging();
        this->stay(2.0f);
        this->isPreActionCharge = true;
        return;
    } else if (rand < 0.15f) {
        log("STAY");
        this->stay(1.0f);
        return;
    }

    Vec2 targetPosition = this->target->getPosition();
    Vec2 myPosition = this->entity->getPosition();
    float distance = targetPosition.distance(myPosition);

    // TODO: magic number
    if (distance < 120.0f) {
        std::vector<std::string> attackNameList = this->entity->getAttackNameListForAi();
        int index = std::rand() % attackNameList.size();
        std::string attackName = attackNameList.at(index);
        AttackParams attackParams = this->entity->getAttackParamsForAiByName(attackName);

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
            CallFunc::create([this, moveState]() {this->isMoving = true; this->entity->stateMachine->move(moveState); }),
            DelayTime::create(dulation),
            CallFunc::create([this]() {this->entity->stateMachine->move(EntityMoveState::NONE); this->isMoving = false; }),
            NULL
        )
    );
}

void EnemyAI::attack(std::string attackName)
{
    if (this->isPreActionCharge) {
        this->entity->attack(attackName, 0.0f);
    } else {
        this->entity->attack(attackName);
    }
}

void EnemyAI::decideTarget()
{
    this->target = opponents.at(0);
}
