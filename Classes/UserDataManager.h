//
// UserDataManager.h
// DotWar
//
// Created by ryutamaki on 2015/07/28.
//
//

#ifndef __DotWar__UserDataManager__
#define __DotWar__UserDataManager__

#include "cocos2d.h"

#include "EntityConstants.h"

static const std::string USER_DATA_COIN_COUNT = "CoinCount";
static const std::string USER_DATA_HIGHSCORE = "HighScore";
static const std::string USER_DATA_ENTITY_PARAMETER = "EntityParameter";

class UserDataManager
{
public:
    static UserDataManager* getInstance();

    void load();
    bool save();

    void setCoinCount(int coinCount);
    int getCoinCount();

    void setHighScoreByEntityType(int highScore, EntityType entityType);
    int getHighScoreByEntityType(EntityType entityType);

    void setEntityParameterLevel(EntityType entityType, EntityParameterLevel EntityParameterLevel);
    EntityParameterLevel getEntityParameterLevel(EntityType entityType);

private:
    UserDataManager();
    ~UserDataManager();

    cocos2d::ValueMap userData;

    std::string getFilePath();
    std::string getEntityTypeStringByEntityType(EntityType entityType);
};

#endif /* defined(__DotWar__UserDataManager__) */
