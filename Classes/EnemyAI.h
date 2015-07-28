//
//  EnemyAI.h
//  DotWar
//
//  Created by ryutamaki on 2015/07/20.
//
//

#ifndef __DotWar__EnemyAI__
#define __DotWar__EnemyAI__

#include "cocos2d.h"
#include "Entity.h"

class EnemyAI : public cocos2d::Node
{
public:
    EnemyAI(Entity* entity, cocos2d::Vector<Entity*> opponents);
    ~EnemyAI();

    void start();
    void stop();

private:
    Entity* entity;

    Entity* target;
    cocos2d::Vector<Entity*> opponents;

    void running(float dt);

    void move(EntityMoveState moveState, float dulation);
    void attack(std::string attackName);

    void decideTarget();

};

#endif /* defined(__DotWar__EnemyAI__) */
