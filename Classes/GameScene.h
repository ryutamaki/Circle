#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "CocosGUI.h"

#include "EntityConstants.h"

#include "Entity.h"
#include "EntityContainer.h"
#include "EntityFactory.h"
#include "CoinContainer.h"

class EntityAI;
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
    int totalCoinCount;
    cocos2d::ui::Button* lobbyButton;
    cocos2d::ui::Button* pauseButton;

    std::unique_ptr<CoinContainer> coinContainer;

    std::unique_ptr<EntityFactory> entityFactory;
    std::unique_ptr<EntityContainer> entityContainer;
    Entity* character;
    Entity* friendCharacter;
    EntityType enemyEntityType;
    int defeatEnemyCount;
    int nextEnemyIndex;
    cocos2d::Vec2 nextEnemyInitialPosition;

    void onEnter() override;
    void setupTouchHandling();

    // game logic
    void update(float dt) override;

    void damageEnemyFromCharacter();
    void damageCharacterFromEntity();

    EntityAI* attachAI(Entity* entity);
    EntityParameterLevel enemyParameterLevel(int nextEnemyIndex);
    void spawnNextEnemy(float dt);
    void checkDeadEnemy(float dt);
    void gameover();
    void checkGameOver();
    void giveCoin(int coinCount);

    // transitions
    void showTutorialBasicIfNeverSeen();
    void showPauseLayer();
    void showResultLayer(int score, int highscore, bool isNewRecord, int coinCount);

    void readyToStart(Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void tryToStart();
    void start();

};

#endif // __GAME_SCENE_H__
