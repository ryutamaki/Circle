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

    entityState.hp = document["hp"].GetInt();

    rapidjson::Value &positionJson = document["position"];
    Vec2 position;
    position.x = positionJson["x"].GetDouble();
    position.y = positionJson["y"].GetDouble();
    entityState.position = position;

    entityState.moveState = (EntityMoveState)document["moveState"].GetInt();
    entityState.attackState = (EntityAttackState)document["attackState"].GetInt();

    return entityState;
}

std::string packEntityState(const EntityState entityState)
{
    rapidjson::Document document;
    document.SetObject();

    document.AddMember("hp", (int)entityState.hp, document.GetAllocator());

    Vec2 position = entityState.position;
    rapidjson::Value positionJson(rapidjson::kObjectType);
    positionJson.AddMember("x", position.x, document.GetAllocator());
    positionJson.AddMember("y", position.y, document.GetAllocator());
    document.AddMember("position", positionJson, document.GetAllocator());

    document.AddMember("moveState", (int)entityState.moveState, document.GetAllocator());
    document.AddMember("attackState", (int)entityState.attackState, document.GetAllocator());

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);

    std::string returnString(buffer.GetString(), buffer.Size());
    return returnString;
}
}
