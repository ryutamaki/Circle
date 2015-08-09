//
//  CoinLabel.h
//  DotWar
//
//  Created by ryutamaki on 2015/08/09.
//
//

#ifndef __DotWar__CoinLabel__
#define __DotWar__CoinLabel__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "CocosGUI.h"

class CoinLabel : public cocos2d::Node {
public:
    CREATE_FUNC(CoinLabel);
    bool init() override;

    void setCoinCount(int coinCount);

protected:
    cocostudio::timeline::ActionTimeline* timeline;

    cocos2d::ui::TextBMFont* coinLabel;
    int coinCount;

    void onEnter() override;
    void onExit() override;

};

#endif /* defined(__DotWar__CoinLabel__) */
