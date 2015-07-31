//
// StageComponentReader.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/26.
//
//

#include "StageComponentReader.h"
#include "StageComponent.h"

using namespace cocos2d;

static StageComponentReader* _instanceStageComponentReader = nullptr;

StageComponentReader* StageComponentReader::getInstance()
{
    if (! _instanceStageComponentReader) {
        _instanceStageComponentReader = new StageComponentReader();
    }
    return _instanceStageComponentReader;
}

void StageComponentReader::purge()
{
    CC_SAFE_DELETE(_instanceStageComponentReader);
}

Node* StageComponentReader::createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions)
{
    StageComponent* node = StageComponent::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
