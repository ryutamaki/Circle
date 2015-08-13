//
// Triangle.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/15.
//
//

#include "Triangle.h"

using namespace cocostudio::timeline;

#pragma mark - Public methods

#pragma mark Initializer

bool Triangle::init()
{
    if (! Entity::init()) {
        return false;
    }

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("Triangle.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->timeline->retain();

    return true;
}

#pragma mark Override methods

int Triangle::getCoinCountDropped()
{
    return (this->getEntityParameterLevel().rank + 1) * 2;
}

int Triangle::getCoinCountToRankUp()
{
    int currentRank = this->getEntityParameterLevel().rank;
    int coinCount = 0;

    coinCount = 10 * powf(2.0f, static_cast<float>(currentRank));
    return coinCount;
}

int Triangle::getCoinCountToHpLevelUp()
{
    int currentHp = this->getEntityParameterLevel().hp;
    int coinCount = 0;

    coinCount = 2 * powf(2.0f, static_cast<float>(currentHp));
    return coinCount;
}

int Triangle::getCoinCountToAttackLevelUp()
{
    int currentAttack = this->getEntityParameterLevel().attack;
    int coinCount = 0;

    coinCount = 2 * powf(2.0f, static_cast<float>(currentAttack));
    return coinCount;
}

std::vector<Rect> Triangle::getRectsUseForAttackInWorldSpace()
{
    std::vector<Rect> returnRects;
    Vector<Node*> children = this->getChildren();

    for (int i = 0, last = (int)children.size(); i < last; ++i) {
        Sprite* sprite = dynamic_cast<Sprite*>(children.at(i));

        if (! sprite || ! sprite->isVisible()) {
            continue;
        }

        // TODO: ひどいけど便利
        if (this->getCurrentAttackName() == "ChargeAttack") {
            if (sprite->getName() == "Body") {
                continue;
            }
        }

        Size size = sprite->getContentSize();
        float scaleX = sprite->getScaleX();
        float scaleY = sprite->getScaleY();
        Vec2 spritePositionInWorld = this->convertToWorldSpace(sprite->getPosition());

        Rect spriteRect = Rect(
                spritePositionInWorld.x - size.width * sprite->getAnchorPoint().x * scaleX,
                spritePositionInWorld.y - size.height * sprite->getAnchorPoint().y * scaleY,
                size.width * scaleX, size.height * scaleY
            );
        returnRects.push_back(spriteRect);
    }

    return returnRects;
}

#pragma mark - Protected methods

#pragma mark Override methods

void Triangle::setupEntityParamerterByLevel(struct EntityParameterLevel parameterLevel)
{
    EntityParameter initialParameter = ENTITY_INITIAL_PARAMETER.at(EntityType::TRIANGLE);
    EntityParameterMultipler parameterMultipler = ENTITY_PARAMETER_MULTIPLER_BY_RANK.at(parameterLevel.rank);

    this->entityParameter = {
        static_cast<int>(initialParameter.initialHp + parameterLevel.hp * parameterMultipler.hp * 5),
        static_cast<int>(initialParameter.attackFactor + parameterLevel.attack * parameterMultipler.attack * 1),
    };
}
