//
// EntityContainer.cpp
// DotWar
//
// Created by ryutamaki on 2015/08/07.
//
//

#include "EntityContainer.h"

#pragma mark - Public methods

#pragma mark Constructor and Destructor

EntityContainer::EntityContainer()
{
}

EntityContainer::~EntityContainer()
{
}

Entity* EntityContainer::findEntity(EntityIdentifier identifier)
{
    Entity* entity = nullptr;
    entity = this->findFriend(identifier);

    if (entity != nullptr) {
        return entity;
    }

    entity = this->findEnemy(identifier);

    if (entity != nullptr) {
        return entity;
    }
    return nullptr;
}

Entity* EntityContainer::findMyself()
{
    for (auto& kv : this->friends) {
        Entity* entity = static_cast<Entity*>(kv.second);

        if (entity->synchronizer->getIsMyself()) {
            return entity;
        }
    }

    return nullptr;
}

void EntityContainer::addFriend(EntityIdentifier identifier, Entity* entity)
{
}

void EntityContainer::addEnemy(EntityIdentifier identifier, Entity* entity)
{
}

void EntityContainer::moveEnemyToCemetery(EntityIdentifier identifier)
{
}

#pragma mark - Private methods

Entity* EntityContainer::findFriend(EntityIdentifier identifier)
{
    if (this->friends.count(identifier) == 0) {
        return nullptr;
    }
    auto it = this->friends.find(identifier);
    Entity* entity = static_cast<Entity*>(it->second);

    return entity;
}

Entity* EntityContainer::findEnemy(EntityIdentifier identifier)
{
    if (this->enemies.count(identifier) == 0) {
        return nullptr;
    }

    auto it = this->enemies.find(identifier);
    Entity* entity = static_cast<Entity*>(it->second);

    return entity;
}
