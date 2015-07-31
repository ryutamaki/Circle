//
//  StageComponent.h
//  DotWar
//
//  Created by ryutamaki on 2015/07/26.
//
//

#ifndef __DotWar__StageComponent__
#define __DotWar__StageComponent__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

#include "EntityConstants.h"

class StageComponent : public cocos2d::Node {
public:
    CREATE_FUNC(StageComponent);
    bool init() override;

    void setEntityType(EntityType entityType);
    EntityType getEntityType() const;

protected:
    cocostudio::timeline::ActionTimeline* timeline;

    EntityType entityType;

    cocos2d::ui::Layout* componentFrame;

    void onEnter() override;

    void attachEntity(EntityType entityType);
    void attachHighScoreLabel();

};

#endif /* defined(__DotWar__StageComponent__) */
