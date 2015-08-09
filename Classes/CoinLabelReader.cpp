//
//  CoinLabelReader.cpp
//  DotWar
//
//  Created by ryutamaki on 2015/08/09.
//
//

#include "CoinLabelReader.h"
#include "CoinLabel.h"

using namespace cocos2d;

static CoinLabelReader* _instanceCoinLabelReader = nullptr;

CoinLabelReader* CoinLabelReader::getInstance() {
    if (!_instanceCoinLabelReader) {
        _instanceCoinLabelReader = new CoinLabelReader();
    }
    return _instanceCoinLabelReader;
}

void CoinLabelReader::purge() {
    CC_SAFE_DELETE(_instanceCoinLabelReader);
}

Node* CoinLabelReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    CoinLabel* node = CoinLabel::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
