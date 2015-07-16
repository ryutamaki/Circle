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

#include "GameConstants.h"

class Entity : public cocos2d::Node
{
public:
    CREATE_FUNC(Entity);

    // Accessors
    int getHp();
    void setMoveState(CharacterMoveState moveState);

    // Behavior
    virtual void attack();
    virtual void receiveDamage(int damage, cocos2d::Vec2 knockback);

protected:
    int hp;
    CharacterMoveState moveState;
    cocos2d::Vec2 velocity;

    bool init() override;
    void onEnter() override;
    void onExit() override;

};

#endif /* defined(__DotWar__Entity__) */
