//
// Circle.h
// DotWar
//
// Created by ryutamaki on 2015/07/15.
//
//

#ifndef __DotWar__Circle__
#define __DotWar__Circle__

#include "cocos2d.h"

#include "Entity.h"

class Circle: public Entity
{
public:
    CREATE_FUNC(Circle);
    bool init() override;

protected:
    void setupEntityParamerterByLevel(struct EntityParameterLevel parameterLevel) override;
};

#endif /* defined(__DotWar__Circle__) */
