//
//  CoinLabelReader.h
//  DotWar
//
//  Created by ryutamaki on 2015/08/09.
//
//

#ifndef __DotWar__CoinLabelReader__
#define __DotWar__CoinLabelReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class CoinLabelReader : public cocostudio::NodeReader {
public:
    static CoinLabelReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* defined(__DotWar__CoinLabel__) */
