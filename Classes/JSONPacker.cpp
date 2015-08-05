//
// JSONPacker.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/15.
//
//

#include "JSONPacker.h"

#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"

USING_NS_CC;

namespace JSONPacker {
EntityState unpackEntityStateJSON(std::string json)
{
    rapidjson::Document document;
    document.Parse<0>(json.c_str());

    EntityState entityState;

    entityState.identifier = document["identifier"].GetString();
    entityState.hp = document["hp"].GetInt();

    rapidjson::Value& positionJson = document["position"];
    Vec2 position;
    position.x = positionJson["x"].GetDouble();
    position.y = positionJson["y"].GetDouble();
    entityState.position = position;

    entityState.moveState = static_cast<EntityMoveState>(document["moveState"].GetInt());
    entityState.attackState = static_cast<EntityAttackState>(document["attackState"].GetInt());

    rapidjson::Value& damageJson = document["damage"];
    EntityState::Damage damage;
    damage.identifier = damageJson["identifier"].GetString();
    damage.volume = damageJson["volume"].GetInt();
    entityState.damage = damage;

    return entityState;
}

std::string packEntityState(const EntityState entityState)
{
    rapidjson::Document document;
    document.SetObject();

    document.AddMember("identifier", entityState.identifier.c_str(), document.GetAllocator());
    document.AddMember("hp", entityState.hp, document.GetAllocator());

    Vec2 position = entityState.position;
    rapidjson::Value positionJson(rapidjson::kObjectType);
    positionJson.AddMember("x", position.x, document.GetAllocator());
    positionJson.AddMember("y", position.y, document.GetAllocator());
    document.AddMember("position", positionJson, document.GetAllocator());

    document.AddMember("moveState", static_cast<int>(entityState.moveState), document.GetAllocator());
    document.AddMember("attackState", static_cast<int>(entityState.attackState), document.GetAllocator());

    EntityState::Damage damage = entityState.damage;
    rapidjson::Value damageJson(rapidjson::kObjectType);
    damageJson.AddMember("identifier", damage.identifier.c_str(), document.GetAllocator());
    damageJson.AddMember("volume", damage.volume, document.GetAllocator());
    document.AddMember("damage", damageJson, document.GetAllocator());

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);

    std::string returnString(buffer.GetString(), buffer.Size());
    return returnString;
}

EntityReadyState unpackEntityReadyStateJSON(std::string json)
{
    rapidjson::Document document;
    document.Parse<0>(json.c_str());

    EntityReadyState entityReadyState;

    entityReadyState.identifier = document["identifier"].GetString();
    entityReadyState.isReady = document["isReady"].GetBool();
    entityReadyState.entityType = static_cast<EntityType>(document["entityType"].GetInt());

    rapidjson::Value& parameterLevelJson = document["parameterLevel"];
    EntityParameterLevel parameterLevel;
    parameterLevel.rank = parameterLevelJson["rank"].GetInt();
    parameterLevel.hp = parameterLevelJson["hp"].GetInt();
    parameterLevel.attack = parameterLevelJson["attack"].GetInt();
    parameterLevel.speed = parameterLevelJson["speed"].GetInt();
    entityReadyState.parameterLevel = parameterLevel;

    return entityReadyState;
}

std::string packEntityReadyState(const EntityReadyState entityReadyState)
{
    rapidjson::Document document;
    document.SetObject();

    document.AddMember("identifier", entityReadyState.identifier.c_str(), document.GetAllocator());
    document.AddMember("isReady", entityReadyState.isReady, document.GetAllocator());
    document.AddMember("entityType", static_cast<int>(entityReadyState.entityType), document.GetAllocator());

    EntityParameterLevel parameterLevel = entityReadyState.parameterLevel;
    rapidjson::Value parameterLevelJson(rapidjson::kObjectType);
    parameterLevelJson.AddMember("rank", parameterLevel.rank, document.GetAllocator());
    parameterLevelJson.AddMember("hp", parameterLevel.hp, document.GetAllocator());
    parameterLevelJson.AddMember("attack", parameterLevel.attack, document.GetAllocator());
    parameterLevelJson.AddMember("speed", parameterLevel.speed, document.GetAllocator());
    document.AddMember("parameterLevel", parameterLevelJson, document.GetAllocator());

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);

    std::string returnString(buffer.GetString(), buffer.Size());
    return returnString;
}
}
