//
//  MenuScene.h
//  DotWar
//
//  Created by ryutamaki on 2015/07/15.
//
//

#ifndef __DotWar__MenuScene__
#define __DotWar__MenuScene__

#include "cocos2d.h"
#include "CocosGUI.h"

#include "EntityConstants.h"

class MenuScene : public cocos2d::Layer
{
public:
    //there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);

private:
    void onEnter() override;

    void putEntityByEntityType(EntityType entityType);

    void singlePlayerButtonPushed(Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void multiplayerButtonPushed(Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void powerUpButtonPushed(Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);

};

#endif /* defined(__DotWar__MenuScene__) */
