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
    const Size visibleSize = Director::getInstance()->getVisibleSize();

    const std::vector<Vec2> buttonPositionList = {
        Vec2(visibleSize.width * 0.3f, visibleSize.height * 0.65f),
        Vec2(visibleSize.width * 0.7f, visibleSize.height * 0.65f),
        Vec2(visibleSize.width * 0.3f, visibleSize.height * 0.25f),
        Vec2(visibleSize.width * 0.7f, visibleSize.height * 0.25f),
    };

    const unsigned int entityTypeCount = (int)EntityType::NONE;
    const unsigned int totalPageCount = ceil(entityTypeCount / (float)buttonPositionList.size());
    this->pageView->setSizePercent(Vec2(1.0f, 1.0f));

    for (int page = 0, last = totalPageCount; page < last; ++page) {
        ui::Layout* pageLayout = ui::Layout::create();

        for (Vec2 buttonPosition : buttonPositionList) {
            auto it = std::find(buttonPositionList.begin(), buttonPositionList.end(), buttonPosition);
            long buttonPositionIndex = std::distance(buttonPositionList.begin(), it);
            CCASSERT(buttonPositionIndex != buttonPositionList.size(), "Index out of range");

            EntityType entityType = (EntityType)(page * buttonPositionList.size() + buttonPositionIndex);

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

            stageButton->setPosition(buttonPosition);
            pageLayout->addChild(stageButton);
        }

        this->pageView->addPage(pageLayout);
    }
}
