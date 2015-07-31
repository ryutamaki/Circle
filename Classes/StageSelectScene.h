//
//  StageSelectScene.h
//  DotWar
//
//  Created by ryutamaki on 2015/07/26.
//
//

#ifndef __DotWar__StageSelectScene__
#define __DotWar__StageSelectScene__

#include "cocos2d.h"
#include "CocosGUI.h"

class StageSelectScene : public cocos2d::Layer
{
public:
    //there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(StageSelectScene);

private:
    cocos2d::ui::PageView* pageView;
    cocos2d::ui::Button* playButton;

    void onEnter() override;
    void onExit() override;
    void setupStageSelectButtons();
    void setupPlayButton();
    void expandPageViewTouchHandler();

};

#endif /* defined(__DotWar__StageSelectScene__) */
