//
// EntityFactory.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/26.
//
//

#include "EntityFactory.h"

#include "UserDataManager.h"

#include "Circle.h"
#include "CircleReader.h"
#include "CircleAI.h"
#include "Triangle.h"
#include "TriangleReader.h"
#include "TriangleAI.h"

#pragma mark - Public methods

#pragma mark Constructor and Destructor

EntityFactory::EntityFactory()
    : enemyIdentifier(ENEMY_INITIAL_IDENTIFIER)
{
}

EntityFactory::~EntityFactory()
{
}

#pragma mark Factory methods

Entity* EntityFactory::createFriend(bool isHost, EntityType entityType, EntityParameterLevel parameterLevel)
{
    std::map<std::string, EntityAttackParams> attackMap = {
        {"Attack",		 {1, EntityAttackType::NORMAL, ""										  }},
        {"ChargeAttack", {3, EntityAttackType::CHARGE, "Particles/Circle_ChargeAttack_Smoke.plist"}},
    };

    return this->createFriend(isHost, entityType, parameterLevel, attackMap);
}

Entity* EntityFactory::createFriend(bool isHost, EntityType entityType, EntityParameterLevel parameterLevel, std::map<std::string, EntityAttackParams> attackMap)
{
    EntityIdentifier identifier;
    Color4B initialColor;

    // MARK: 二人までしか入れないと思ってる
    if (isHost) {
        identifier = ENTITY_HOST_PLAYER_IDENTIFIER;
        initialColor = CIRCLE_LIGHT_BLUE;
    } else {
        identifier = ENTITY_BUDDY_PLAYER_IDENTIFIER;
        // TODO: change the color
        initialColor = CIRCLE_LIGHT_YELLOW;
    }

    return this->gen(
        identifier,
        entityType,
        parameterLevel,
        attackMap,
        initialColor
    );
}

Entity* EntityFactory::createEnemy(EntityType entityType, EntityParameterLevel parameterLevel)
{
    std::map<std::string, EntityAttackParams> attackMap = {
        {"EnemyAttack",	 {1, EntityAttackType::NORMAL, ""										  }},
        {"ChargeAttack", {4, EntityAttackType::CHARGE, "Particles/Circle_ChargeAttack_Smoke.plist"}}
    };
    return this->createEnemy(entityType, parameterLevel, attackMap);
}

Entity* EntityFactory::createEnemy(EntityType entityType, int enemyIndex)
{
    EntityParameterLevel parameterLevel;

    switch (entityType) {
        case EntityType::CIRCLE:
        {
            int maxRank = EntityHelper::getMaxRank();
            int rank = MIN(static_cast<int>(floor(enemyIndex / 10.0f)), maxRank);
            int hpLevel = enemyIndex;
            int attackLevel = enemyIndex;

            parameterLevel = {rank, hpLevel, attackLevel};
            break;
        }

        case EntityType::TRIANGLE:
        {
            int maxRank = EntityHelper::getMaxRank();
            int rank = MIN(static_cast<int>(floor(enemyIndex / 10.0f)), maxRank);
            int hpLevel = enemyIndex + 40;
            int attackLevel = enemyIndex + 20;

            parameterLevel = {rank, hpLevel, attackLevel};
            break;
        }

        default:
        {
            CCASSERT(false, "Undefined entity type is passed.");
            break;
        }
    }
    return this->createEnemy(entityType, parameterLevel);
}

Entity* EntityFactory::createEnemy(EntityType entityType, EntityParameterLevel parameterLevel, std::map<std::string, EntityAttackParams> attackMap)
{
    Color4B initialColor = CIRCLE_LIGHT_RED;
    Entity* entity = this->gen(
            this->enemyIdentifier,
            entityType,
            parameterLevel,
            attackMap,
            initialColor
        );
    this->enemyIdentifier++;
    return entity;
}

EntityAI* EntityFactory::createAI(Entity* entity, Vector<Entity*> opponents)
{
    EntityType entityType = entity->getEntityType();
    switch (entityType) {
        case EntityType::CIRCLE:
        {
            CircleAI* circleAI = CircleAI::create(entity, opponents);
            return circleAI;
        }

        case EntityType::TRIANGLE:
        {
            TriangleAI* triangleAI = TriangleAI::create(entity, opponents);
            return triangleAI;
        }

        case EntityType::NONE:
        {
            return nullptr;
        }
    }

    CCASSERT(false, "Undefined entity type is passed.");
}

#pragma mark - Private methods

Entity* EntityFactory::gen(
    EntityIdentifier identifier,
    EntityType entityType,
    EntityParameterLevel parameterLevel,
    std::map<std::string, EntityAttackParams> attackMap,
    Color4B initialColor
)
{
    CSLoader* instance = CSLoader::getInstance();
    switch (entityType) {
        case EntityType::CIRCLE:
        {
            instance->registReaderObject("CircleReader", (ObjectFactory::Instance)CircleReader::getInstance);
            Circle* circle = dynamic_cast<Circle*>(CSLoader::createNode("Circle.csb"));
            circle->setEntityType(entityType);
            circle->setEntityParameterLevel(parameterLevel);
            circle->setAttackMap(attackMap);
            circle->setInitialColor(initialColor);
            circle->setIdentifier(identifier);
            return circle;
        }

        case EntityType::TRIANGLE:
        {
            instance->registReaderObject("TriangleReader", (ObjectFactory::Instance)TriangleReader::getInstance);
            Triangle* triangle = dynamic_cast<Triangle*>(CSLoader::createNode("Triangle.csb"));
            triangle->setEntityType(entityType);
            triangle->setEntityParameterLevel(parameterLevel);
            triangle->setAttackMap(attackMap);
            triangle->setInitialColor(initialColor);
            triangle->setIdentifier(identifier);
            return triangle;
        }

        case EntityType::NONE:
        {
            return nullptr;
        }
    }

    CCASSERT(false, "Undefined entity type is passed.");
}
