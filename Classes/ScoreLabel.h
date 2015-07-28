//
//  ScoreLabel.h
//  DotWar
//
//  Created by ryutamaki on 2015/07/28.
//
//

#ifndef __DotWar__ScoreLabel__
#define __DotWar__ScoreLabel__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "CocosGUI.h"

class ScoreLabel : public cocos2d::Node {
public:
    CREATE_FUNC(ScoreLabel);
    bool init() override;

    void setScore(int score);

protected:
    cocostudio::timeline::ActionTimeline* timeline;

    cocos2d::ui::TextBMFont* scoreLabel;

    void onEnter() override;
    void onExit() override;

};

#endif /* defined(__DotWar__ScoreLabel__) */
