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

    // This function refer to user data
    static Entity* createUserEntityWityEntityType(EntityType entityType);

    static Entity* createEntityWithEntityType(EntityType entityType);
    static cocos2d::Vector<Entity*> createEntityList(int countOfSequence, EntityType entityType);
};

#endif /* defined(__DotWar__EntityFactory__) */
