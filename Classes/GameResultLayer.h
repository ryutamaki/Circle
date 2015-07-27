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

    void setIsWin(bool isWin);

private:
    cocostudio::timeline::ActionTimeline* timeline;

    bool isWin;

    void onEnter() override;

    void backToMenu(Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
};

#endif /* defined(__DotWar__GameResultLayer__) */
