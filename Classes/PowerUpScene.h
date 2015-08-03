//
//  PowerUpScene.h
//  DotWar
//
//  Created by ryutamaki on 2015/07/30.
//
//

#ifndef __DotWar__PowerUpScene__
#define __DotWar__PowerUpScene__

#include "cocos2d.h"
#include "CocosGUI.h"

#include "EntityConstants.h"

class PowerUpScene : public cocos2d::Layer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(PowerUpScene);

    void setEntityType(EntityType entityType);

private:
    int coinCount;
    EntityType entityType;
    EntityParameterLevel EntityParameterLevel;

    cocos2d::ui::TextBMFont* rankLabel;
    cocos2d::ui::TextBMFont* hpLabel;
    cocos2d::ui::TextBMFont* attackLabel;
    cocos2d::ui::TextBMFont* speedLabel;
    cocos2d::ui::TextBMFont* coinCountLabel;

    void onEnter() override;
    void setupUI(Node* rootNode);

    void setCoinCountLabelText(int coinCount);
    void setEntityParameterLevelLabelText(struct EntityParameterLevel EntityParameterLevel);

    bool canUseCoin(int useCoinCount);
    void useCoin(int useCoinCount);

};

#endif /* defined(__DotWar__PowerUpScene__) */
