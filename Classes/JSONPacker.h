//
//  JSONPacker.h
//  DotWar
//
//  Created by ryutamaki on 2015/07/15.
//
//

#ifndef __DotWar__JSONPacker__
#define __DotWar__JSONPacker__

#include "cocos2d.h"

#include "EntityStateMachine.h"
#include "EntityConstants.h"

namespace JSONPacker
{

    GameState getGameStateFromJSON(const std::string& json);
    std::string packGameState(const GameState gameState);

    struct EntityState
    {
        struct Damage
        {
            EntityIdentifier identifier;
            int volume;
        };

        GameState gameState;
        EntityIdentifier identifier;
        int hp;
        cocos2d::Vec2 position;
        EntityDirection direction;
        EntityMoveState moveState;
        EntityGlobalState globalState;
        EntityAttackState attackState;
        std::string attackName;
        Damage damage;

    };

    EntityState unpackEntityStateJSON(std::string json);
    std::string packEntityState(const EntityState entityState);

    struct EntityReadyState
    {
        GameState gameState;
        EntityIdentifier identifier;
        bool isReady;
        EntityType entityType;
        EntityParameterLevel parameterLevel;
    };

    EntityReadyState unpackEntityReadyStateJSON(std::string json);
    std::string packEntityReadyState(const EntityReadyState entityReadyState);
}

#endif /* defined(__DotWar__JSONPacker__) */
