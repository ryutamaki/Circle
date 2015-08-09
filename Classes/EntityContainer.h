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

class EntityContainer
{
public:
    EntityContainer();
    ~EntityContainer();

    std::map<EntityIdentifier, Entity*> getAllEnemies();

    Entity* findEntity(EntityIdentifier identifier);
    Entity* findMyself();
    EntityAI* findAi(EntityIdentifier identifier);

    void addFriend(EntityIdentifier identifier, Entity* entity);
    void addEnemy(EntityIdentifier identifier, Entity* entity);
    void addAi(EntityIdentifier identifier, EntityAI* entity);

    void moveEnemyToCemetery(EntityIdentifier identifier);

    bool canSpawnEnemy(int characterRank, int enemyRank);

    void pauseAllEntity();
    void resumeAllEntity();

private:
    // These are formed for frineds VS enemies
    std::map<EntityIdentifier, Entity*> friends;
    std::map<EntityIdentifier, Entity*> enemies;

    // aiList have all of AIs running whether friends or enemies
    std::map<EntityIdentifier, EntityAI*> aiList;

    // Body list
    std::map<EntityIdentifier, Entity*> cemetery;

    
    Entity* findFriend(EntityIdentifier identifier);
    Entity* findEnemy(EntityIdentifier identifier);
};

#endif /* defined(__DotWar__EntityContainer__) */
