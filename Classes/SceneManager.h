//
//  SceneManager.h
//  Tetrominos
//
//  Created by ryutamaki on 2015/07/01.
//
//

#ifndef __Tetrominos___SceneManager__
#define __Tetrominos___SceneManager__

#include "cocos2d.h"
#include "NetworkingWrapper.h"

#include "EntityConstants.h"

class GameScene;

class SceneManager : public NetworkingDelegate
{
public:
    static SceneManager* getInstance();

    void enterGameScene(EntityType enemyEntityType, bool networked);
    void exitGameScene();
    void showPeerList();
    void receiveMultiplayerInvitations();
    void sendData(const void* data, unsigned long length);

    std::vector<std::string> getPeerNameList();
    std::string getMyName();
    std::string getHostUserName();
    std::string getUniqueIdentifier();
    bool isHost();

protected:
    std::unique_ptr<NetworkingWrapper> networkingWrapper;
    GameScene* gameScene;

    SceneManager();
    ~SceneManager();

    void receivedData(const void* data, unsigned long length);
    void stateChanged(ConnectionState state) override;

};

#endif /* defined(__Tetrominos___SceneManager__) */
