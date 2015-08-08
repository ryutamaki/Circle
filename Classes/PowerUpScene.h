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

class Entity;

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
    EntityParameterLevel entityParameterLevel;
    Entity* entity;

    cocos2d::ui::Layout* coinLayout;
    cocos2d::ui::Layout* rankLayout;
    cocos2d::ui::Layout* hpLayout;
    cocos2d::ui::Layout* attackLayout;

    void onEnter() override;
    void setupUI();

    void setEntity(EntityType entityType);
    void setCoinCountLabelText(int coinCount);
    void setEntityParameterLevelLabelText(struct EntityParameterLevel entityParameterLevel);

    bool canUseCoin(int useCoinCount);
    void useCoin(int useCoinCount);

};

#endif /* defined(__DotWar__PowerUpScene__) */
