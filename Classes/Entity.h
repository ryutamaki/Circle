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
#include "EntityHelper.h"

#include "cocostudio/CocoStudio.h"

class Entity : public cocos2d::Node, public EntityStateMachineDelegate
{
public:
    // This stateMachine is opened to the public
    EntityStateMachine* stateMachine;

    CREATE_FUNC(Entity);

    // Accessors
    int getHp();
    void setHp(int hp);
    cocos2d::Vec2 getVelocity();
    cocos2d::Rect getRect();

    void setIsSendData(bool isSendData);
    cocos2d::Size getBodySize();
    virtual bool isDead();

    // Behavior
    virtual void attack(const std::string attackName);
    virtual void receiveDamage(const int damage, const cocos2d::Vec2 knockback);

    // EntityStateMachineDelegate
    void willStateChange(EntityMoveState moveState, EntityAttackState attackState) override;
    void didStateChanged(EntityMoveState newMoveState, EntityAttackState newAttackState) override;

protected:
    cocostudio::timeline::ActionTimeline* timeline;
    bool isSendData;

    int hp, initialHp;
    float velocityFactor;
    cocos2d::Vec2 velocity;

    bool init() override;
    void onEnter() override;
    void onExit() override;

    void update(float dt) override;
    void sendCurrentEntityData();
};

#endif /* defined(__DotWar__Entity__) */
