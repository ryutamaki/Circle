//
// PowerUpScene.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/30.
//
//

#include "PowerUpScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "Entity.h"
#include "EntityFactory.h"

#include "UserDataManager.h"

USING_NS_CC;

#pragma mark - Public methods

#pragma mark Initializer

bool PowerUpScene::init()
{
    if (! Layer::init()) {
        return false;
    }

    auto rootNode = CSLoader::createNode("PowerUpScene.csb");

    Size visibleSize = Director::getInstance()->getVisibleSize();
    rootNode->setContentSize(visibleSize);
    ui::Helper::doLayout(rootNode);

    this->field = rootNode->getChildByName<Sprite*>("Field");
    this->entityType = EntityType::NONE;
    this->coinCount = UserDataManager::getInstance()->getCoinCount();

    this->setupUI(rootNode);
    this->addChild(rootNode);

    return true;
}

#pragma mark Accessor

void PowerUpScene::setEntityType(EntityType entityType)
{
    this->entityType = entityType;

    Entity* entity = EntityFactory::createUserEntity(this->entityType);
    this->entityLevelParameter = entity->getEntityLevelParameter();

    this->setEntityLevelParameterLabelText(this->entityLevelParameter);
}

#pragma mark - Private methods

#pragma mark View lifecycle

void PowerUpScene::onEnter()
{
    Layer::onEnter();

    // TODO: field should be a custom object
    float fieldScaleFactor = 1.0f;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Size fieldSize = this->field->getContentSize();

    fieldScaleFactor = MIN(visibleSize.height / fieldSize.height, visibleSize.width / fieldSize.width);
    this->field->setScale(fieldScaleFactor);

    CCASSERT(this->entityType != EntityType::NONE, "You MUST set entityType before onEnter().");
}

void PowerUpScene::setupUI(Node* rootNode)
{
    this->hpLabel = rootNode->getChildByName<ui::TextBMFont*>("HpLabel");
    this->attackLabel = rootNode->getChildByName<ui::TextBMFont*>("AttackLabel");
    this->speedLabel = rootNode->getChildByName<ui::TextBMFont*>("SpeedLabel");

    this->coinCountLabel = rootNode->getChildByName<ui::TextBMFont*>("CoinCountLabel");
    this->setCoinCountLabelText(this->coinCount);

    ui::Button* hpButton = rootNode->getChildByName<ui::Button*>("HpButton");
    hpButton->addTouchEventListener([this](Ref* pRef, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            if (this->canUseCoin(1)) {
                this->entityLevelParameter.levelHp++;
                UserDataManager::getInstance()->setEntityLevelParameter(this->entityType, this->entityLevelParameter);
                this->setEntityLevelParameterLabelText(this->entityLevelParameter);

                // TODO: magic number
                this->useCoin(1);
            }
        }
    });

    ui::Button* attackButton = rootNode->getChildByName<ui::Button*>("AttackButton");
    attackButton->addTouchEventListener([this](Ref* pRef, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            if (this->canUseCoin(1)) {
                this->entityLevelParameter.levelAttack++;
                UserDataManager::getInstance()->setEntityLevelParameter(this->entityType, this->entityLevelParameter);
                this->setEntityLevelParameterLabelText(this->entityLevelParameter);

                // TODO: magic number
                this->useCoin(1);
            }
        }
    });

    ui::Button* speedButton = rootNode->getChildByName<ui::Button*>("SpeedButton");
    speedButton->addTouchEventListener([this](Ref* pRef, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            if (this->canUseCoin(1)) {
                this->entityLevelParameter.levelSpeed++;
                UserDataManager::getInstance()->setEntityLevelParameter(this->entityType, this->entityLevelParameter);
                this->setEntityLevelParameterLabelText(this->entityLevelParameter);

                // TODO: magic number
                this->useCoin(1);
            }
        }
    });

    ui::Button* backButton = rootNode->getChildByName<ui::Button*>("BackButton");
    backButton->addTouchEventListener([this](Ref* pRef, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            Director::getInstance()->popScene();
        }
    });
}

bool PowerUpScene::canUseCoin(int useCoinCount)
{
    if (this->coinCount - useCoinCount < 0) {
        return false;
    }
    return true;
}

void PowerUpScene::useCoin(int useCoinCount)
{
    CCASSERT(this->coinCount - useCoinCount >= 0, "You can not use coin because your coin count is not enough");

    int newCoinCount = this->coinCount - useCoinCount;
    this->coinCount = newCoinCount;
    UserDataManager::getInstance()->setCoinCount(newCoinCount);

    this->setCoinCountLabelText(newCoinCount);
}

void PowerUpScene::setCoinCountLabelText(int coinCount)
{
    this->coinCountLabel->setString(std::to_string(coinCount));
}

void PowerUpScene::setEntityLevelParameterLabelText(EntityLevelParameter entityLevelParameter)
{
    this->hpLabel->setString(std::to_string(entityLevelParameter.levelHp));
    this->attackLabel->setString(std::to_string(entityLevelParameter.levelAttack));
    this->speedLabel->setString(std::to_string(entityLevelParameter.levelSpeed));
}
