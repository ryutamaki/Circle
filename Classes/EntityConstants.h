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

static const std::map<int, std::string> ENTITY_RANK_SYMBOL_PATH = {
    {0, ""},
    {1, ""},
    {2, ""},
    {3, ""},
    {4, ""},
    {5, ""},
    {6, ""},
    {7, ""},
    {8, ""},
    {9, ""},
    {10, ""},
};

struct EntityParameterLevel
{
    // FIXME: Do not use unsigned int because ValueMap "=" operator not support it
    int rank;
    int hp;
    int attack;
    int speed;
};

struct EntityParameterMultipler
{
    float hp;
    float attack;
    float speed;
};

static const std::map<EntityType, EntityParameterLevel> ENTITY_INITIAL_LEVEL_PARAMETER = {
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
