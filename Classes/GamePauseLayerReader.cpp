//
//  GamePauseLayerReader.cpp
//  DotWar
//
//  Created by ryutamaki on 2015/07/31.
//
//

#include "GamePauseLayerReader.h"
#include "GamePauseLayer.h"

using namespace cocos2d;

static GamePauseLayerReader* _instanceGamePauseLayerReader = nullptr;

GamePauseLayerReader* GamePauseLayerReader::getInstance() {
    if (!_instanceGamePauseLayerReader) {
        _instanceGamePauseLayerReader = new GamePauseLayerReader();
    }
    return _instanceGamePauseLayerReader;
}

void GamePauseLayerReader::purge() {
    CC_SAFE_DELETE(_instanceGamePauseLayerReader);
}

Node* GamePauseLayerReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    GamePauseLayer* node = GamePauseLayer::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
