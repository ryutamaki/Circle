//
//  Entity.cpp
//  DotWar
//
//  Created by ryutamaki on 2015/07/15.
//
//

#include "Entity.h"

#include "EntityConstants.h"

USING_NS_CC;
using namespace cocostudio::timeline;

#pragma mark - Initilalizer

bool Entity::init()
{
    if (!Node::init())
    {
        return false;
    }

    this->stateMachine = new EntityStateMachine();

    this->hp = 100;
    this->velocity = Vec2(0.0f, 0.0f);

    return true;
}

#pragma mark Accessor

int Entity::getHp()
{
    return this->hp;
}

Vec2 Entity::getVelocity()
{
    return this->velocity;
}

Size Entity::getBodySize()
{
    Sprite* body = this->getChildByName<Sprite*>("Body");
    return body->getContentSize();
}

Rect Entity::getRect()
{
    Size size = this->getBodySize();
    Vec2 position = this->getPosition();

    Rect returnRect = Rect(
                      position.x - size.width * 0.5f,
                      position.y - size.height * 0.5f,
                      size.width, size.height
                      );
    return returnRect;
}

#pragma mark Game logic

void Entity::attack(std::string attackName)
{
    // override point
    if (!this->stateMachine->canAttack())
    {
        return;
    }

    this->stopAllActions();
    this->runAction(this->timeline);
    this->timeline->play(attackName, false);
    this->timeline->setFrameEventCallFunc([this](Frame* frame){
        EventFrame* frameEvent = dynamic_cast<EventFrame*>(frame);
        auto eventName = frameEvent->getEvent();
        log("---- %s ----", eventName.c_str());
        if (eventName == "Ready") {
            this->stateMachine->readyToAttack();
        }
        else if (eventName == "Attack") {
            this->stateMachine->startToAttack();
        }
        else if (eventName == "Cooldown") {
            this->stateMachine->coolDownAttaking();
        }
        else if (eventName == "Finish") {
            this->stateMachine->finishAttaking();
        }
    });
}

void Entity::receiveDamage(int damage, Vec2 knockback)
{
//    log("take damage %d, knockback %f:%f", damage, knockback.x, knockback.y);
    this->stateMachine->startMoving(this->moveStateFromVector(knockback));
    this->hp -= damage;

    // override point
}

bool Entity::isDead()
{
    if (this->getHp() < 0)
    {
        return true;
    }
    return false;
}

void Entity::update(float dt)
{
    Node::update(dt);

    if (this->stateMachine->getMoveState() == EntityMoveState::NONE)
    {
        this->velocity.setZero();
        return;
    }

    Vec2 direction = this->directionFromMoveState(this->stateMachine->getMoveState());
    this->velocity = ENTITY_SPEED * direction * dt;
}


#pragma mark - Protected method

#pragma mark View lifecycle

void Entity::onEnter()
{
    Node::onEnter();

    this->scheduleUpdate();
}

void Entity::onExit()
{
    Node::onExit();
}

#pragma mark Utility methods

Vec2 Entity::directionFromMoveState(EntityMoveState moveState)
{
    switch (moveState) {
        case EntityMoveState::UP_RIGHT:
            return Vec2(1.0f / sqrt(2.0f), 1.0f / sqrt(2.0f));
        case EntityMoveState::UP:
            return Vec2(0.0f, 1.0f);
        case EntityMoveState::UP_LEFT:
            return Vec2(- 1.0f / sqrt(2.0f), 1.0f / sqrt(2.0f));
        case EntityMoveState::LEFT:
            return Vec2(- 1.0f, 0.0f);
        case EntityMoveState::DOWN_LEFT:
            return Vec2(- 1.0f / sqrt(2.0f), - 1.0f / sqrt(2.0f));
        case EntityMoveState::DOWN:
            return Vec2(0.0f, - 1.0f);
        case EntityMoveState::DOWN_RIGHT:
            return Vec2(1.0f / sqrt(2.0f), - 1.0f / sqrt(2.0f));
        case EntityMoveState::RIGHT:
            return Vec2(1.0f, 0.0f);
        case EntityMoveState::NONE:
            return Vec2(0.0f, 0.0f);
        default:
            CCASSERT(false, "Undefined moveState are passed");
            break;
    }
}

EntityMoveState Entity::moveStateFromStartPositionAndEndPosition(cocos2d::Vec2 startPosition, cocos2d::Vec2 endPosition)
{
    Vec2 vector = endPosition - startPosition;
    return this->moveStateFromVector(vector);
}

EntityMoveState Entity::moveStateFromVector(cocos2d::Vec2 knockback)
{
    float radiun = Vec2::angle(knockback, Vec2(1.0f, 0.0f));
    float degree = CC_RADIANS_TO_DEGREES(radiun);
    degree = knockback.y > 0 ? degree : 360.0f - degree;

    if (22.5 <= degree && degree < 67.5)
        return EntityMoveState::UP_RIGHT;
    else if (67.5 <= degree && degree < 112.5)
        return EntityMoveState::UP;
    else if (112.5 <= degree && degree < 157.5)
        return EntityMoveState::UP_LEFT;
    else if (157.5 <= degree && degree < 202.5)
        return EntityMoveState::LEFT;
    else if (202.5 <= degree && degree < 247.5)
        return EntityMoveState::DOWN_LEFT;
    else if (247.5 <= degree && degree < 292.5)
        return EntityMoveState::DOWN;
    else if (292.5 <= degree && degree < 337.5)
        return EntityMoveState::DOWN_RIGHT;
    else
        return EntityMoveState::RIGHT;
}