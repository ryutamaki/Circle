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

class Character : public cocos2d::Node {
public:
    CREATE_FUNC(Character);
    bool init() override;

protected:
    cocostudio::timeline::ActionTimeline* timeline;

};

#endif /* defined(__DotWar__Character__) */
