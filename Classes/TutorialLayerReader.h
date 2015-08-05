//
//  TutorialLayerReader.h
//  DotWar
//
//  Created by ryutamaki on 2015/08/05.
//
//

#ifndef __DotWar__TutorialLayerReader__
#define __DotWar__TutorialLayerReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class TutorialLayerReader : public cocostudio::NodeReader {
public:
    static TutorialLayerReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* defined(__DotWar__TutorialLayer__) */
