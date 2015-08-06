//
// GameConstants.h
// DotWar
//
// Created by ryutamaki on 2015/07/17.
//
//

#ifndef DotWar_GameConstants_h
#define DotWar_GameConstants_h

#include "cocos2d.h"
#include "EntityConstants.h"

static const float SCENE_TRANSITION_DURATION = 0.3f;
static const Color3B SCENE_TRANSITION_COLOR = Color3B(CIRCLE_GRAY);

static const float BATTLE_FIELD_FRAME_THICKNESS = 5.0f;

static const float SENSITIVITY_TO_CONTROL_PLAYER = 10.0f;

static const float INITIAL_ENEMY_SPAWN_DURATION = 5.0f;

enum class GameState
{
    PREPARE,
    PLAYING,
    RESULT,
};

#endif /* ifndef DotWar_GameConstants_h */
