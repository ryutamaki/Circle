//
//  GameResultLayerReader.h
//  DotWar
//
//  Created by ryutamaki on 2015/07/27.
//
//

#ifndef __DotWar__GameResultLayerReader__
#define __DotWar__GameResultLayerReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class GameResultLayerReader : public cocostudio::NodeReader {
public:
    static GameResultLayerReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* defined(__DotWar__GameResultLayer__) */
