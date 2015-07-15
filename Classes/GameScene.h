#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "CocosGUI.h"

class Character;
class Enemy;

class GameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

    void setNetworkedSession(bool networkedSession);
    void receivedData(const void* data, unsigned long length);

private:
    bool networkedSession;
    
    Character* character;
    Enemy* enemy;

    void onEnter() override;
    void setupTouchHandling();

    void attackButtonPushed(Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    
};

#endif // __GAME_SCENE_H__
