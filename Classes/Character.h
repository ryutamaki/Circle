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

class Character : public cocos2d::Node {
public:
    CREATE_FUNC(Character);
    bool init() override;

    void setMoveState(CharacterMoveState moveState);
    void setMoveStateByStartPositionAndCurrentPosition(Vec2 startPosition, Vec2 currentPosition);

private:
    cocostudio::timeline::ActionTimeline* timeline;

    CharacterMoveState moveState;
    Vec2 velocity;

    void onEnter() override;

    void update(float dt) override;

};

#endif /* defined(__DotWar__Character__) */
