//
// TriangleAI.h
// Circle
//
// Created by ryutamaki on 2015/08/13.
//
//

#ifndef __Circle__TriangleAI__
#define __Circle__TriangleAI__

#include "cocos2d.h"
#include "EntityAI.h"

class TriangleAI: public EntityAI
{
public:
    static TriangleAI* create(Entity* entity, cocos2d::Vector<Entity*> opponents);

    TriangleAI(Entity * entity, cocos2d::Vector<Entity*> opponents);
    ~TriangleAI();

protected:
    void running(float dt) override;

private:
    void onEnter() override;
    void onExit() override;
};

#endif /* defined(__Circle__TriangleAI__) */
