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

#pragma mark - Private methods

void EntityAI::running(float dt)
{
    if (this->isMoving) {
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

    if (! this->target || this->target->stateMachine->isDead()) {
        auto it = this->opponents.find(this->target);

        if (it != this->opponents.end()) {
            this->opponents.erase(it);
        }
        this->decideTarget();
        return;
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
    } else if (rand < 0.2f) {
        this->decideTarget();
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
        EntityDirection direction = EntityHelper::directionFromStartPositionAndEndPosition(myPosition, targetPosition);

        this->move(direction, 0.3f);
    }
}

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
