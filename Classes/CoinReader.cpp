//
//  CoinReader.cpp
//  DotWar
//
//  Created by ryutamaki on 2015/07/27.
//
//

#include "CoinReader.h"
#include "Coin.h"

using namespace cocos2d;

static CoinReader* _instanceCoinReader = nullptr;

CoinReader* CoinReader::getInstance() {
    if (!_instanceCoinReader) {
        _instanceCoinReader = new CoinReader();
    }
    return _instanceCoinReader;
}

void CoinReader::purge() {
    CC_SAFE_DELETE(_instanceCoinReader);
}

Node* CoinReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    Coin* node = Coin::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
