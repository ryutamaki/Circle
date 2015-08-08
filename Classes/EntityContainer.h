//
// EntityContainer.h
// DotWar
//
// Created by ryutamaki on 2015/08/07.
//
//

#ifndef __DotWar__EntityContainer__
#define __DotWar__EntityContainer__

#include "cocos2d.h"

#include "Entity.h"
#include "EntityAI.h"

typedef unsigned int id;

class EntityContainer
{
public:
    EntityContainer();
    ~EntityContainer();

    void addFriend(id identifier, Entity* entity);
    void addEnemy(id identifier, Entity* entity);
    void moveEnemyToCemetery(id identifier);

private:
    // These are formed for frineds VS enemies
    std::map<id, Entity*> friends;
    std::map<id, Entity*> enemies;

    // aiList have all of AIs running whether friends or enemies
    std::map<id, EntityAI*> aiList;

    // Body list
    std::map<id, Entity*> cemetery;
};

#endif /* defined(__DotWar__EntityContainer__) */
