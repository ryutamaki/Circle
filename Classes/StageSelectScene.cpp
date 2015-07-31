//
//
// Created by ryutamaki on 2015/07/26.
//
//

#include "StageSelectScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "StageButton.h"
#include "StageButtonReader.h"

#include "EntityConstants.h"
#include "GameSceneManager.h"
#include "MenuScene.h"

USING_NS_CC;

#pragma mark - Public methods

#pragma mark Initializer

Scene* StageSelectScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = StageSelectScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool StageSelectScene::init()
{
    if (! Layer::init()) {
        return false;
    }

    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("StageButtonReader", (ObjectFactory::Instance)StageButtonReader::getInstance);

    auto rootNode = CSLoader::createNode("StageSelectScene.csb");

    Size visibleSize = Director::getInstance()->getVisibleSize();
    rootNode->setContentSize(visibleSize);
    ui::Helper::doLayout(rootNode);

    this->pageView = rootNode->getChildByName<ui::PageView*>("PageView");
    this->pageView->setCustomScrollThreshold(visibleSize.width * 0.1f);

    ui::Button* backButton = rootNode->getChildByName<ui::Button*>("BackButton");
    backButton->addTouchEventListener([this](Ref* pRef, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            Scene* menuScene = MenuScene::createScene();
            Director::getInstance()->replaceScene(menuScene);
        }
    });

    addChild(rootNode);

    return true;
}

#pragma mark - Private methods

void StageSelectScene::onEnter()
{
    Layer::onEnter();

    this->setupStageSelectButtons();
}

void StageSelectScene::onExit()
{
    Layer::onExit();

    this->pageView = nullptr;
}

void StageSelectScene::setupStageSelectButtons()
{
    const unsigned int entityTypeCount = (int)EntityType::NONE;
    const unsigned int totalPageCount = ceil(entityTypeCount);
    this->pageView->setSizePercent(Vec2(0.5f, 2.0f));
    this->pageView->setColor(Color3B::GRAY);

    for (int page = 0, last = totalPageCount; page < last; ++page) {
        ui::Layout* pageLayout = ui::Layout::create();
        EntityType entityType = (EntityType)(page);

        if (entityType >= EntityType::NONE) {
            entityType = EntityType::NONE;
        }

        StageButton* stageButton = dynamic_cast<StageButton*>(CSLoader::createNode("StageButton.csb"));
        stageButton->setEntityType(entityType);
        ui::Button* stageButtonBase = stageButton->getChildByName<ui::Button*>("StageButtonBase");

        if (entityType != EntityType::NONE) {
            stageButtonBase->addTouchEventListener([entityType](Ref* pSender, ui::Widget::TouchEventType eEventType) {
                if (eEventType == ui::Widget::TouchEventType::ENDED) {
                    GameSceneManager::getInstance()->enterGameScene(entityType, false);
                    log("entity type: %d", entityType);
                }
            });
        }
        stageButton->setNormalizedPosition(Vec2(0.5f, 0.5f));
        pageLayout->addChild(stageButton);

        this->pageView->addPage(pageLayout);
    }
}
