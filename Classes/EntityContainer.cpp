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

#pragma mark Accessor

std::map<EntityIdentifier, Entity*> EntityContainer::getAllEnemies()
{
    return this->enemies;
}

#pragma mark Find

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

EntityAI* EntityContainer::findAi(EntityIdentifier identifier)
{
    if (this->aiList.count(identifier) == 0) {
        return nullptr;
    }

    auto it = this->aiList.find(identifier);
    EntityAI* ai = static_cast<EntityAI*>(it->second);

    return ai;
}

#pragma mark Add

void EntityContainer::addFriend(EntityIdentifier identifier, Entity* entity)
{
    std::pair<EntityIdentifier, Entity*> entityPair(identifier, entity);
    this->friends.insert(entityPair);
}

void EntityContainer::addEnemy(EntityIdentifier identifier, Entity* entity)
{
    std::pair<EntityIdentifier, Entity*> entityPair(identifier, entity);
    this->enemies.insert(entityPair);
}

void EntityContainer::addAi(EntityIdentifier identifier, EntityAI* ai)
{
    std::pair<EntityIdentifier, EntityAI*> aiPair(identifier, ai);
    this->aiList.insert(aiPair);
}

#pragma mark Move

void EntityContainer::moveEnemyToCemetery(EntityIdentifier identifier)
{
    Entity* target = this->findEnemy(identifier);

    if (target == nullptr) {
        return;
    }

    std::map<EntityIdentifier, Entity*>::iterator it = this->enemies.find(identifier);

    this->cemetery.insert(std::pair<EntityIdentifier, Entity*>(identifier, target));
    this->enemies.erase(it);

    EntityAI* ai = this->findAi(identifier);

    if (ai) {
        ai->stop();
        ai->removeFromParent();
    }
}

#pragma mark Pause and Resume

void EntityContainer::pauseAllEntity()
{
    // pause all friends
    for (auto& kv : this->friends) {
        Entity* entity = static_cast<Entity*>(kv.second);
        entity->pause();
    }

    // pause all enemies
    for (auto& kv : this->enemies) {
        Entity* entity = static_cast<Entity*>(kv.second);
        entity->pause();
    }

    // pause all ai
    for (auto& kv : this->aiList) {
        EntityAI* ai = static_cast<EntityAI*>(kv.second);
        ai->stop();
    }
}

void EntityContainer::resumeAllEntity()
{
    // resume all friends
    for (auto& kv : this->friends) {
        Entity* entity = static_cast<Entity*>(kv.second);
        entity->resume();
    }

    // resume all enemies
    for (auto& kv : this->enemies) {
        Entity* entity = static_cast<Entity*>(kv.second);
        entity->resume();
    }

    // resume all ai
    for (auto& kv : this->aiList) {
        EntityAI* ai = static_cast<EntityAI*>(kv.second);
        ai->start();
    }
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
