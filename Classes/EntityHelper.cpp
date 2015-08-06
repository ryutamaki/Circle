//
// EntityHelper.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/21.
//
//

#include "EntityHelper.h"

#include "EntityConstants.h"

USING_NS_CC;
const EntityDirection EntityHelper::directionFromStartPositionAndEndPosition(const cocos2d::Vec2 startPosition, const cocos2d::Vec2 endPosition)
{
    Vec2 vector = endPosition - startPosition;
    float radiun = Vec2::angle(vector, Vec2::UNIT_X);
    float degree = CC_RADIANS_TO_DEGREES(radiun);
    degree = vector.y > 0 ? degree : 360.0f - degree;
    return static_cast<EntityDirection>(degree);
}

const Vec2 EntityHelper::unitVectorFronEntityDirection(EntityDirection direction)
{
    float degree = static_cast<float>(direction);
    float radiun = CC_DEGREES_TO_RADIANS(degree);
    return Vec2(cos(radiun), sin(radiun));
}

const bool EntityHelper::isRankExists(int rank)
{
    if (ENTITY_RANK_SYMBOL_PATH.count(rank)) {
        return true;
    }
    return false;
}

const bool EntityHelper::isNextRankExists(int rank)
{
    int nextRank = rank + 1;
    return EntityHelper::isRankExists(nextRank);
}
