//
//  Enemy.h
//  DotWar
//
//  Created by ryutamaki on 2015/07/15.
//
//

#ifndef __DotWar__Enemy__
#define __DotWar__Enemy__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "Entity.h"

class Enemy : public Entity {
public:
    CREATE_FUNC(Enemy);
    bool init() override;

    void recieveDamage(int damage, Vec2 knockback);

private:
    cocostudio::timeline::ActionTimeline* timeline;

    void onEnter() override;
};

#endif /* defined(__DotWar__Enemy__) */