//
// EntityConstants.h
// DotWar
//
// Created by ryutamaki on 2015/07/15.
//
//

#ifndef DotWar_EntityConstants_h
#define DotWar_EntityConstants_h

enum class EntityType
{
    CIRCLE = 0,
    TRIANGLE,
    NONE, // This is not good way but I dont no some of better way.
};

struct EntityLevelParameter
{
    // FIXME: Do not use unsigned int because ValueMap "=" operator not support it
    int rank;
    int hp;
    int attack;
    int speed;
};

struct EntityParameter
{
    // FIXME: Do not use unsigned int because ValueMap "=" operator not support it
    int initialHp;
    int attackFactor;
    int velocityFactor;
};

static const std::map<EntityType, EntityLevelParameter> ENTITY_INITIAL_LEVEL_PARAMETER = {
    // {EntityType, {rank, hp, attack, speed}}
    {EntityType::CIRCLE, {1, 1, 1, 1}},
    {EntityType::TRIANGLE, {1, 1, 1, 1}},
    {EntityType::NONE, {0, 0, 0, 0}},
};

static const std::map<EntityType, EntityParameter> ENTITY_INITIAL_PARAMETER = {
    {EntityType::CIRCLE, {50, 10, 500}},
    {EntityType::TRIANGLE, {100, 1, 150}},
    {EntityType::NONE, {0, 0, 0}},
};

#endif
