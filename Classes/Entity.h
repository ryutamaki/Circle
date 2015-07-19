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

#include "EntityStateMachine.h"
#include "cocostudio/CocoStudio.h"

class Entity : public cocos2d::Node
{
public:
    // This stateMachine is opened to the public
    EntityStateMachine* stateMachine;

    CREATE_FUNC(Entity);

    // Accessors
    int getHp();
    cocos2d::Vec2 getVelocity();
    cocos2d::Size getBodySize();
    cocos2d::Rect getRect();

    // Behavior
    virtual void attack(std::string attackName);
    virtual void receiveDamage(int damage, cocos2d::Vec2 knockback);
    virtual bool isDead();

protected:
    cocostudio::timeline::ActionTimeline* timeline;

    int hp;
    cocos2d::Vec2 velocity;

    bool init() override;
    void onEnter() override;
    void onExit() override;

    void update(float dt) override;

    // Utility methods
    cocos2d::Vec2 directionFromMoveState(EntityMoveState moveState);
    EntityMoveState moveStateFromStartPositionAndEndPosition(cocos2d::Vec2 startPosition, cocos2d::Vec2 endPosition);
    EntityMoveState moveStateFromVector(cocos2d::Vec2 knockback);

};

#endif /* defined(__DotWar__Entity__) */
