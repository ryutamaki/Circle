//
// FlurryHelper.cpp
// DotWar
//
// Created by ryutamaki on 2015/08/10.
//
//

#include "FlurryHelper.h"
#include "PluginFlurryAnalytics/PluginFlurryAnalytics.h"

namespace FlurryHelper {
void logTransitionScene(std::string toScene)
{
    std::map<std::string, std::string> scenes = {
        {"To Scene", toScene},
    };

    sdkbox::PluginFlurryAnalytics::logEvent("Scene", scenes);
}

void logGameResult(bool isSinglePlayerMode, bool abandon, int score, int coinEarned, int totalCoin)
{
    std::map<std::string, std::string> params = {
        {"Game Mode",	isSinglePlayerMode ? "Single Player" : "Multiplayer"},
        {"Abandon",		abandon ? "true" : "false"							},
        {"Score",		StringUtils::toString(score)						},
        {"Coin Earned", StringUtils::toString(coinEarned)					},
        {"Total Coin",	StringUtils::toString(totalCoin)					},
    };

    sdkbox::PluginFlurryAnalytics::logEvent("Game Result", params);
}

void logPowerUp(std::string targetStatus, int rank, int hpLevel, int attackLevel, int coinUsed, int coinRemaining)
{
    std::map<std::string, std::string> params = {
        {"Target Status",  targetStatus						   },
        {"Rank",		   StringUtils::toString(rank)		   },
        {"HP Level",	   StringUtils::toString(hpLevel)	   },
        {"Attack Level",   StringUtils::toString(attackLevel)  },
        {"Coin Used",	   StringUtils::toString(coinUsed)	   },
        {"Coin Remaining", StringUtils::toString(coinRemaining)},
    };

    sdkbox::PluginFlurryAnalytics::logEvent("Power Up", params);
}
}
