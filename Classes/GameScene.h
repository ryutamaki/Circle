#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "CocosGUI.h"

#include "GameConstants.h"
#include "EntityConstants.h"

#include "Entity.h"
#include "CoinContainer.h"

class EnemyAI;
class ScoreLabel;

class GameScene : public cocos2d::Layer
{
public:
    virtual bool init();

    CREATE_FUNC(GameScene);

    // setup entities
    void setCharacterByEntityType(EntityType entityType);
    void setFriendCharacter(EntityType entityType);
    void setEnemyEntityType(EntityType entityType);

    // networking
    void setNetworkedSession(bool networkedSession);
    void receivedData(const void* data, unsigned long length);

private:
    bool networkedSession;
    GameState gameState;

    cocos2d::Sprite* background;
    cocos2d::Sprite* field;
    ScoreLabel* scoreLabel;

    std::unique_ptr<CoinContainer> coinContainer;

    Entity* character;
    Entity* friendCharacter;
    EntityType enemyEntityType;
    Entity* currentEnemy;
    int defeatEnemyCount;
    EnemyAI* enemyAI;

    void onEnter() override;
    void setupUI();
    void setupTouchHandling();

    // game logic
    void update(float dt) override;

    void damageEnemyFromCharacter();
    void damageCharacterFromEntity();

    void spawnNextEnemy();
    void checkSpawnNextEnemy();
    void gameover(bool isWin);
    void checkGameOver();
    Entity* getTargetEntityByTargetString(std::string targetString);

    // transitions
    void showResultLayer(bool isWin);

    void readyToStart(Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void tryToStart();
    void start();

};

#endif // __GAME_SCENE_H__
