//
//  ScoreLabelReader.cpp
//  DotWar
//
//  Created by ryutamaki on 2015/07/28.
//
//

#include "ScoreLabelReader.h"
#include "ScoreLabel.h"

using namespace cocos2d;

static ScoreLabelReader* _instanceScoreLabelReader = nullptr;

ScoreLabelReader* ScoreLabelReader::getInstance() {
    if (!_instanceScoreLabelReader) {
        _instanceScoreLabelReader = new ScoreLabelReader();
    }
    return _instanceScoreLabelReader;
}

void ScoreLabelReader::purge() {
    CC_SAFE_DELETE(_instanceScoreLabelReader);
}

Node* ScoreLabelReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    ScoreLabel* node = ScoreLabel::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
