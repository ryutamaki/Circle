//
// EntitySynchronizer.h
// DotWar
//
// Created by ryutamaki on 2015/07/22.
//
//

#ifndef __DotWar__EntitySynchronizer__
#define __DotWar__EntitySynchronizer__

#include "cocos2d.h"

#include "JSONPacker.h"

class EntitySynchronizer
{
public:
    EntitySynchronizer();
    ~EntitySynchronizer();

    // Accessor
    bool getIsHost();
    void setIsHost(bool isHost);
    bool getIsMyself();
    void setIsMyself(bool isMyself);
    bool getIsSendData();
    void setIsSendData(bool isSendData);

    // logic
    void sendData(JSONPacker::EntityState entityState);
    void sendDataIfNotHost(JSONPacker::EntityState entityState);

private:
    // The entity which has this object acts as a host or not.
    // If single player mode, the player should be the host.
    bool isHost;
    // The entity which has this object is myself or not.
    bool isMyself;
    // THIS IS EXPLICIT CHECK
    // Does this object should send data or not.
    bool isSendData;

    // THIS IS IMPLICIT CHECK
    // Check whether this object should send passed data or not
    bool checkDataShouldBeSent(JSONPacker::EntityState entityState);
};

#endif /* defined(__DotWar__EntitySynchronizer__) */
