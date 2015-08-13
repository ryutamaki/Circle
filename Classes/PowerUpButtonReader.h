//
//  PowerUpButtonReader.h
//  Circle
//
//  Created by ryutamaki on 2015/08/13.
//
//

#ifndef __Circle__PowerUpButtonReader__
#define __Circle__PowerUpButtonReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class PowerUpButtonReader : public cocostudio::NodeReader {
public:
    static PowerUpButtonReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* defined(__Circle__PowerUpButton__) */
