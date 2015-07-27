//
// TriangleReader.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/15.
//
//

#include "TriangleReader.h"
#include "Triangle.h"

using namespace cocos2d;

static TriangleReader* _instanceTriangleReader = nullptr;

TriangleReader* TriangleReader::getInstance()
{
    if (! _instanceTriangleReader) {
        _instanceTriangleReader = new TriangleReader();
    }
    return _instanceTriangleReader;
}

void TriangleReader::purge()
{
    CC_SAFE_DELETE(_instanceTriangleReader);
}

Node* TriangleReader::createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions)
{
    Triangle* node = Triangle::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
