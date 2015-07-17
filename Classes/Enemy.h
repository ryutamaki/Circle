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
#include "Entity.h"

class Enemy : public Entity {
public:
    CREATE_FUNC(Enemy);
    bool init() override;

private:
    void onEnter() override;

    void updateAttack(float dt);
};

#endif /* defined(__DotWar__Enemy__) */
