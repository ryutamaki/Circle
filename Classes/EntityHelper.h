//
// EntityHelper.h
// DotWar
//
// Created by ryutamaki on 2015/07/21.
//
//

#ifndef __DotWar__EntityHelper__
#define __DotWar__EntityHelper__

#include "cocos2d.h"
#include "EntityStateMachine.h"

class EntityHelper
{
public:
    // static const cocos2d::Vec2 directionFromMoveState(const EntityMoveState moveState);
    // FIXME: I dont wanna pass "currentRotation" if I can.
    // static const float rotationFromMoveState(const EntityMoveState moveState, const float currentRotation);
    static const EntityDirection directionFromStartPositionAndEndPosition(const cocos2d::Vec2 startPosition, const cocos2d::Vec2 endPosition);
    // static const EntityMoveState moveStateFromVector(const cocos2d::Vec2 knockback);

    static const Vec2 unitVectorFronEntityDirection(EntityDirection direction);

    static const bool isRankExists(int rank);
    static const bool isNextRankExists(int rank);
};

#endif /* defined(__DotWar__EntityHelper__) */
