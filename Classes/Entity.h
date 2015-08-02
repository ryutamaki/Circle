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
#include "EntityConstants.h"

#include "cocostudio/CocoStudio.h"

struct AttackParams {
    int damage;
    cocos2d::Rect range;
};


class Entity : public cocos2d::Node, public EntityStateMachineDelegate
{
public:
    // This stateMachine is opened to the public
    std::unique_ptr<EntityStateMachine> stateMachine;
    // This synchronizer manage data synchronizing when you play multiplayer mode
    std::unique_ptr<EntitySynchronizer> synchronizer;

    // Accessors
    EntityParameter getEntityParameter();
    EntityLevelParameter getEntityLevelParameter();
    void setEntityLevelParameter(EntityLevelParameter entityParameter);

    int getHp();
    void setHp(int hp);
    cocos2d::Vec2 getVelocity();
    void setInitialColor(cocos2d::Color4B initialColor);

    std::string getCurrentAttackName();
    std::vector<std::string> getAttackNameList();
    AttackParams getAttackParamsByName(std::string attackName);

    cocos2d::Rect getBodyRect();
    cocos2d::Rect getBodyRectInWorldSpace();

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
    void die();

    // EntityStateMachineDelegate
    void willStateChange(EntityMoveState moveState, EntityAttackState attackState) override;
    void didStateChanged(EntityMoveState newMoveState, EntityAttackState newAttackState) override;

protected:
    cocostudio::timeline::ActionTimeline* timeline;
    std::string identifier;

    EntityParameter entityParameter;
    EntityLevelParameter entityLevelParameter;

    int hp;
    cocos2d::Vec2 velocity;
    std::string currentAttackName;
    std::map<std::string, AttackParams> attackMap;
    Color4B initialColor;
    bool isDead;

    bool init() override;
    void onEnter() override;
    void onExit() override;

    Sprite* getBody();
    void setBodyColorByCurrentHp();

    void update(float dt) override;

    // Abstruct methods
    virtual void setupAttackMap() = 0;
    virtual void setupEntityParamerterByLevel(EntityLevelParameter levelParameter) = 0;

};

#endif /* defined(__DotWar__Entity__) */
