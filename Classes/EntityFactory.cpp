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
{
}

EntityFactory::~EntityFactory()
{
}

#pragma mark Factory methods

Entity* EntityFactory::createUserEntity(EntityType entityType)
{
    CSLoader* instance = CSLoader::getInstance();
    switch (entityType) {
        case EntityType::CIRCLE:
        {
            instance->registReaderObject("CircleReader", (ObjectFactory::Instance)CircleReader::getInstance);
            Circle* circle = dynamic_cast<Circle*>(CSLoader::createNode("Circle.csb"));
            EntityParameterLevel parameter = UserDataManager::getInstance()->getEntityParameterLevel(entityType);
            circle->setEntityParameterLevel(parameter);
            // TODO: この攻撃の設定方法いつかリファクタしたい
            circle->setAttackMap({
                {"Attack", {1, EntityAttackType::NORMAL, ""}},
                {"ChargeAttack", {5, EntityAttackType::CHARGE, "Particles/Circle_ChargeAttack_Smoke.plist"}},
            });
            return circle;
        }

        // case EntityType::TRIANGLE:
        // {
        // instance->registReaderObject("TriangleReader", (ObjectFactory::Instance)TriangleReader::getInstance);
        // Triangle* triangle = dynamic_cast<Triangle*>(CSLoader::createNode("Triangle.csb"));
        // EntityParameterLevel parameter = UserDataManager::getInstance()->getEntityParameterLevel(entityType);
        // triangle->setEntityParameterLevel(parameter);
        //// TODO: この攻撃の設定方法いつかリファクタしたい
        // triangle->setAttackMap({
        // {"Attack", {2, EntityAttackType::NORMAL, ""}},
        // });
        // return triangle;
        // }

        case EntityType::NONE:
        {
            return nullptr;
        }
    }

    CCASSERT(false, "Undefined entity type is passed.");
}

Entity* EntityFactory::createEntity(EntityType entityType)
{
    EntityParameterLevel parameterLevel = {1, 1, 1};
    return EntityFactory::createEntity(entityType, parameterLevel);
}

Entity* EntityFactory::createEntity(EntityType entityType, EntityParameterLevel parameterLevel)
{
    Color4B initialColor = CIRCLE_LIGHT_BLUE;
    return EntityFactory::createEntity(entityType, parameterLevel, initialColor);
}

Entity* EntityFactory::createEntity(EntityType entityType, EntityParameterLevel parameterLevel, Color4B initialColor)
{
    CSLoader* instance = CSLoader::getInstance();
    switch (entityType) {
        case EntityType::CIRCLE:
        {
            instance->registReaderObject("CircleReader", (ObjectFactory::Instance)CircleReader::getInstance);
            Circle* circle = dynamic_cast<Circle*>(CSLoader::createNode("Circle.csb"));
            circle->setEntityType(entityType);
            circle->setEntityParameterLevel(parameterLevel);
            circle->setInitialColor(initialColor);
            // TODO: この攻撃の設定方法いつかリファクタしたい
            circle->setAttackMap({
                {"Attack", {1, EntityAttackType::NORMAL, ""}},
                {"ChargeAttack", {5, EntityAttackType::CHARGE, "Particles/Circle_ChargeAttack_Smoke.plist"}},
            });
            return circle;
        }

        // case EntityType::TRIANGLE:
        // {
        // instance->registReaderObject("TriangleReader", (ObjectFactory::Instance)TriangleReader::getInstance);
        // Triangle* triangle = dynamic_cast<Triangle*>(CSLoader::createNode("Triangle.csb"));
        // triangle->setEntityType(entityType);
        // triangle->setEntityParameterLevel(parameterLevel);
        // triangle->setInitialColor(initialColor);
        //// TODO: この攻撃の設定方法いつかリファクタしたい
        // triangle->setAttackMap({
        // {"Attack", {2, EntityAttackType::NORMAL, ""}},
        // });
        // return triangle;
        // }

        case EntityType::NONE:
        {
            return nullptr;
        }
    }

    CCASSERT(false, "Undefined entity type is passed.");
}
