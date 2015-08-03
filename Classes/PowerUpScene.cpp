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
    this->setEntityParameterLevelLabelText(entity->getEntityParameterLevel());

    this->setEntityParameterLevelLabelText(this->EntityParameterLevel);
}

#pragma mark - Private methods

#pragma mark View lifecycle

void PowerUpScene::onEnter()
{
    Layer::onEnter();

    // TODO: Bad code. It depends on state of an instance
    CCASSERT(this->entityType != EntityType::NONE, "You MUST set entityType before onEnter().");
}

void PowerUpScene::setupUI(Node* rootNode)
{
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
    this->setCoinCountLabelText(this->coinCount);

    ui::Button* rankButton = rankPanel->getChildByName<ui::Button*>("RankUpButton");

    if (! EntityHelper::isNextRankExists(this->EntityParameterLevel.rank)) {
        rankButton->setEnabled(false);
    }
    rankButton->addTouchEventListener([this, rankButton](Ref* pRef, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            if (this->canUseCoin(1)) {
                this->EntityParameterLevel.rank++;
                UserDataManager::getInstance()->setEntityParameterLevel(this->entityType, this->EntityParameterLevel);
                this->setEntityParameterLevelLabelText(this->EntityParameterLevel);

                // TODO: magic number
                this->useCoin(1);

                if (! EntityHelper::isNextRankExists(this->EntityParameterLevel.rank)) {
                    rankButton->setEnabled(false);
                }
            }
        }
    });

    ui::Button* hpButton = hpPanel->getChildByName<ui::Button*>("HpLevelUpButton");
    hpButton->addTouchEventListener([this](Ref* pRef, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            if (this->canUseCoin(1)) {
                this->EntityParameterLevel.hp++;
                UserDataManager::getInstance()->setEntityParameterLevel(this->entityType, this->EntityParameterLevel);
                this->setEntityParameterLevelLabelText(this->EntityParameterLevel);

                // TODO: magic number
                this->useCoin(1);
            }
        }
    });

    ui::Button* attackButton = attackPanel->getChildByName<ui::Button*>("AttackLevelUpButton");
    attackButton->addTouchEventListener([this](Ref* pRef, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            if (this->canUseCoin(1)) {
                this->EntityParameterLevel.attack++;
                UserDataManager::getInstance()->setEntityParameterLevel(this->entityType, this->EntityParameterLevel);
                this->setEntityParameterLevelLabelText(this->EntityParameterLevel);

                // TODO: magic number
                this->useCoin(1);
            }
        }
    });

    ui::Button* speedButton = speedPanel->getChildByName<ui::Button*>("SpeedLevelUpButton");
    speedButton->addTouchEventListener([this](Ref* pRef, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            if (this->canUseCoin(1)) {
                this->EntityParameterLevel.speed++;
                UserDataManager::getInstance()->setEntityParameterLevel(this->entityType, this->EntityParameterLevel);
                this->setEntityParameterLevelLabelText(this->EntityParameterLevel);

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

void PowerUpScene::setCoinCountLabelText(int coinCount)
{
    this->coinCountLabel->setString(std::to_string(coinCount));
}

void PowerUpScene::setEntityParameterLevelLabelText(struct EntityParameterLevel EntityParameterLevel)
{
    this->EntityParameterLevel = EntityParameterLevel;

    this->rankLabel->setString(std::to_string(EntityParameterLevel.rank));
    this->hpLabel->setString(std::to_string(EntityParameterLevel.hp));
    this->attackLabel->setString(std::to_string(EntityParameterLevel.attack));
    this->speedLabel->setString(std::to_string(EntityParameterLevel.speed));
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
