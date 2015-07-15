//
//  Character.cpp
//  DotWar
//
//  Created by ryutamaki on 2015/07/15.
//
//

#include "Character.h"

bool Character::init() {
    if (!Node::init()) {
        return false;
    }

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("Character.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->timeline->retain();

    return true;
}
