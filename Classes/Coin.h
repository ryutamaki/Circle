//
//  Coin.h
//  DotWar
//
//  Created by ryutamaki on 2015/07/27.
//
//

#ifndef __DotWar__Coin__
#define __DotWar__Coin__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

class Coin : public cocos2d::Node {
public:
    CREATE_FUNC(Coin);
    bool init() override;

protected:
    cocostudio::timeline::ActionTimeline* timeline;

    void onEnter() override;
    void onExit() override;

};

#endif /* defined(__DotWar__Coin__) */
