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

static const EntityIdentifier ENTITY_HOST_PLAYER_IDENTIFIER = -1;
static const EntityIdentifier ENTITY_BUDDY_PLAYER_IDENTIFIER = -2;
static const EntityIdentifier ENEMY_INITIAL_IDENTIFIER = 1;

class Entity;
class EntityAI;

class EntityFactory
{
public:
    EntityFactory();
    ~EntityFactory();

    Entity* createFriend(
        bool					isHost,
        EntityType				entityType,
        EntityParameterLevel	parameterLevel
    );

    Entity* createFriend(
        bool isHost,
        EntityType entityType,
        EntityParameterLevel parameterLevel,
        std::map<std::string, EntityAttackParams> attackMap
    );

    Entity* createEnemy(
        EntityType				entityType,
        EntityParameterLevel	parameterLevel
    );

    Entity* createEnemy(
        EntityType entityType,
        EntityParameterLevel parameterLevel,
        std::map<std::string, EntityAttackParams> attackMap
    );

    EntityAI* createAI(
        Entity* entity,
        cocos2d::Vector<Entity*> opponents
    );

private:
    EntityIdentifier enemyIdentifier;

    Entity* gen(
        EntityIdentifier identifier,
        EntityType entityType,
        EntityParameterLevel parameterLevel,
        std::map<std::string, EntityAttackParams> attackMap,
        cocos2d::Color4B initialColor
    );
};

#endif /* defined(__DotWar__EntityFactory__) */
