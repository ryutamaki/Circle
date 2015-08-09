//
// CoinLabel.cpp
// DotWar
//
// Created by ryutamaki on 2015/08/09.
//
//

#include "CoinLabel.h"

#include "UserDataManager.h"

#pragma mark - Public methods

bool CoinLabel::init()
{
    if (! Node::init()) {
        return false;
    }

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("CoinLabel.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->timeline->retain();

    this->coinCount = UserDataManager::getInstance()->getCoinCount();

    return true;
}

#pragma mark Accessor

void CoinLabel::setCoinCount(int coinCount)
{
    this->coinCount = coinCount;
    this->coinLabel->setString(std::to_string(this->coinCount));
}

#pragma mark - Private methods

#pragma mark View lifecycle

void CoinLabel::onEnter()
{
    Node::onEnter();

    this->runAction(this->timeline);

    this->coinLabel = this->getChildByName<ui::TextBMFont*>("CoinLabel");

    this->setCoinCount(this->coinCount);
}

void CoinLabel::onExit()
{
    Node::onExit();

    this->stopAllActions();
}
