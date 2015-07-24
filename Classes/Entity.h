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
#include "EntitySynchronizer.h"
#include "EntityHelper.h"

#include "cocostudio/CocoStudio.h"

class Entity : public cocos2d::Node, public EntityStateMachineDelegate
{
public:
    // This stateMachine is opened to the public
    EntityStateMachine* stateMachine;
    // This synchronizer manage data synchronizing when you play multiplayer mode
    EntitySynchronizer* synchronizer;

    CREATE_FUNC(Entity);

    // Accessors
    int getHp();
    void setHp(int hp);
    cocos2d::Vec2 getVelocity();
    cocos2d::Rect getRect();

    std::string getIdentifier();
    void setIdentifier(std::string identifier);

    cocos2d::Size getBodySize();
    bool getIsDead();

    JSONPacker::EntityState currentEntityState();

    void activate();
    void deactivate();

    // Behavior
    void attack(const std::string attackName);
    void receiveDamage(const int damage);

    // EntityStateMachineDelegate
    void willStateChange(EntityMoveState moveState, EntityAttackState attackState) override;
    void didStateChanged(EntityMoveState newMoveState, EntityAttackState newAttackState) override;

protected:
    cocostudio::timeline::ActionTimeline* timeline;
    std::string identifier;

    int hp, initialHp;
    float velocityFactor;
    cocos2d::Vec2 velocity;
    bool isDead;

    bool init() override;
    void onEnter() override;
    void onExit() override;

    void update(float dt) override;

};

#endif /* defined(__DotWar__Entity__) */
