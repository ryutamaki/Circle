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

protected:
    void setupAttackMap() override;
    void setupEntityParamerterByLevel(struct EntityParameterLevel parameterLevel) override;
};

#endif /* defined(__DotWar__Triangle__) */
