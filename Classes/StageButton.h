//
//  StageButton.h
//  DotWar
//
//  Created by ryutamaki on 2015/07/26.
//
//

#ifndef __DotWar__StageButton__
#define __DotWar__StageButton__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

#include "EntityConstants.h"

class StageButton : public cocos2d::Node {
public:
    CREATE_FUNC(StageButton);
    bool init() override;

    void setEntityType(EntityType entityType);
    EntityType getEntityType();

protected:
    cocostudio::timeline::ActionTimeline* timeline;

    EntityType entityType;

    void onEnter() override;

    void attachEntity(EntityType entityType);
    void attachHighScoreLabel();

};

#endif /* defined(__DotWar__StageButton__) */
