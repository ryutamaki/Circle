//
//  TutorialLayer.h
//  DotWar
//
//  Created by ryutamaki on 2015/08/05.
//
//

#ifndef __DotWar__TutorialLayer__
#define __DotWar__TutorialLayer__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

enum class TutorialType {
    BASIC_CONTROL,
};

static const std::map<TutorialType, std::string> TUTOTIAL_NODE_NAME = {
    {TutorialType::BASIC_CONTROL, "Basic"},
};

class TutorialLayer : public cocos2d::Layer {
public:
    CREATE_FUNC(TutorialLayer);
    bool init() override;

    void show(TutorialType tutorialType);
    void hide();

protected:
    cocostudio::timeline::ActionTimeline* timeline;

    cocos2d::ui::Layout* tutorialLayout;

    void onEnter() override;

};

#endif /* defined(__DotWar__TutorialLayer__) */
