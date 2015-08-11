//
//  GamePauseLayer.h
//  DotWar
//
//  Created by ryutamaki on 2015/07/31.
//
//

#ifndef __DotWar__GamePauseLayer__
#define __DotWar__GamePauseLayer__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

class GamePauseLayer : public cocos2d::Layer {
public:
    CREATE_FUNC(GamePauseLayer);

    void show(Node* parent);
    void hide(std::function<void()> lastFrameCallback);

    void setCurrentGameStateForAnalytics(bool networked, int score, int coinEarned);

protected:
    cocostudio::timeline::ActionTimeline* timeline;
    
    cocos2d::ui::Layout* pauseLayout;

    // Use for analytics
    bool networked;
    int score;
    int coinEarned;

    bool init() override;
    void onEnter() override;

};

#endif /* defined(__DotWar__GamePauseLayer__) */
