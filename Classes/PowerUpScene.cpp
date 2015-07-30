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

    this->setupUI(rootNode);
    this->addChild(rootNode);

    return true;
}

#pragma mark Accessor

void PowerUpScene::setEntityType(EntityType entityType)
{
    this->entityType = entityType;

    Entity* entity = EntityFactory::createUserEntityWityEntityType(this->entityType);
    this->entityLevelParameter = entity->getEntityLevelParameter();

    this->setLabelTextByEntityLevelParameter(this->entityLevelParameter);
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

    ui::Button* hpButton = rootNode->getChildByName<ui::Button*>("HpButton");
    hpButton->addTouchEventListener([this](Ref* pRef, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            this->entityLevelParameter.levelHp++;
            UserDataManager::getInstance()->setEntityLevelParameter(this->entityType, this->entityLevelParameter);
            this->setLabelTextByEntityLevelParameter(this->entityLevelParameter);
        }
    });

    ui::Button* attackButton = rootNode->getChildByName<ui::Button*>("AttackButton");
    attackButton->addTouchEventListener([this](Ref* pRef, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            this->entityLevelParameter.levelAttack++;
            UserDataManager::getInstance()->setEntityLevelParameter(this->entityType, this->entityLevelParameter);
            this->setLabelTextByEntityLevelParameter(this->entityLevelParameter);
        }
    });

    ui::Button* speedButton = rootNode->getChildByName<ui::Button*>("SpeedButton");
    speedButton->addTouchEventListener([this](Ref* pRef, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            this->entityLevelParameter.levelSpeed++;
            UserDataManager::getInstance()->setEntityLevelParameter(this->entityType, this->entityLevelParameter);
            this->setLabelTextByEntityLevelParameter(this->entityLevelParameter);
        }
    });

    ui::Button* backButton = rootNode->getChildByName<ui::Button*>("BackButton");
    backButton->addTouchEventListener([this](Ref* pRef, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            Director::getInstance()->popScene();
        }
    });
}

void PowerUpScene::setLabelTextByEntityLevelParameter(EntityLevelParameter entityLevelParameter)
{
    this->hpLabel->setString(std::to_string(entityLevelParameter.levelHp));
    this->attackLabel->setString(std::to_string(entityLevelParameter.levelAttack));
    this->speedLabel->setString(std::to_string(entityLevelParameter.levelSpeed));
}
