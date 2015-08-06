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

class Entity : public cocos2d::Node, public EntityStateMachineDelegate
{
public:
    // This stateMachine is opened to the public
    std::unique_ptr<EntityStateMachine> stateMachine;
    // This synchronizer manage data synchronizing when you play multiplayer mode
    std::unique_ptr<EntitySynchronizer> synchronizer;

    // Accessors
    EntityType getEntityType() const;
    void setEntityType(EntityType entityType);
    EntityParameter getEntityParameter();
    EntityParameterLevel getEntityParameterLevel();
    void setEntityParameterLevel(EntityParameterLevel entityParameter);

    int getHp();
    void setHp(int hp);
    cocos2d::Vec2 getVelocity();
    void setInitialColor(cocos2d::Color4B initialColor);

    std::string getCurrentAttackName();
    std::vector<std::string> getAttackNameList();
    void setAttackMap(std::map<std::string, EntityAttackParams> attackMap);
    EntityAttackParams getAttackParamsByName(std::string attackName);

    cocos2d::Rect getBodyRect();
    std::vector<cocos2d::Rect> getRectsUseForAttackInWorldSpace();
    std::vector<cocos2d::Rect> getRectsUseForDamageInWorldSpace();

    std::string getIdentifier();
    void setIdentifier(std::string identifier);

    cocos2d::Size getBodySize();
    bool getIsDead();

    JSONPacker::EntityState currentEntityState();

    void activate();
    void deactivate();

    // Behavior
    void attack(const std::string attackName);
    void startCharging();
    void endCharging();
    // EntityStateMachineDelegate
    void willStateChange(EntityMoveState moveState, EntityAttackState attackState) override;
    void didStateChanged(EntityMoveState newMoveState, EntityAttackState newAttackState) override;

protected:
    cocostudio::timeline::ActionTimeline* timeline;
    std::string identifier;

    EntityType entityType;
    EntityParameter entityParameter;
    EntityParameterLevel EntityParameterLevel;

    int hp;
    cocos2d::Vec2 velocity;
    std::string currentAttackName;
    std::map<std::string, EntityAttackParams> attackMap;
    Color4B initialColor;
    bool isDead;

    bool init() override;
    void onEnter() override;
    void onExit() override;

    Sprite* getBody();
    void setRankSymbol(int rank);
    void setBodyColorByCurrentHp();

    // Behavior
    void update(float dt) override;
    void receiveDamage();
    void die();

    // Abstruct methods
    virtual void setupEntityParamerterByLevel(struct EntityParameterLevel parameterLevel) = 0;

};

#endif /* defined(__DotWar__Entity__) */
