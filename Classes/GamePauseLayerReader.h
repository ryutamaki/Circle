//
//  GamePauseLayerReader.h
//  DotWar
//
//  Created by ryutamaki on 2015/07/31.
//
//

#ifndef __DotWar__GamePauseLayerReader__
#define __DotWar__GamePauseLayerReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class GamePauseLayerReader : public cocostudio::NodeReader {
public:
    static GamePauseLayerReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* defined(__DotWar__GamePauseLayer__) */
