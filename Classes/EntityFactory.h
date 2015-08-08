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

    Entity* createEntity(
        EntityType entityType
    );

    Entity* createEntity(
        EntityType				entityType,
        EntityParameterLevel	parameterLevel
    );

    Entity* createEntity(
        EntityType entityType,
        EntityParameterLevel parameterLevel,
        std::map<std::string, EntityAttackParams> attackMap
    );

    Entity* createEntity(
        EntityType entityType,
        EntityParameterLevel parameterLevel,
        std::map<std::string, EntityAttackParams> attackMap,
        cocos2d::Color4B initialColor
    );

private:
    EntityIdentifier identifier;
};

#endif /* defined(__DotWar__EntityFactory__) */
