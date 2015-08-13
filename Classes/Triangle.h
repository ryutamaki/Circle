//
// Triangle.h
// DotWar
//
// Created by ryutamaki on 2015/07/15.
//
//

#ifndef __DotWar__Triangle__
#define __DotWar__Triangle__

#include "cocos2d.h"
#include "Entity.h"

class Triangle: public Entity {
public:
    CREATE_FUNC(Triangle);
    bool init() override;

    int getCoinCountToRankUp() override;
    int getCoinCountToHpLevelUp() override;
    int getCoinCountToAttackLevelUp() override;

    std::vector<cocos2d::Rect> getRectsUseForAttackInWorldSpace() override;

protected:
    void setupEntityParamerterByLevel(struct EntityParameterLevel parameterLevel) override;
};

#endif /* defined(__DotWar__Triangle__) */
