//
//  Character.cpp
//  DotWar
//
//  Created by ryutamaki on 2015/07/15.
//
//

#include "Character.h"

#pragma mark - Public methods

#pragma mark Initializer

bool Character::init() {
    if (!Entity::init()) {
        return false;
    }

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("Character.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->timeline->retain();

    return true;
}

#pragma mark Accessor

void Character::setMoveStateByStartPositionAndCurrentPosition(cocos2d::Vec2 startPosition, cocos2d::Vec2 currentPosition)
{
    Vec2 direction = currentPosition - startPosition;
    float yDifference = currentPosition.y - startPosition.y;
    float radiun = Vec2::angle(direction, Vec2(1.0f, 0.0f));
    float degree = CC_RADIANS_TO_DEGREES(radiun);
    degree = yDifference > 0 ? degree : 360.0f - degree;

    if (22.5 <= degree && degree < 67.5)
    {
        this->setMoveState(CharacterMoveState::UP_RIGHT);
    }
    else if (67.5 <= degree && degree < 112.5)
    {
        this->setMoveState(CharacterMoveState::UP);
    }
    else if (112.5 <= degree && degree < 157.5)
    {
        this->setMoveState(CharacterMoveState::UP_LEFT);
    }
    else if (157.5 <= degree && degree < 202.5)
    {
        this->setMoveState(CharacterMoveState::LEFT);
    }
    else if (202.5 <= degree && degree < 247.5)
    {
        this->setMoveState(CharacterMoveState::DOWN_LEFT);
    }
    else if (247.5 <= degree && degree < 292.5)
    {
        this->setMoveState(CharacterMoveState::DOWN);
    }
    else if (292.5 <= degree && degree < 337.5)
    {
        this->setMoveState(CharacterMoveState::DOWN_RIGHT);
    }
    else
    {
        this->setMoveState(CharacterMoveState::RIGHT);
    }
}

#pragma mark Game logic

void Character::attack()
{
    this->stopAllActions();
    this->runAction(this->timeline);
    this->timeline->play("Attack", false);
}

void Character::receiveDamage(int damage, Vec2 knockback)
{
    this->runAction(Sequence::create(ScaleTo::create(0.1f, 0.9f), ScaleTo::create(0.1f, 1.0f), NULL));
    
    this->hp -= damage;
    this->setPosition(this->getPosition() + knockback);
}

#pragma mark - Prvate methods

#pragma mark View lifecycle

void Character::onEnter()
{
    Entity::onEnter();

    this->scheduleUpdate();
}

#pragma mark Game logic

void Character::update(float dt)
{
    Node::update(dt);

    Vec2 direction;
    switch (this->moveState) {
        case CharacterMoveState::UP_RIGHT:
            direction = Vec2(1.0f / sqrt(2.0f), 1.0f / sqrt(2.0f));
            break;
        case CharacterMoveState::UP:
            direction = Vec2(0.0f, 1.0f);
            break;
        case CharacterMoveState::UP_LEFT:
            direction = Vec2(- 1.0f / sqrt(2.0f), 1.0f / sqrt(2.0f));
            break;
        case CharacterMoveState::LEFT:
            direction = Vec2(- 1.0f, 0.0f);
            break;
        case CharacterMoveState::DOWN_LEFT:
            direction = Vec2(- 1.0f / sqrt(2.0f), - 1.0f / sqrt(2.0f));
            break;
        case CharacterMoveState::DOWN:
            direction = Vec2(0.0f, - 1.0f);
            break;
        case CharacterMoveState::DOWN_RIGHT:
            direction = Vec2(1.0f / sqrt(2.0f), - 1.0f / sqrt(2.0f));
            break;
        case CharacterMoveState::RIGHT:
            direction = Vec2(1.0f, 0.0f);
            break;
        case CharacterMoveState::NONE:
            direction = Vec2(0.0f, 0.0f);
            break;
        default:
            break;
    }

    this->velocity = CHARACTER_SPEED * direction;
    this->setPosition(this->getPosition() + this->velocity);
}

