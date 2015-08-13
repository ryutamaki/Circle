//
// TriangleAI.cpp
// Circle
//
// Created by ryutamaki on 2015/08/13.
//
//

#include "TriangleAI.h"

USING_NS_CC;

#pragma mark - Public methods

TriangleAI* TriangleAI::create(Entity* entity, Vector<Entity*> opponents)
{
    TriangleAI* pRet = new(std::nothrow)TriangleAI(entity, opponents);

    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    } else {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

TriangleAI::TriangleAI(Entity* entity, Vector<Entity*> opponents)
    : EntityAI(entity, opponents)
{
}

TriangleAI::~TriangleAI()
{
}

#pragma mark Protected methods

void TriangleAI::running(float dt)
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

    if (rand < 0.10f) {
        this->stay(1.0f);
        return;
    } else if (rand < 0.15f) {
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

        if (distance < 400.0f && CCRANDOM_0_1() < 0.3f) {
            this->move(direction, 0.0f);
            this->entity->startCharging();
            this->stay(2.0f);
            this->isPreActionCharge = true;
            return;
        } else {
            this->move(direction, 0.3f);
        }
    }
}

#pragma mark Private methods

#pragma mark View lifecycle

void TriangleAI::onEnter()
{
    Node::onEnter();
}

void TriangleAI::onExit()
{
    Node::onExit();
}
