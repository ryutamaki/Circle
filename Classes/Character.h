//
//  Character.h
//  DotWar
//
//  Created by ryutamaki on 2015/07/15.
//
//

#ifndef __DotWar__Character__
#define __DotWar__Character__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "GameConstants.h"

#include "Entity.h"

class Character : public Entity {
public:
    CREATE_FUNC(Character);
    bool init() override;

    void setMoveStateByStartPositionAndCurrentPosition(Vec2 startPosition, Vec2 currentPosition);

    void attack() override;
    void receiveDamage(int damage, Vec2 knockback);

private:
    cocostudio::timeline::ActionTimeline* timeline;

    void onEnter() override;

    void update(float dt) override;

};

#endif /* defined(__DotWar__Character__) */
