//
// Coin.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/27.
//
//

#include "Coin.h"

bool Coin::init()
{
    if (! Node::init()) {
        return false;
    }

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("Coin.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->timeline->retain();

    return true;
}

#pragma mark - Private methods

#pragma mark View lifecycle

void Coin::onEnter()
{
    Node::onEnter();

    this->setRotation(CCRANDOM_MINUS1_1() * 180);

    this->runAction(this->timeline);
    this->timeline->play("Drop", false);
    this->timeline->setLastFrameCallFunc([this]() {
        this->removeFromParent();
    });
}

void Coin::onExit()
{
    Node::onExit();

    this->stopAllActions();
}
