//
//  GameResultLayer.h
//  DotWar
//
//  Created by ryutamaki on 2015/07/27.
//
//

#ifndef __DotWar__GameResultLayer__
#define __DotWar__GameResultLayer__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

#include "PluginChartboost/PluginChartboost.h"

class Entity;

class GameResultLayer : public cocos2d::Layer, public sdkbox::ChartboostListener {
public:
    CREATE_FUNC(GameResultLayer);
    bool init() override;

    void setScore(int score);
    void setHighScore(int highScore);
    void setIsNewRecord(bool isNewRecord);
    void setCoinCount(int coinCount);
    void setNetworked(bool networked);
    void setEntityType(EntityType entityType);

    void show(Node* parent);
    void hide(std::function<void()> lastFrameCallback);

    // chartboost
    void onChartboostCached(const std::string& name);
    bool onChartboostShouldDisplay(const std::string& name);
    void onChartboostDisplay(const std::string& name);
    void onChartboostDismiss(const std::string& name);
    void onChartboostClose(const std::string& name);
    void onChartboostClick(const std::string& name);
    void onChartboostReward(const std::string& name, int reward);
    void onChartboostFailedToLoad(const std::string& name, sdkbox::CB_LoadError e);
    void onChartboostFailToRecordClick(const std::string& name, sdkbox::CB_ClickError e);
    void onChartboostConfirmation();
    void onChartboostCompleteStore();

private:
    cocostudio::timeline::ActionTimeline* timeline;

    cocos2d::ui::Layout* resultLayout;

    int score;
    int highScore;
    bool isNewRecord;
    int coinCount;
    bool networked;
    EntityType entityType;

    void onEnter() override;
    void onExit() override;

    void setupButtons();
    void setupPowerUpButtonNotifier();
    void setupLabels();

};

#endif /* defined(__DotWar__GameResultLayer__) */
