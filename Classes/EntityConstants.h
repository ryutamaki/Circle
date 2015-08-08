//
// EntityConstants.h
// DotWar
//
// Created by ryutamaki on 2015/07/15.
//
//

#ifndef DotWar_EntityConstants_h
#define DotWar_EntityConstants_h

static const float ENTITY_CHARGE_START_DURATION = 0.1f;
static const float ENTITY_VELOCITY_FACTOR = 400.0f;

// TODO: These parameters should be attached to ATTACK
// キャラクターのサイズが 80x80 なので、だいたい distance * duration が 80 くらいになるといいかも
static const float ENTITY_KNOCKBACK_DURATION = 0.1f;
static const float ENTITY_KNOCKBACK_DISTANCE_PER_SEC = 800.0f;
static const bool ENTITY_KNOCKBACK_CANCEL_ATTACK = false;

typedef unsigned int EntityIdentifier;

enum class EntityType
{
    CIRCLE = 0,
//    TRIANGLE,
    NONE, // This is not good way but I dont no some of better way.
};

enum class EntityAttackType
{
    NORMAL,
    CHARGE,
};

struct EntityAttackParams {
    int damageFactor;
    EntityAttackType attackType;
    std::string particleFilePath;
};

struct EntityParameter
{
    // FIXME: I do not use unsigned int because ValueMap "=" operator not support it
    int initialHp;
    int attackFactor;
};

struct EntityParameterLevel
{
    // FIXME: I do not use unsigned int because ValueMap "=" operator not support it
    int rank;
    int hp;
    int attack;
};

struct EntityParameterMultipler
{
    float hp;
    float attack;
};

static const std::map<EntityType, EntityParameterLevel> ENTITY_INITIAL_LEVEL_PARAMETER = {
    // {EntityType, {rank, hp, attack}}
    {EntityType::CIRCLE, {0, 1, 1}},
//    {EntityType::TRIANGLE, {1, 1, 1}},
    {EntityType::NONE, {0, 0, 0}},
};

static const std::map<EntityType, EntityParameter> ENTITY_INITIAL_PARAMETER = {
    {EntityType::CIRCLE, {10, 1}},
//    {EntityType::TRIANGLE, {200, 1}},
    {EntityType::NONE, {0, 0}},
};

static const std::map<int, std::string> ENTITY_RANK_SYMBOL_PATH = {
    {0, ""},
    {1, "Rank/Rank1@2x.png"},
    {2, "Rank/Rank2@2x.png"},
    {3, "Rank/Rank3@2x.png"},
    {4, "Rank/Rank4@2x.png"},
    {5, "Rank/Rank5@2x.png"},
    {6, "Rank/Rank6@2x.png"},
    {7, "Rank/Rank7@2x.png"},
    {8, "Rank/Rank8@2x.png"},
    {9, "Rank/Rank9@2x.png"},
    {10, ""},
};

static const std::map<int, EntityParameterMultipler> ENTITY_PARAMETER_MULTIPLER_BY_RANK = {
    {0, {1.0f, 1.0f}},
    {1, {1.2f, 1.2f}},
    {2, {1.5f, 1.5f}},
    {3, {2.0f, 2.0f}},
    {4, {2.5f, 2.5f}},
    {5, {3.0f, 3.0f}},
    {6, {3.5f, 3.5f}},
    {7, {5.0f, 5.0f}},
    {8, {6.0f, 6.0f}},
    {9, {8.0f, 8.0f}},
    {10, {10.0f, 10.0f}},
};

#endif
