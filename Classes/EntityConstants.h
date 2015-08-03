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

struct EntityParameter
{
    // FIXME: Do not use unsigned int because ValueMap "=" operator not support it
    int initialHp;
    int attackFactor;
    int velocityFactor;
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
    {EntityType::CIRCLE, {10, 1, 200}},
    {EntityType::TRIANGLE, {200, 1, 250}},
    {EntityType::NONE, {0, 0, 0}},
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

static const std::map<int, EntityParameterMultipler> ENTITY_PARAMETER_MULTIPLER_BY_RANK = {
    {0, {1.0f, 1.0f, 1.0f}},
    {1, {1.2f, 1.2f, 1.2f}},
    {2, {1.5f, 1.5f, 1.5f}},
    {3, {2.0f, 2.0f, 2.0f}},
    {4, {2.5f, 2.5f, 2.5f}},
    {5, {3.0f, 3.0f, 3.0f}},
    {6, {3.5f, 3.5f, 3.5f}},
    {7, {5.0f, 5.0f, 5.0f}},
    {8, {6.0f, 6.0f, 6.0f}},
    {9, {8.0f, 8.0f, 8.0f}},
    {10, {10.0f, 10.0f, 10.0f}},
};

#endif
