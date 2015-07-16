#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "CocosGUI.h"

class Character;
class Enemy;

class GameScene : public cocos2d::Layer
{
public:
    virtual bool init();

    CREATE_FUNC(GameScene);

    void setNetworkedSession(bool networkedSession);
    void receivedData(const void* data, unsigned long length);

private:
    bool networkedSession;
    
    Character* character;
    Enemy* enemy;

    void onEnter() override;
    void setupUserInterfaces(Node* rootNode);
    void setupTouchHandling();

    void update(float dt) override;
    void checkGameOver();

    void attackButtonPushed(Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    
};

#endif // __GAME_SCENE_H__
