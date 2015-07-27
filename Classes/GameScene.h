#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "CocosGUI.h"

#include "GameConstants.h"
#include "EntityConstants.h"

class Entity;
class EnemyAI;

class GameScene : public cocos2d::Layer
{
public:
    virtual bool init();

    CREATE_FUNC(GameScene);

    // setup entities
    void setCharacterByEntityType(EntityType entityType);
    void setFriendCharacter(EntityType entityType);
    void setEnemyByEntityType(EntityType entityType);

    // networking
    void setNetworkedSession(bool networkedSession);
    void receivedData(const void* data, unsigned long length);

private:
    bool networkedSession;
    GameState gameState;

    cocos2d::Sprite* background;
    cocos2d::Sprite* field;

    Entity* character;
    Entity* friendCharacter;
    Entity* enemy;
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
