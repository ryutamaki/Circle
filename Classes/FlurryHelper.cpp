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
}
