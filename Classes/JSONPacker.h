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

namespace JSONPacker
{
    struct EntityState
    {
        struct Damage
        {
            std::string identifier;
            int volume;
        };

        std::string identifier;
        int hp;
        cocos2d::Vec2 position;
        EntityMoveState moveState;
        EntityAttackState attackState;
        std::string attackName;
        Damage damage;

    };

    EntityState unpackEntityStateJSON(std::string json);
    std::string packEntityState(const EntityState entityState);

    struct EntityReadyState
    {
        std::string identifier;
        bool isReady;
        EntityType entityType;
        EntityParameterLevel parameterLevel;
    };

    EntityReadyState unpackEntityReadyStateJSON(std::string json);
    std::string packEntityReadyState(const EntityReadyState entityReadyState);
}

#endif /* defined(__DotWar__JSONPacker__) */
