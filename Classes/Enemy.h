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

class Enemy : public cocos2d::Node {
public:
    CREATE_FUNC(Enemy);
    bool init() override;

    void recieveAttack(int damage);

    int getHp();

protected:
    cocostudio::timeline::ActionTimeline* timeline;

    int hp;

};

#endif /* defined(__DotWar__Enemy__) */
