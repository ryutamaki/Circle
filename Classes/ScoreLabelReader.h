//
//  ScoreLabelReader.h
//  DotWar
//
//  Created by ryutamaki on 2015/07/28.
//
//

#ifndef __DotWar__ScoreLabelReader__
#define __DotWar__ScoreLabelReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class ScoreLabelReader : public cocostudio::NodeReader {
public:
    static ScoreLabelReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* defined(__DotWar__ScoreLabel__) */
