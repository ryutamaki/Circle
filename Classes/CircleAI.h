//
// CircleAI.h
// Circle
//
// Created by ryutamaki on 2015/08/12.
//
//

#ifndef __Circle__CircleAI__
#define __Circle__CircleAI__

#include "cocos2d.h"
#include "EntityAI.h"

class CircleAI: public EntityAI
{
public:
    static CircleAI* create(Entity* entity, cocos2d::Vector<Entity*> opponents);

    CircleAI(Entity* entity, cocos2d::Vector<Entity*> opponents);
    ~CircleAI();

protected:
    void running(float dt) override;

private:
    void onEnter() override;
    void onExit() override;
};

#endif /* defined(__Circle__CircleAI__) */
