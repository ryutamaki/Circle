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
#include "TutorialLayer.h"

static const std::string USER_DATA_COIN_COUNT = "CoinCount";
static const std::string USER_DATA_HIGHSCORE = "HighScore";
static const std::string USER_DATA_ENTITY_PARAMETER = "EntityParameter";
static const std::string USER_DATA_IS_SHOWN_TUTORIAL = "IsShownTutorial";

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

    void setIsShownTutorial(TutorialType tutorialType, bool isShown);
    bool getIsShownTutorial(TutorialType tutorialType);

private:
    UserDataManager();
    ~UserDataManager();

    cocos2d::ValueMap userData;

    std::string getFilePath();
    std::string getEntityTypeStringByEntityType(EntityType entityType);
    std::string getTutorialTypeStringByTutorialType(TutorialType tutorialType);
};

#endif /* defined(__DotWar__UserDataManager__) */
