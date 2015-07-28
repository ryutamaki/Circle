//
// EntityFactory.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/26.
//
//

#include "EntityFactory.h"

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

Entity* EntityFactory::createEntityWithEntityType(EntityType entityType)
{
    CSLoader* instance = CSLoader::getInstance();
    switch (entityType) {
        case EntityType::CIRCLE:
        {
            instance->registReaderObject("CircleReader", (ObjectFactory::Instance)CircleReader::getInstance);
            Circle* circle = dynamic_cast<Circle*>(CSLoader::createNode("Circle.csb"));
            return circle;
        }

        case EntityType::TRIANGLE:
        {
            instance->registReaderObject("TriangleReader", (ObjectFactory::Instance)TriangleReader::getInstance);
            Triangle* triangle = dynamic_cast<Triangle*>(CSLoader::createNode("Triangle.csb"));
            return triangle;
        }

        case EntityType::NONE:
        {
            return nullptr;
        }
    }

    CCASSERT(false, "Undefined entity type is passed.");
}

Vector<Entity*> EntityFactory::createEntityList(int countOfSequence, EntityType entityType)
{
    Vector<Entity*> entityQueue;

    for (int i = 0; i < countOfSequence; ++i) {
        Entity* entity = EntityFactory::createEntityWithEntityType(entityType);
        entityQueue.pushBack(entity);
    }

    return entityQueue;
}
