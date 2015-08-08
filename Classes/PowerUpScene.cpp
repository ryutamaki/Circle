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

    this->coinLayout = rootNode->getChildByName<ui::Layout*>("CoinLayout");
    this->rankLayout = rootNode->getChildByName<ui::Layout*>("RankLayout");
    this->hpLayout = rootNode->getChildByName<ui::Layout*>("HpLayout");
    this->attackLayout = rootNode->getChildByName<ui::Layout*>("AttackLayout");

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

    EntityParameterLevel parameterLevel = UserDataManager::getInstance()->getEntityParameterLevel(this->entityType);
    this->setEntity(entityType, parameterLevel.rank);

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

    // Rank
    ui::Button* rankUpButton = this->rankLayout->getChildByName<ui::Button*>("RankUpButton");

    if (EntityHelper::isNextRankExists(this->entityParameterLevel.rank) &&
        this->coinCount >= this->entity->getCoinCountToRankUp()) {
        rankUpButton->addTouchEventListener([this, rankUpButton](Ref* pRef, ui::Widget::TouchEventType eEventType) {
            if (eEventType == ui::Widget::TouchEventType::ENDED) {
                int useCoinCount = this->entity->getCoinCountToRankUp();

                if (this->canUseCoin(useCoinCount)) {
                    this->entityParameterLevel.rank++;
                    UserDataManager::getInstance()->setEntityParameterLevel(this->entityType, this->entityParameterLevel);
                    this->setEntityParameterLevelLabelText(this->entityParameterLevel);
                    this->useCoin(useCoinCount);

                    if (! EntityHelper::isNextRankExists(this->entityParameterLevel.rank) ||
                        this->coinCount < this->entity->getCoinCountToRankUp()) {
                        rankUpButton->setEnabled(false);
                    }
                }
            }
        });
    } else {
        rankUpButton->setEnabled(false);
    }

    // HP
    ui::Button* hpUpButton = this->hpLayout->getChildByName<ui::Button*>("HpUpButton");
    hpUpButton->addTouchEventListener([this](Ref* pRef, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            int useCoinCount = this->entity->getCoinCountToHpLevelUp();

            if (this->canUseCoin(useCoinCount)) {
                this->entityParameterLevel.hp++;
                UserDataManager::getInstance()->setEntityParameterLevel(this->entityType, this->entityParameterLevel);
                this->setEntityParameterLevelLabelText(this->entityParameterLevel);
                this->useCoin(useCoinCount);
            }
        }
    });

    // Attack
    ui::Button* attackUpButton = this->attackLayout->getChildByName<ui::Button*>("AttackUpButton");
    attackUpButton->addTouchEventListener([this](Ref* pRef, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            int useCoinCount = this->entity->getCoinCountToAttackLevelUp();

            if (this->canUseCoin(useCoinCount)) {
                this->entityParameterLevel.attack++;
                UserDataManager::getInstance()->setEntityParameterLevel(this->entityType, this->entityParameterLevel);
                this->setEntityParameterLevelLabelText(this->entityParameterLevel);
                this->useCoin(useCoinCount);
            }
        }
    });
}

#pragma mark Setter

void PowerUpScene::setEntity(EntityType entityType, int rank)
{
    if (this->entity) {
        this->entity->removeFromParent();
        this->entity = nullptr;
    }

    std::unique_ptr<EntityFactory> factory = std::unique_ptr<EntityFactory>(new EntityFactory());
    bool isHost = true;
    this->entity = factory->createFriend(isHost, entityType, this->entityParameterLevel);
    this->entity->setNormalizedPosition(Vec2(0.4, 0.65));
    this->addChild(this->entity);
}

void PowerUpScene::setCoinCountLabelText(int coinCount)
{
    ui::TextBMFont* coinCountLabel = this->coinLayout->getChildByName<ui::TextBMFont*>("CoinCountLabel");
    coinCountLabel->setString(std::to_string(coinCount));
}

void PowerUpScene::setEntityParameterLevelLabelText(struct EntityParameterLevel entityParameterLevel)
{
    this->entityParameterLevel = entityParameterLevel;
    this->setEntity(this->entityType, this->entityParameterLevel.rank);

    // level
    ui::TextBMFont* rankLabel = this->rankLayout->getChildByName<ui::TextBMFont*>("RankLevelLabel");
    ui::TextBMFont* hpLabel = this->hpLayout->getChildByName<ui::TextBMFont*>("HpLevelLabel");
    ui::TextBMFont* attackLabel = this->attackLayout->getChildByName<ui::TextBMFont*>("AttackLevelLabel");

    rankLabel->setString(std::to_string(entityParameterLevel.rank));
    hpLabel->setString(std::to_string(entityParameterLevel.hp));
    attackLabel->setString(std::to_string(entityParameterLevel.attack));

    // need coin count
    ui::TextBMFont* rankUpCoinNeedCountLabel = this->rankLayout->getChildByName<ui::TextBMFont*>("RankUpCoinNeedCountLabel");
    ui::TextBMFont* hpUpCoinNeedCountLabel = this->hpLayout->getChildByName<ui::TextBMFont*>("HpUpCoinNeedCountLabel");
    ui::TextBMFont* attackUpCoinNeedCountLabel = this->attackLayout->getChildByName<ui::TextBMFont*>("AttackUpCoinNeedCountLabel");

    rankUpCoinNeedCountLabel->setString(std::to_string(this->entity->getCoinCountToRankUp()));
    hpUpCoinNeedCountLabel->setString(std::to_string(this->entity->getCoinCountToHpLevelUp()));
    attackUpCoinNeedCountLabel->setString(std::to_string(this->entity->getCoinCountToAttackLevelUp()));
}

#pragma mark Logic

bool PowerUpScene::canUseCoin(int useCoinCount)
{
    if (this->coinCount - useCoinCount >= 0) {
        return true;
    }
    return false;
}

void PowerUpScene::useCoin(int useCoinCount)
{
    CCASSERT(this->coinCount - useCoinCount >= 0, "You can not use coin because your coin count is not enough");

    int newCoinCount = this->coinCount - useCoinCount;
    this->coinCount = newCoinCount;
    UserDataManager::getInstance()->setCoinCount(newCoinCount);

    this->setCoinCountLabelText(newCoinCount);
}
