//
// UserDataManager.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/28.
//
//

#include "UserDataManager.h"

USING_NS_CC;

#pragma mark - Public methods

static UserDataManager* sharedUserDataManager;
UserDataManager* UserDataManager::getInstance()
{
    if (! sharedUserDataManager) {
        sharedUserDataManager = new UserDataManager();
    }

    return sharedUserDataManager;
}

#pragma mark Constructor and Destructor

UserDataManager::UserDataManager()
{
}

UserDataManager::~UserDataManager()
{
}

void UserDataManager::load()
{
    std::string path = this->getFilePath();

    if (! FileUtils::getInstance()->isFileExist(path)) {
        this->userData = ValueMap();
    } else {
        this->userData = FileUtils::getInstance()->getValueMapFromFile(path);
    }
}

bool UserDataManager::save()
{
    std::string path = this->getFilePath();

    if (FileUtils::getInstance()->writeToFile(this->userData, path)) {
        CCLOG("Save Success");
        return true;
    } else {
        CCLOG("Save Failed");
        return false;
    }
}

#pragma mark Accessor

void UserDataManager::setHighScoreByEntityType(int highScore, EntityType entityType)
{
    int currentHighScore = this->getHighScoreByEntityType(entityType);

    if (highScore < currentHighScore) {
        return;
    }

    ValueMap highScoreMap;

    if (this->userData.find(USER_DATA_HIGHSCORE) == this->userData.end()) {
        highScoreMap = ValueMap();
    } else {
        highScoreMap = this->userData[USER_DATA_HIGHSCORE].asValueMap();
    }

    std::string entityTypeString = std::to_string((int)entityType);
    highScoreMap[entityTypeString] = highScore;
    this->userData[USER_DATA_HIGHSCORE] = highScoreMap;

    this->save();
}

int UserDataManager::getHighScoreByEntityType(EntityType entityType)
{
    this->load();

    if (this->userData.find(USER_DATA_HIGHSCORE) == this->userData.end()) {
        int initialHighScore = 0;
        return initialHighScore;
    }

    std::string entityTypeString = std::to_string((int)entityType);
    ValueMap highScoreMap = this->userData[USER_DATA_HIGHSCORE].asValueMap();
    int highScore = highScoreMap[entityTypeString].asInt();

    return highScore;
}

#pragma mark - Private methods

#pragma mark Utility

std::string UserDataManager::getFilePath()
{
    return FileUtils::getInstance()->getWritablePath() + "user_data";
}
