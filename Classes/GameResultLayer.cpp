//
// GameResultLayer.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/27.
//
//

#include "GameResultLayer.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "GameSceneManager.h"
#include "PowerUpButton.h"
#include "PowerUpButtonReader.h"

#include "EntityFactory.h"
#include "UserDataManager.h"

USING_NS_CC;

#pragma mark - Public methods

#pragma mark Initializer

bool GameResultLayer::init()
{
    if (! Layer::init()) {
        return false;
    }

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("GameResultLayer.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->timeline->retain();

    this->score = 0;
    this->highScore = 0;
    this->isNewRecord = false;
    this->coinCount = 0;
    this->networked = false;
    this->entityType = EntityType::NONE;

    // Prevent propagation into the layers below
    EventListenerTouchOneByOne* eventListener = EventListenerTouchOneByOne::create();
    eventListener->setSwallowTouches(true);
    eventListener->onTouchBegan = [](Touch* touch, Event* event) -> bool {
            return true;
        };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, this);

    return true;
}

void GameResultLayer::show(Node* parent)
{
    parent->addChild(this, Z_ORDER_FOR_MODAL);
    this->timeline->play("Show", false);
}

void GameResultLayer::hide(std::function<void()> lastFrameCallback)
{
    this->timeline->play("Hide", false);
    this->timeline->setLastFrameCallFunc(lastFrameCallback);
}

#pragma mark Accessors

void GameResultLayer::setScore(int score)
{
    this->score = score;
}

void GameResultLayer::setHighScore(int highScore)
{
    this->highScore = highScore;
}

void GameResultLayer::setIsNewRecord(bool isNewRecord)
{
    this->isNewRecord = isNewRecord;
}

void GameResultLayer::setCoinCount(int coinCount)
{
    this->coinCount = coinCount;
}

void GameResultLayer::setNetworked(bool networked)
{
    this->networked = networked;
}

void GameResultLayer::setEntityType(EntityType entityType)
{
    this->entityType = entityType;
}

#pragma mark - Private methods

#pragma mark View lifecycle

void GameResultLayer::onEnter()
{
    Layer::onEnter();

    this->runAction(this->timeline);

    Sprite* overlay = this->getChildByName<Sprite*>("Overlay");
    this->setContentSize(overlay->getContentSize());

    this->resultLayout = this->getChildByName<ui::Layout*>("ResultLayout");
    this->setupButtons();
    this->setupPowerUpButtonNotifier();
    this->setupLabels();
}

void GameResultLayer::onExit()
{
    Layer::onExit();

    this->stopAction(this->timeline);
}

void GameResultLayer::setupButtons()
{
    ui::Button* quitButton = this->resultLayout->getChildByName<ui::Button*>("QuitButton");
    quitButton->addTouchEventListener([](Ref* pSender, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            GameSceneManager::getInstance()->exitGameScene();
        }
    });

    ui::Button* retryButton = this->resultLayout->getChildByName<ui::Button*>("RetryButton");
    retryButton->addTouchEventListener([this](Ref* pSender, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            GameSceneManager::getInstance()->restartGameScene(this->networked);
        }
    });
}

void GameResultLayer::setupPowerUpButtonNotifier()
{
    std::unique_ptr<EntityFactory> entityFactory = std::unique_ptr<EntityFactory>(new EntityFactory());
    EntityParameterLevel parameterLevel = UserDataManager::getInstance()->getEntityParameterLevel(this->entityType);
    Entity* entity = entityFactory->createFriend(true, this->entityType, parameterLevel);
    PowerUpButton* powerUpButton = this->resultLayout->getChildByName<PowerUpButton*>("PowerUpButton");
    powerUpButton->setNotifierByEntity(entity);
}

void GameResultLayer::setupLabels()
{
    ui::TextBMFont* scoreCountLabel = this->resultLayout->getChildByName<ui::TextBMFont*>("ScoreCountLabel");
    scoreCountLabel->setString(std::to_string(this->score));

    ui::TextBMFont* coinCountLabel = this->resultLayout->getChildByName<ui::TextBMFont*>("CoinCountLabel");
    coinCountLabel->setString(std::to_string(this->coinCount));

    ui::TextBMFont* highScoreCountLabel = this->resultLayout->getChildByName<ui::TextBMFont*>("HighScoreCountLabel");
    highScoreCountLabel->setString(std::to_string(this->highScore));

    if (isNewRecord) {
        highScoreCountLabel->setColor(Color3B(CIRCLE_DARK_BLUE));
    }
}
