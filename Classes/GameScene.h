#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "CocosGUI.h"

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
    void setFriendCharacter(EntityType entityType, EntityParameterLevel parameterLevel);
    void setEnemyEntityType(EntityType entityType);
    EntityType getEnemyEntityType();

    // Pause and Restart
    void pauseGame();
    void resumeGame();

    // networking
    void setNetworkedSession(bool networkedSession);
    void receivedData(const void* data, unsigned long length);
    void disconnected();

private:
    bool networkedSession;
    GameState gameState;
    bool isAttackTouching;
    clock_t touchStartTime;

    cocos2d::Sprite* background;
    cocos2d::Sprite* field;
    ScoreLabel* scoreLabel;
    cocos2d::ui::Button* lobbyButton;
    cocos2d::ui::Button* pauseButton;

    std::unique_ptr<CoinContainer> coinContainer;

    Entity* character;
    Entity* friendCharacter;
    EntityType enemyEntityType;
    std::vector<std::pair<Entity*, EnemyAI*>> aliveEnemyAndAiList;
    cocos2d::Vector<Entity*> deadEnemyList;
    int defeatEnemyCount;
    int nextEnemyIndex;

    void onEnter() override;
    void setupTouchHandling();

    // game logic
    void update(float dt) override;

    void damageEnemyFromCharacter();
    void damageCharacterFromEntity();

    EnemyAI* attachAI(Entity* entity);
    void spawnNextEnemy(float dt);
    void checkDeadEnemy(float dt);
    void gameover();
    void checkGameOver();
    void giveCoin();
    Entity* getTargetEntityByTargetString(std::string targetString);

    // transitions
    void showTutorialBasicIfNeverSeen();
    void showPauseLayer();
    void showResultLayer(int score, int highscore, bool isNewRecord);

    void readyToStart(Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void tryToStart();
    void start();

};

#endif // __GAME_SCENE_H__
