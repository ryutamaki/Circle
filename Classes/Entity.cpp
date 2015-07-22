//
// Entity.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/15.
//
//

#include "Entity.h"

#include "EntityConstants.h"

#include "SceneManager.h"
#include "JSONPacker.h"

USING_NS_CC;
using namespace cocostudio::timeline;

#pragma mark - Initilalizer

bool Entity::init()
{
    if (! Node::init()) {
        return false;
    }

    this->stateMachine = new EntityStateMachine();
    this->stateMachine->setDelegate(this);

    this->velocity = Vec2::ZERO;
    this->isSendData = false;

    return true;
}

#pragma mark Accessor

int Entity::getHp()
{
    return this->hp;
}

void Entity::setHp(int hp)
{
    this->hp = hp;

    Sprite* hpBar = dynamic_cast<Sprite*>(this->getChildByName("Bar"));

    if (hpBar && this->initialHp != 0) {
        hpBar->setScaleX(float(this->hp) / float(this->initialHp));
    }
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

void Entity::setIsSendData(bool isSendData)
{
    this->isSendData = isSendData;
}

Size Entity::getBodySize()
{
    Sprite* body = this->getChildByName<Sprite*>("Body");
    return body->getContentSize();
}

bool Entity::isDead()
{
    if (this->getHp() <= 0) {
        return true;
    } else {
        return false;
    }
}

#pragma mark Game logic

void Entity::attack(const std::string attackName)
{
    if (! this->stateMachine->canAttack()) {
        return;
    }

    this->timeline->play(attackName, false);
    this->timeline->setFrameEventCallFunc([this](Frame* frame) {
        EventFrame* frameEvent = dynamic_cast<EventFrame*>(frame);
        auto eventName = frameEvent->getEvent();

        // log("---- %s ----", eventName.c_str());
        if (eventName == "Ready") {
            this->stateMachine->readyToAttack();
        } else if (eventName == "Attack") {
            this->stateMachine->startToAttack();
        } else if (eventName == "Cooldown") {
            this->stateMachine->coolDownAttaking();
        } else if (eventName == "Finish") {
            this->stateMachine->finishAttaking();
        }
    });

    // override point
}

void Entity::receiveDamage(const int damage, const Vec2 knockback)
{
    // std::string animationName = "Damaged";
    // this->timeline->play(animationName, false);

    this->stateMachine->move(EntityHelper::moveStateFromVector(knockback));
    this->setHp(this->getHp() - damage);

    this->sendCurrentEntityData();

    // override point
}

#pragma mark EntityStateMachineDelegate

void Entity::willStateChange(EntityMoveState moveState, EntityAttackState attackState)
{}

void Entity::didStateChanged(EntityMoveState newMoveState, EntityAttackState newAttackState)
{
    if (! this->isSendData) {
        return;
    }

    this->sendCurrentEntityData();
}

#pragma mark - Protected method

#pragma mark View lifecycle

void Entity::onEnter()
{
    Node::onEnter();

    this->scheduleUpdate();
    this->runAction(this->timeline);
}

void Entity::onExit()
{
    Node::onExit();
}

#pragma mark Game logic

void Entity::update(float dt)
{
    Node::update(dt);

    EntityMoveState currentMoveState = this->stateMachine->getMoveState();
    Vec2 direction = EntityHelper::directionFromMoveState(currentMoveState);
    this->velocity = this->velocityFactor * direction * dt;
    this->setRotation(EntityHelper::rotationFromMoveState(currentMoveState, this->getRotation()));
}

void Entity::sendCurrentEntityData()
{
    JSONPacker::EntityState entityState;
    entityState.hp = this->getHp();
    entityState.position = this->getPosition();
    entityState.moveState = this->stateMachine->getMoveState();
    entityState.attackState = this->stateMachine->getAttackState();

    std::string json = JSONPacker::packEntityState(entityState);
    SceneManager::getInstance()->sendData(json.c_str(), json.length());
}
