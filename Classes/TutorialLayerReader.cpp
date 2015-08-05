//
//  TutorialLayerReader.cpp
//  DotWar
//
//  Created by ryutamaki on 2015/08/05.
//
//

#include "TutorialLayerReader.h"
#include "TutorialLayer.h"

using namespace cocos2d;

static TutorialLayerReader* _instanceTutorialLayerReader = nullptr;

TutorialLayerReader* TutorialLayerReader::getInstance() {
    if (!_instanceTutorialLayerReader) {
        _instanceTutorialLayerReader = new TutorialLayerReader();
    }
    return _instanceTutorialLayerReader;
}

void TutorialLayerReader::purge() {
    CC_SAFE_DELETE(_instanceTutorialLayerReader);
}

Node* TutorialLayerReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    TutorialLayer* node = TutorialLayer::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
