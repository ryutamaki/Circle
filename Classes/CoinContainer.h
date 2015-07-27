//
// CoinContainer.h
// DotWar
//
// Created by ryutamaki on 2015/07/27.
//
//

#ifndef __DotWar__CoinContainer__
#define __DotWar__CoinContainer__

#include "cocos2d.h"

#include "Coin.h"

class CoinContainer
{
public:
    CoinContainer();
    ~CoinContainer();

    Coin* fetchCoin();

private:
    cocos2d::Vector<Coin*> coinCache;
    int currentCoinCacheIndex;
};

#endif /* defined(__DotWar__CoinContainer__) */
