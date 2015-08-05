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

    this->entityType = EntityType::NONE;
    this->coinCount = UserDataManager::getInstance()->getCoinCount();

    auto rootNode = CSLoader::createNode("PowerUpScene.csb");

    Size visibleSize = Director::getInstance()->getVisibleSize();
    rootNode->setContentSize(visibleSize);
    ui::Helper::doLayout(rootNode);

    this->addChild(rootNode);

    ui::Layout* rankPanel = rootNode->getChildByName<ui::Layout*>("RankComponent");
    ui::Layout* hpPanel = rootNode->getChildByName<ui::Layout*>("HpComponent");
    ui::Layout* attackPanel = rootNode->getChildByName<ui::Layout*>("AttackComponent");
    ui::Layout* speedPanel = rootNode->getChildByName<ui::Layout*>("SpeedComponent");
    ui::Layout* coinPanel = rootNode->getChildByName<ui::Layout*>("CoinComponent");

    this->rankLabel = rankPanel->getChildByName<ui::TextBMFont*>("RankLevelLabel");
    this->hpLabel = hpPanel->getChildByName<ui::TextBMFont*>("HpLevelLabel");
    this->attackLabel = attackPanel->getChildByName<ui::TextBMFont*>("AttackLevelLabel");
    this->speedLabel = speedPanel->getChildByName<ui::TextBMFont*>("SpeedLevelLabel");
    this->coinCountLabel = coinPanel->getChildByName<ui::TextBMFont*>("CoinCountLabel");

    this->rankButton = rankPanel->getChildByName<ui::Button*>("RankUpButton");
    this->hpButton = hpPanel->getChildByName<ui::Button*>("HpLevelUpButton");
    this->attackButton = attackPanel->getChildByName<ui::Button*>("AttackLevelUpButton");
    this->speedButton = speedPanel->getChildByName<ui::Button*>("SpeedLevelUpButton");

    ui::Button* backButton = rootNode->getChildByName<ui::Button*>("BackButton");
    backButton->addTouchEventListener([this](Ref* pRef, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            Director::getInstance()->popScene();
        }
    });

    return true;
}

#pragma mark Accessor

void PowerUpScene::setEntityType(EntityType entityType)
{
    this->entityType = entityType;

    Entity* entity = EntityFactory::createUserEntity(this->entityType);

    this->entityParameterLevel = entity->getEntityParameterLevel();
    this->setEntityParameterLevelLabelText(this->entityParameterLevel);
}

#pragma mark - Private methods

#pragma mark View lifecycle

void PowerUpScene::onEnter()
{
    Layer::onEnter();

    // TODO: Bad code. It depends on state of an instance
    CCASSERT(this->entityType != EntityType::NONE, "You MUST set entityType before onEnter().");

    this->setupUI();
}

void PowerUpScene::setupUI()
{
    this->setCoinCountLabelText(this->coinCount);

    if (! EntityHelper::isNextRankExists(this->entityParameterLevel.rank)) {
        rankButton->setEnabled(false);
    }
    this->rankButton->addTouchEventListener([this](Ref* pRef, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            if (this->canUseCoin(1)) {
                this->entityParameterLevel.rank++;
                UserDataManager::getInstance()->setEntityParameterLevel(this->entityType, this->entityParameterLevel);
                this->setEntityParameterLevelLabelText(this->entityParameterLevel);

                // TODO: magic number
                this->useCoin(1);

                if (! EntityHelper::isNextRankExists(this->entityParameterLevel.rank)) {
                    rankButton->setEnabled(false);
                }
            }
        }
    });

    this->hpButton->addTouchEventListener([this](Ref* pRef, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            if (this->canUseCoin(1)) {
                this->entityParameterLevel.hp++;
                UserDataManager::getInstance()->setEntityParameterLevel(this->entityType, this->entityParameterLevel);
                this->setEntityParameterLevelLabelText(this->entityParameterLevel);

                // TODO: magic number
                this->useCoin(1);
            }
        }
    });

    this->attackButton->addTouchEventListener([this](Ref* pRef, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            if (this->canUseCoin(1)) {
                this->entityParameterLevel.attack++;
                UserDataManager::getInstance()->setEntityParameterLevel(this->entityType, this->entityParameterLevel);
                this->setEntityParameterLevelLabelText(this->entityParameterLevel);

                // TODO: magic number
                this->useCoin(1);
            }
        }
    });

    this->speedButton->addTouchEventListener([this](Ref* pRef, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            if (this->canUseCoin(1)) {
                this->entityParameterLevel.speed++;
                UserDataManager::getInstance()->setEntityParameterLevel(this->entityType, this->entityParameterLevel);
                this->setEntityParameterLevelLabelText(this->entityParameterLevel);

                // TODO: magic number
                this->useCoin(1);
            }
        }
    });
}

void PowerUpScene::setCoinCountLabelText(int coinCount)
{
    this->coinCountLabel->setString(std::to_string(coinCount));
}

void PowerUpScene::setEntityParameterLevelLabelText(struct EntityParameterLevel entityParameterLevel)
{
    this->entityParameterLevel = entityParameterLevel;

    this->rankLabel->setString(std::to_string(entityParameterLevel.rank));
    this->hpLabel->setString(std::to_string(entityParameterLevel.hp));
    this->attackLabel->setString(std::to_string(entityParameterLevel.attack));
    this->speedLabel->setString(std::to_string(entityParameterLevel.speed));
}

#pragma mark Logic

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
