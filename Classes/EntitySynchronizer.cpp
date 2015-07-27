//
// EntitySynchronizer.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/22.
//
//

#include "EntitySynchronizer.h"

#include "GameSceneManager.h"

#pragma mark - Public methods

#pragma mark constructor and destructor

EntitySynchronizer::EntitySynchronizer()
{
    // This setting is for single player mode
    this->isReadyToPlay = false;
    this->isHost = true;
    this->isMyself = true;
    this->isSendData = false;
}

EntitySynchronizer::~EntitySynchronizer()
{
}

#pragma mark Accessor

bool EntitySynchronizer::getIsReadyToPlay()
{
    return this->isReadyToPlay;
}

void EntitySynchronizer::setIsReadyToPlay(bool isReadyToPlay)
{
    this->isReadyToPlay = isReadyToPlay;
}

bool EntitySynchronizer::getIsHost()
{
    return this->isHost;
}

void EntitySynchronizer::setIsHost(bool isHost)
{
    this->isHost = isHost;
}

bool EntitySynchronizer::getIsMyself()
{
    return this->isMyself;
}

void EntitySynchronizer::setIsMyself(bool isMyself)
{
    this->isMyself = isMyself;
}

bool EntitySynchronizer::getIsSendData()
{
    return this->isSendData;
}

void EntitySynchronizer::setIsSendData(bool isSendData)
{
    this->isSendData = isSendData;
}

#pragma mark Logic

void EntitySynchronizer::sendData(JSONPacker::EntityState entityState)
{
    // check explicit
    if (! this->getIsSendData()) {
        return;
    }

    if (! this->checkDataShouldBeSent(entityState)) {
        return;
    }

    std::string json = JSONPacker::packEntityState(entityState);
    GameSceneManager::getInstance()->sendData(json.c_str(), json.length());
}

void EntitySynchronizer::sendData(JSONPacker::EntityReadyState entityReadyState)
{
    std::string json = JSONPacker::packEntityReadyState(entityReadyState);
    GameSceneManager::getInstance()->sendData(json.c_str(), json.length());
}

void EntitySynchronizer::sendDataIfNotHost(JSONPacker::EntityState entityState)
{
    // check explicit
    if (! this->getIsSendData()) {
        return;
    }

    // Dont send if this is host
    if (this->getIsHost()) {
        return;
    }

    std::string json = JSONPacker::packEntityState(entityState);
    GameSceneManager::getInstance()->sendData(json.c_str(), json.length());
}

#pragma mark - Private methods

bool EntitySynchronizer::checkDataShouldBeSent(JSONPacker::EntityState entityState)
{
    // Do some implicit data check here

    // Dont send attack state is not ready

    return true;
}
