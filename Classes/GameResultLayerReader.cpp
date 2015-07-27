//
//  GameResultLayerReader.cpp
//  DotWar
//
//  Created by ryutamaki on 2015/07/27.
//
//

#include "GameResultLayerReader.h"
#include "GameResultLayer.h"

using namespace cocos2d;

static GameResultLayerReader* _instanceGameResultLayerReader = nullptr;

GameResultLayerReader* GameResultLayerReader::getInstance() {
    if (!_instanceGameResultLayerReader) {
        _instanceGameResultLayerReader = new GameResultLayerReader();
    }
    return _instanceGameResultLayerReader;
}

void GameResultLayerReader::purge() {
    CC_SAFE_DELETE(_instanceGameResultLayerReader);
}

Node* GameResultLayerReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    GameResultLayer* node = GameResultLayer::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
