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
#include "Triangle.h"
#include "TriangleReader.h"

#pragma mark - Public methods

#pragma mark Constructor and Destructor

EntityFactory::EntityFactory()
    : identifier(0)
{
}

EntityFactory::~EntityFactory()
{
}

#pragma mark Factory methods

Entity* EntityFactory::createEntity(EntityType entityType)
{
    EntityParameterLevel parameterLevel = {1, 1, 1};
    return EntityFactory::createEntity(entityType, parameterLevel);
}

Entity* EntityFactory::createEntity(EntityType entityType, EntityParameterLevel parameterLevel)
{
    std::map<std::string, EntityAttackParams> attackMap = {
        {"Attack",		 {1, EntityAttackType::NORMAL, ""										  }},
        {"ChargeAttack", {5, EntityAttackType::CHARGE, "Particles/Circle_ChargeAttack_Smoke.plist"}},
    };
    return this->createEntity(entityType, parameterLevel, attackMap);
}

Entity* EntityFactory::createEntity(EntityType entityType, EntityParameterLevel parameterLevel, std::map<std::string, EntityAttackParams> attackMap)
{
    Color4B initialColor = CIRCLE_LIGHT_BLUE;
    return this->createEntity(entityType, parameterLevel, attackMap, initialColor);
}

Entity* EntityFactory::createEntity(EntityType entityType, EntityParameterLevel parameterLevel, std::map<std::string, EntityAttackParams> attackMap, Color4B initialColor)
{
    this->identifier++;
    log("%d", this->identifier);

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
            circle->setIdentifier(this->identifier);
            return circle;
        }

        case EntityType::NONE:
        {
            return nullptr;
        }
    }

    CCASSERT(false, "Undefined entity type is passed.");
}
