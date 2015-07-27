//
// GameSceneManager.cpp
// Tetrominos
//
// Created by ryutamaki on 2015/07/01.
//
//

#include "GameSceneManager.h"
#include "MenuScene.h"
#include "GameScene.h"

using namespace cocos2d;

static GameSceneManager* sharedGameSceneManager;

GameSceneManager* GameSceneManager::getInstance()
{
    if (! sharedGameSceneManager) {
        sharedGameSceneManager = new (std::nothrow)GameSceneManager();
    }

    return sharedGameSceneManager;
}

GameSceneManager::GameSceneManager()
{
    this->networkingWrapper = std::unique_ptr<NetworkingWrapper>(new NetworkingWrapper());
    this->networkingWrapper->setDelegate(this);

    this->gameScene = nullptr;
}

GameSceneManager::~GameSceneManager()
{
}

#pragma mark - Public methods

#pragma mark Scene transition methods

void GameSceneManager::enterGameScene(EntityType enemyEntityType, bool networked)
{
    Scene* scene = Scene::create();
    this->gameScene = GameScene::create();
    this->gameScene->setNetworkedSession(networked);
    this->gameScene->setCharacterByEntityType(EntityType::CIRCLE);
    this->gameScene->setEnemyByEntityType(enemyEntityType);

    if (networked) {
        this->gameScene->setFriendCharacter(EntityType::CIRCLE);
    }

    scene->addChild(this->gameScene);
    Director::getInstance()->pushScene(scene);
}

void GameSceneManager::exitGameScene()
{
    if (gameScene) {
        auto menuScene = MenuScene::createScene();
        Director::getInstance()->replaceScene(menuScene);
        this->gameScene = nullptr;
        this->networkingWrapper->disconnect();
    }
}

#pragma mark Networking

void GameSceneManager::showPeerList()
{
    this->networkingWrapper->showPeerList();
}

void GameSceneManager::receiveMultiplayerInvitations()
{
    this->networkingWrapper->startAdvertisingAvailability();
}

void GameSceneManager::sendData(const void* data, unsigned long length)
{
    this->networkingWrapper->sendData(data, length);
}

#pragma mark Networking utilities

std::vector<std::string> GameSceneManager::getPeerNameList()
{
    return this->networkingWrapper->getPeerList();
}

std::string GameSceneManager::getMyName()
{
    return this->networkingWrapper->getMyPeerId();
}

std::string GameSceneManager::getHostUserName()
{
    std::vector<std::string> peerList = this->getPeerNameList();
    peerList.push_back(this->getMyName());
    std::sort(peerList.begin(), peerList.end());
    return peerList[0];
}

std::string GameSceneManager::getUniqueIdentifier()
{
    std::string uniqueIdentifier = this->networkingWrapper->getUniqueIdentifier();
    return uniqueIdentifier;
}

bool GameSceneManager::isHost()
{
    if (this->getMyName().compare(this->getHostUserName()) == 0) {
        return true;
    }
    return false;
}

#pragma mark - Private methods

#pragma mark NetworkingDelegate

void GameSceneManager::receivedData(const void* data, unsigned long length)
{
    if (this->gameScene) {
        this->gameScene->receivedData(data, length);
    }
}

void GameSceneManager::stateChanged(ConnectionState state)
{
    switch (state) {
        case ConnectionState::CONNECTING:
            CCLOG("Connecting...");
            break;

        case ConnectionState::NOT_CONNECTED:
            CCLOG("Not connected...");
            break;

        case ConnectionState::CONNECTED:
            CCLOG("Connected...");

            if (! this->gameScene) {
                this->networkingWrapper->stopAdvertisingAvailability();
                this->enterGameScene(EntityType::TRIANGLE, true);
            }
            break;

        default:
            break;
    }
}
