//
// EntityFactory.h
// DotWar
//
// Created by ryutamaki on 2015/07/26.
//
//

#ifndef __DotWar__EntityFactory__
#define __DotWar__EntityFactory__

#include "cocos2d.h"

#include "EntityConstants.h"

class Entity;

class EntityFactory
{
public:
    EntityFactory();
    ~EntityFactory();

    static Entity* createEntity(EntityType entityType);
    static Entity* createEntity(EntityType entityType, EntityParameterLevel parameterLevel);
    static Entity* createEntity(EntityType entityType, EntityParameterLevel parameterLevel, cocos2d::Color4B initialColor);
};

#endif /* defined(__DotWar__EntityFactory__) */
