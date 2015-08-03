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
            return circle;
        }

        case EntityType::TRIANGLE:
        {
            instance->registReaderObject("TriangleReader", (ObjectFactory::Instance)TriangleReader::getInstance);
            Triangle* triangle = dynamic_cast<Triangle*>(CSLoader::createNode("Triangle.csb"));
            EntityParameterLevel parameter = UserDataManager::getInstance()->getEntityParameterLevel(entityType);
            triangle->setEntityParameterLevel(parameter);
            return triangle;
        }

        case EntityType::NONE:
        {
            return nullptr;
        }
    }

    CCASSERT(false, "Undefined entity type is passed.");
}

Entity* EntityFactory::createEntity(EntityType entityType)
{
    unsigned int defeatCount = 0;
    return EntityFactory::createEntity(entityType, defeatCount);
}

Entity* EntityFactory::createEntity(EntityType entityType, unsigned int defeatCount)
{
    Color4B initialColor = CIRCLE_DARK_BLUE;
    return EntityFactory::createEntity(entityType, defeatCount, initialColor);
}

Entity* EntityFactory::createEntity(EntityType entityType, unsigned int defeatCount, cocos2d::Color4B initialColor)
{
    CSLoader* instance = CSLoader::getInstance();
    switch (entityType) {
        case EntityType::CIRCLE:
        {
            instance->registReaderObject("CircleReader", (ObjectFactory::Instance)CircleReader::getInstance);
            Circle* circle = dynamic_cast<Circle*>(CSLoader::createNode("Circle.csb"));
            EntityParameterLevel parameterLevel = ENTITY_INITIAL_LEVEL_PARAMETER.at(entityType);
            // TODO: magic number and game logic here
            parameterLevel.rank += floor(defeatCount / 10);
            parameterLevel.hp += defeatCount;
            parameterLevel.attack += defeatCount;
            parameterLevel.speed += defeatCount * 1;
            circle->setEntityParameterLevel(parameterLevel);
            circle->setInitialColor(initialColor);
            return circle;
        }

        case EntityType::TRIANGLE:
        {
            instance->registReaderObject("TriangleReader", (ObjectFactory::Instance)TriangleReader::getInstance);
            Triangle* triangle = dynamic_cast<Triangle*>(CSLoader::createNode("Triangle.csb"));
            EntityParameterLevel parameterLevel = ENTITY_INITIAL_LEVEL_PARAMETER.at(entityType);
            // TODO: magic number and game logic here
            parameterLevel.rank += floor(defeatCount / 10);
            parameterLevel.hp += defeatCount;
            parameterLevel.attack += defeatCount;
            parameterLevel.speed += defeatCount * 1;
            triangle->setEntityParameterLevel(parameterLevel);
            triangle->setInitialColor(initialColor);
            return triangle;
        }

        case EntityType::NONE:
        {
            return nullptr;
        }
    }

    CCASSERT(false, "Undefined entity type is passed.");
}
