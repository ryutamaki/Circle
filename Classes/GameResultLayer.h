//
//  GameResultLayer.h
//  DotWar
//
//  Created by ryutamaki on 2015/07/27.
//
//

#ifndef __DotWar__GameResultLayer__
#define __DotWar__GameResultLayer__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

class GameResultLayer : public cocos2d::Layer {
public:
    CREATE_FUNC(GameResultLayer);
    bool init() override;

    void setScore(int score);
    void setHighScore(int highScore, bool isNewRecord);
    void setCoinCount(int coinCount);

private:
    cocostudio::timeline::ActionTimeline* timeline;

    cocos2d::ui::Layout* resultLayout;

    void onEnter() override;

};

#endif /* defined(__DotWar__GameResultLayer__) */
