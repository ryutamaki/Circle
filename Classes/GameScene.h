#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "CocosGUI.h"
#include "GameConstants.h"

#include "EnemyAI.h"

class Circle;
class Triangle;

class GameScene : public cocos2d::Layer
{
public:
    virtual bool init();

    CREATE_FUNC(GameScene);

    void setNetworkedSession(bool networkedSession);
    void receivedData(const void* data, unsigned long length);

private:
    bool networkedSession;
    GameState gameState;

    cocos2d::Sprite* background;
    cocos2d::Sprite* field;
    cocos2d::ui::Button* lobbyButton;

    Circle* character;
    Circle* friendCharacter;
    Triangle* enemy;
    EnemyAI* enemyAI;

    void onEnter() override;
    void setupTouchHandling();

    void update(float dt) override;
    void checkGameOver();

    Entity* getTargetEntityByTargetString(std::string targetString);
    void showResultLayerWithString(std::string result);

    void readyToStart(Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void backToMenu(Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void tryToStart();
    void start();

};

#endif // __GAME_SCENE_H__
