//
// CircleReader.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/15.
//
//

#include "CircleReader.h"
#include "Circle.h"

using namespace cocos2d;

static CircleReader* _instanceCircleReader = nullptr;

CircleReader* CircleReader::getInstance()
{
    if (! _instanceCircleReader) {
        _instanceCircleReader = new CircleReader();
    }
    return _instanceCircleReader;
}

void CircleReader::purge()
{
    CC_SAFE_DELETE(_instanceCircleReader);
}

Node* CircleReader::createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions)
{
    Circle* node = Circle::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
