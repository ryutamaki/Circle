//
//  Entity.h
//  DotWar
//
//  Created by ryutamaki on 2015/07/15.
//
//

#ifndef __DotWar__Entity__
#define __DotWar__Entity__

#include "cocos2d.h"

#include "EntityConstants.h"

class Entity : public cocos2d::Node
{
public:
    CREATE_FUNC(Entity);

    // Accessors
    int getHp();
    void setMoveState(EntityMoveState moveState);

    // Behavior
    virtual void attack();
    virtual void receiveDamage(int damage, cocos2d::Vec2 knockback);
    virtual bool isDead();

protected:
    int hp;
    EntityMoveState moveState;
    cocos2d::Vec2 velocity;

    bool init() override;
    void onEnter() override;
    void onExit() override;

    // Utility methods
    cocos2d::Vec2 directionFromMoveState(EntityMoveState moveState);
    EntityMoveState moveStateFromStartPositionAndEndPosition(cocos2d::Vec2 startPosition, cocos2d::Vec2 endPosition);

};

#endif /* defined(__DotWar__Entity__) */
