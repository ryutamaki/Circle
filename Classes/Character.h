//
//  Character.h
//  DotWar
//
//  Created by ryutamaki on 2015/07/15.
//
//

#ifndef __DotWar__Character__
#define __DotWar__Character__

#include "cocos2d.h"
#include "EntityConstants.h"

#include "Entity.h"

class Character : public Entity
{
public:
    CREATE_FUNC(Character);
    bool init() override;

    void setMoveStateByStartPositionAndCurrentPosition(Vec2 startPosition, Vec2 currentPosition);

private:
    void onEnter() override;

};

#endif /* defined(__DotWar__Character__) */
