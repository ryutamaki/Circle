//
// Circle.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/15.
//
//

#include "Circle.h"

#pragma mark - Public methods

#pragma mark Initializer

bool Circle::init()
{
    if (! Entity::init()) {
        return false;
    }

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("Circle.csb");
    // retain the haracter animation timeline so it doesn't get deallocated
    this->timeline->retain();

    return true;
}

#pragma Override methods

int Circle::getCoinCountToRankUp()
{
    int currentRank = this->getEntityParameterLevel().rank;
    int coinCount = 0;

    coinCount = (currentRank * 10 + 1) * powf(2.0f, static_cast<float>(currentRank)) + 20;
    // 最大桁のみを残して切り捨てる
    int digit = static_cast<int>(log10(static_cast<double>(coinCount)) + 1);
    coinCount = coinCount - coinCount % static_cast<int>(pow(10, digit - 1));
    return MAX(1, coinCount);
}

int Circle::getCoinCountToHpLevelUp()
{
    int currentHp = this->getEntityParameterLevel().hp;
    int coinCount = 0;

    coinCount = ceil(currentHp / 5.0f);
    return coinCount;
}

int Circle::getCoinCountToAttackLevelUp()
{
    int currentAttack = this->getEntityParameterLevel().attack;
    int coinCount = 0;

    coinCount = ceil(currentAttack / 3.0f);
    return coinCount;
}

#pragma mark - Protected methods

#pragma mark Override methods

void Circle::setupEntityParamerterByLevel(struct EntityParameterLevel parameterLevel)
{
    EntityParameter initialParameter = ENTITY_INITIAL_PARAMETER.at(EntityType::CIRCLE);
    EntityParameterMultipler parameterMultipler = ENTITY_PARAMETER_MULTIPLER_BY_RANK.at(parameterLevel.rank);

    this->entityParameter = {
        static_cast<int>(initialParameter.initialHp + parameterLevel.hp * parameterMultipler.hp * 5),
        static_cast<int>(initialParameter.attackFactor + parameterLevel.attack * parameterMultipler.attack * 1),
    };
}
