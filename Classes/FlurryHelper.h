//
// FlurryHelper.h
// DotWar
//
// Created by ryutamaki on 2015/08/10.
//
//

#ifndef __DotWar__FlurryHelper__
#define __DotWar__FlurryHelper__

#include "cocos2d.h"

namespace FlurryHelper {
    static const std::string SCENE_NAME_MENU = "Menu Scene";
    static const std::string SCENE_NAME_STAGE_SELECT = "Stage Select Scene";
    static const std::string SCENE_NAME_GAME_SINGLE = "[SINGLE] Game Scene";
    static const std::string SCENE_NAME_GAME_MULTI = "[MULTI] Game Scene";
    static const std::string SCENE_NAME_POWERUP = "PowerUp Scene";

    void logTransitionScene(std::string toScene);
    void logGameResult(bool isSinglePlayerMode, bool abandon, int score, int coinEarned, int totalCoin);
    void logPowerUp(std::string targetStatus, int rank, int hpLevel, int attackLevel, int coinUsed, int coinRemaining);

}

#endif /* defined(__DotWar__FlurryHelper__) */
