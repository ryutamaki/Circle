//
//  PowerUpButton.h
//  Circle
//
//  Created by ryutamaki on 2015/08/13.
//
//

#ifndef __Circle__PowerUpButton__
#define __Circle__PowerUpButton__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "CocosGUI.h"

class Entity;

class PowerUpButton : public cocos2d::Node {
public:
    CREATE_FUNC(PowerUpButton);
    bool init() override;

    void setNotifierByEntity(Entity* entity);

protected:
    cocostudio::timeline::ActionTimeline* timeline;

    cocos2d::ui::Button* powerUpButton;
    cocos2d::Sprite* notifier;

    void onEnter() override;
    void onExit() override;

};

#endif /* defined(__Circle__PowerUpButton__) */
