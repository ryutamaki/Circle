//
//  PowerUpButtonReader.cpp
//  Circle
//
//  Created by ryutamaki on 2015/08/13.
//
//

#include "PowerUpButtonReader.h"
#include "PowerUpButton.h"

using namespace cocos2d;

static PowerUpButtonReader* _instancePowerUpButtonReader = nullptr;

PowerUpButtonReader* PowerUpButtonReader::getInstance() {
    if (!_instancePowerUpButtonReader) {
        _instancePowerUpButtonReader = new PowerUpButtonReader();
    }
    return _instancePowerUpButtonReader;
}

void PowerUpButtonReader::purge() {
    CC_SAFE_DELETE(_instancePowerUpButtonReader);
}

Node* PowerUpButtonReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    PowerUpButton* node = PowerUpButton::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
