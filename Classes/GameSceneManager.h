//
//  GameSceneManager.h
//  Tetrominos
//
//  Created by ryutamaki on 2015/07/01.
//
//

#ifndef __Tetrominos___GameSceneManager__
#define __Tetrominos___GameSceneManager__

#include "cocos2d.h"
#include "NetworkingWrapper.h"

#include "EntityConstants.h"

class GameScene;

class GameSceneManager : public NetworkingDelegate
{
public:
    static GameSceneManager* getInstance();

    // scene transitions
    void enterGameScene(EntityType enemyEntityType, bool networked);
    void exitGameScene();

    // networking
    void showPeerList();
    void receiveMultiplayerInvitations();
    void sendData(const void* data, unsigned long length);

    // networking utilities
    std::vector<std::string> getPeerNameList();
    std::string getMyName();
    std::string getHostUserName();
    std::string getUniqueIdentifier();
    bool isHost();

protected:
    std::unique_ptr<NetworkingWrapper> networkingWrapper;
    GameScene* gameScene;

    GameSceneManager();
    ~GameSceneManager();

    void receivedData(const void* data, unsigned long length);
    void stateChanged(ConnectionState state) override;

};

#endif /* defined(__Tetrominos___GameSceneManager__) */
