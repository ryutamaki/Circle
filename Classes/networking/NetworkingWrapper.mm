//
// NetworkingWrapper.cpp
// Doodler
//
// Created by Daniel Haaser on 5/25/15.
//
//

#include "NetworkingWrapper.h"
#include "NetworkManager.h"
#pragma mark -
#pragma mark Lifecycle

NetworkingWrapper::NetworkingWrapper()
{
    this->networkManager = [[NetworkManager alloc] init];
    [this->networkManager setDelegate: this];
    [networkManager retain];
}

NetworkingWrapper::~NetworkingWrapper()
{
    [networkManager release];
    networkManager = nil;
}

#pragma mark -
#pragma mark Public Methods

void NetworkingWrapper::setDelegate(NetworkingDelegate* delegate)
{
    this->delegate = delegate;
}

void NetworkingWrapper::startAdvertisingAvailability()
{
    [this->networkManager startAdvertisingAvailability];
}

void NetworkingWrapper::stopAdvertisingAvailability()
{
    [this->networkManager stopAdvertisingAvailability];
}

void NetworkingWrapper::showPeerList()
{
    [this->networkManager showPeerList];
}

std::string NetworkingWrapper::getMyPeerId()
{
    NSString* myPeerIdObjcString = [this->networkManager getMyPeerId];
    std::string myPeerId = std::string([myPeerIdObjcString UTF8String]);
    return myPeerId;
}

std::vector<std::string> NetworkingWrapper::getPeerList()
{
    NSArray* peerList = [this->networkManager getPeerList];

    std::vector<std::string> returnVector;

    for (NSString* peerName in peerList) {
        std::string peerString = std::string([peerName UTF8String]);
        returnVector.push_back(peerString);
    }

    return returnVector;
}

void NetworkingWrapper::sendData(const void* data, unsigned long length)
{
    NSData* dataToSend = [NSData dataWithBytes:data length:length];
    [this->networkManager sendData: dataToSend];
}

void NetworkingWrapper::disconnect()
{
    [this->networkManager disconnect];
}

const std::string NetworkingWrapper::getDeviceName()
{
    NSString* deviceName = [UIDevice currentDevice].name;
    return std::string([deviceName UTF8String]);
}

const std::string NetworkingWrapper::getUUID()
{
    NSString* uuid = [UIDevice currentDevice].identifierForVendor.UUIDString;
    return std::string([uuid UTF8String]);
}

const std::string NetworkingWrapper::getUniqueIdentifier()
{
    std::string deviceName = NetworkingWrapper::getDeviceName();
    std::string uuid = NetworkingWrapper::getUUID();

    return deviceName + uuid;
}

#pragma mark -
#pragma mark NetworkManager Delegate Methods

void NetworkingWrapper::receivedData(const void* data, unsigned long length)
{
    if (this->delegate) {
        this->delegate->receivedData(data, length);
    }
}

void NetworkingWrapper::stateChanged(ConnectionState state)
{
    if (this->delegate) {
        this->delegate->stateChanged(state);
    }
}
