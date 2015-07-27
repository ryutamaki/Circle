//
// CoinContainer.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/27.
//
//

#include "CoinContainer.h"

#include "CoinReader.h"

#pragma mark - Public methods

#pragma mark Constructor and Destructor

CoinContainer::CoinContainer()
{
    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("CoinReader", (ObjectFactory::Instance)CoinReader::getInstance);

    this->currentCoinCacheIndex = 0;
    this->coinCache = Vector<Coin*>();

    for (int i = 0; i < 100; ++i) {
        Coin* coin = dynamic_cast<Coin*>(CSLoader::createNode("Coin.csb"));
        this->coinCache.pushBack(coin);
    }
}

CoinContainer::~CoinContainer()
{
}

#pragma mark Logic

Coin* CoinContainer::fetchCoin()
{
    ++this->currentCoinCacheIndex;

    if (this->currentCoinCacheIndex >= this->coinCache.size()) {
        this->currentCoinCacheIndex = 0;
    }

    return this->coinCache.at(this->currentCoinCacheIndex);
}
