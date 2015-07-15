//
//  GameConstants.h
//  DotWar
//
//  Created by ryutamaki on 2015/07/15.
//
//

#ifndef DotWar_GameConstants_h
#define DotWar_GameConstants_h

static const float CHARACTER_SPEED = 5.0f;

enum CharacterMoveState
{
    NONE,
    UP,
    UP_LEFT,
    LEFT,
    DOWN_LEFT,
    DOWN,
    DOWN_RIGHT,
    RIGHT,
    UP_RIGHT,
};

#endif
