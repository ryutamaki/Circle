//
//  EntityAI.h
//  DotWar
//
//  Created by ryutamaki on 2015/07/20.
//
//

#ifndef __DotWar__EntityAI__
#define __DotWar__EntityAI__

#include "cocos2d.h"
#include "Entity.h"

class EntityAI : public cocos2d::Node
{
public:
    EntityAI(Entity* entity, cocos2d::Vector<Entity*> opponents);
    ~EntityAI();

    void start();
    void stop();

private:
    Entity* entity;

    Entity* target;
    cocos2d::Vector<Entity*> opponents;

    bool isMoving;
    bool isPreActionAttack;
    bool isPreActionCharge;

    void running(float dt);

    void stay(float dulation);
//    void move(EntityMoveState movieState, float dulation);
    void move(EntityDirection direction, float dulation);
    void attack(std::string attackName);

    void decideTarget();

};

#endif /* defined(__DotWar__EntityAI__) */
