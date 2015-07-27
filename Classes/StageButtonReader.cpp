//
//  StageButtonReader.cpp
//  DotWar
//
//  Created by ryutamaki on 2015/07/26.
//
//

#include "StageButtonReader.h"
#include "StageButton.h"

using namespace cocos2d;

static StageButtonReader* _instanceStageButtonReader = nullptr;

StageButtonReader* StageButtonReader::getInstance() {
    if (!_instanceStageButtonReader) {
        _instanceStageButtonReader = new StageButtonReader();
    }
    return _instanceStageButtonReader;
}

void StageButtonReader::purge() {
    CC_SAFE_DELETE(_instanceStageButtonReader);
}

Node* StageButtonReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    StageButton* node = StageButton::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
