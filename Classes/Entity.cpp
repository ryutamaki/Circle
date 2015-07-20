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

    this->velocity = Vec2::ZERO;

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

Size Entity::getBodySize()
{
    Sprite* body = this->getChildByName<Sprite*>("Body");
    return body->getContentSize();
}

bool Entity::isDead()
{
    if (this->getHp() <= 0)
        return true;
    else
        return false;
}

#pragma mark Game logic

void Entity::attack(const std::string attackName)
{
    if (!this->stateMachine->canAttack())
        return;

    this->stopAllActions();
    this->runAction(this->timeline);
    this->timeline->play(attackName, false);
    this->timeline->setFrameEventCallFunc([this](Frame* frame){
        EventFrame* frameEvent = dynamic_cast<EventFrame*>(frame);
        auto eventName = frameEvent->getEvent();
//        log("---- %s ----", eventName.c_str());
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

    // override point
}

void Entity::receiveDamage(const int damage, const Vec2 knockback)
{
//    std::string animationName = "Damaged";
//    this->stopAllActions();
//    this->runAction(this->timeline);
//    this->timeline->play(animationName, false);

    this->runAction(Blink::create(0.1f, 2));

    log("take damage %d, knockback %f:%f", damage, knockback.x, knockback.y);
    this->stateMachine->startMoving(this->moveStateFromVector(knockback));
    this->hp -= damage;

    Sprite* hpBar = dynamic_cast<Sprite*>(this->getChildByName("Bar"));
    hpBar->setScaleX(float(this->hp) / float(this->initialHp));
    // override point
}

void Entity::update(float dt)
{
    Node::update(dt);

    EntityMoveState currentMoveState = this->stateMachine->getMoveState();
    Vec2 direction = this->directionFromMoveState(currentMoveState);
    this->velocity = ENTITY_SPEED * direction * dt;
    this->setRotation(this->rotationFromMoveState(currentMoveState));
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

const Vec2 Entity::directionFromMoveState(const EntityMoveState moveState)
{
    switch (moveState) {
        case EntityMoveState::UP_RIGHT:
            return Vec2(1.0f / sqrt(2.0f), 1.0f / sqrt(2.0f));
        case EntityMoveState::UP:
            return Vec2::UNIT_Y;
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
            return Vec2::UNIT_X;
        case EntityMoveState::NONE:
            return Vec2::ZERO;
        default:
            CCASSERT(false, "Undefined moveState are passed");
            break;
    }
}

const float Entity::rotationFromMoveState(const EntityMoveState moveState)
{
    // this is tricky function because of cocos2d rotation is anti clocked
    switch (moveState) {
        case EntityMoveState::UP_RIGHT:
            return 315.0f;
        case EntityMoveState::UP:
            return 270.0f;
        case EntityMoveState::UP_LEFT:
            return 225.0f;
        case EntityMoveState::LEFT:
            return 180.0f;
        case EntityMoveState::DOWN_LEFT:
            return 135.0f;
        case EntityMoveState::DOWN:
            return 90.0f;
        case EntityMoveState::DOWN_RIGHT:
            return 45.0f;
        case EntityMoveState::RIGHT:
            return 0.0f;
        case EntityMoveState::NONE:
            // return curretn rotation if moveState is NONE
            return this->getRotation();
        default:
            CCASSERT(false, "Undefined moveState are passed");
            break;
    }
}

const EntityMoveState Entity::moveStateFromStartPositionAndEndPosition(const Vec2 startPosition, const Vec2 endPosition)
{
    Vec2 vector = endPosition - startPosition;
    return this->moveStateFromVector(vector);
}

const EntityMoveState Entity::moveStateFromVector(const Vec2 knockback)
{
    if (knockback.equals(Vec2::ZERO))
        return EntityMoveState::NONE;

    float radiun = Vec2::angle(knockback, Vec2::UNIT_X);
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