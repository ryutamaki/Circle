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
        std::string target;
        int hp;
        cocos2d::Vec2 position;
        EntityMoveState moveState;
        EntityAttackState attackState;
    };

    EntityState unpackEntityStateJSON(std::string json);
    std::string packEntityState(const EntityState entityState);
}

#endif /* defined(__DotWar__JSONPacker__) */
