//
// EntityHelper.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/21.
//
//

#include "EntityHelper.h"

USING_NS_CC;

const cocos2d::Vec2 EntityHelper::directionFromMoveState(const EntityMoveState moveState)
{
    switch (moveState) {
        case EntityMoveState::UP_RIGHT:
            return Vec2(1.0f / sqrt(2.0f), 1.0f / sqrt(2.0f));

        case EntityMoveState::UP:
            return Vec2::UNIT_Y;

        case EntityMoveState::UP_LEFT:
            return Vec2(-1.0f / sqrt(2.0f), 1.0f / sqrt(2.0f));

        case EntityMoveState::LEFT:
            return Vec2(-1.0f, 0.0f);

        case EntityMoveState::DOWN_LEFT:
            return Vec2(-1.0f / sqrt(2.0f), -1.0f / sqrt(2.0f));

        case EntityMoveState::DOWN:
            return Vec2(0.0f, -1.0f);

        case EntityMoveState::DOWN_RIGHT:
            return Vec2(1.0f / sqrt(2.0f), -1.0f / sqrt(2.0f));

        case EntityMoveState::RIGHT:
            return Vec2::UNIT_X;

        case EntityMoveState::NONE:
            return Vec2::ZERO;

        default:
            CCASSERT(false, "Undefined moveState are passed");
            break;
    }
}

const float EntityHelper::rotationFromMoveState(const EntityMoveState moveState, const float currentRotation)
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
            return currentRotation;

        default:
            CCASSERT(false, "Undefined moveState are passed");
            break;
    }
}

const EntityMoveState EntityHelper::moveStateFromStartPositionAndEndPosition(const cocos2d::Vec2 startPosition, const cocos2d::Vec2 endPosition)
{
    Vec2 vector = endPosition - startPosition;
    return EntityHelper::moveStateFromVector(vector);
}

const EntityMoveState EntityHelper::moveStateFromVector(const cocos2d::Vec2 knockback)
{
    if (knockback.equals(Vec2::ZERO)) {
        return EntityMoveState::NONE;
    }

    float radiun = Vec2::angle(knockback, Vec2::UNIT_X);
    float degree = CC_RADIANS_TO_DEGREES(radiun);
    degree = knockback.y > 0 ? degree : 360.0f - degree;

    if (22.5 <= degree && degree < 67.5) {
        return EntityMoveState::UP_RIGHT;
    } else if (67.5 <= degree && degree < 112.5) {
        return EntityMoveState::UP;
    } else if (112.5 <= degree && degree < 157.5) {
        return EntityMoveState::UP_LEFT;
    } else if (157.5 <= degree && degree < 202.5) {
        return EntityMoveState::LEFT;
    } else if (202.5 <= degree && degree < 247.5) {
        return EntityMoveState::DOWN_LEFT;
    } else if (247.5 <= degree && degree < 292.5) {
        return EntityMoveState::DOWN;
    } else if (292.5 <= degree && degree < 337.5) {
        return EntityMoveState::DOWN_RIGHT;
    } else {
        return EntityMoveState::RIGHT;
    }
}
