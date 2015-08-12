//
//
// Created by ryutamaki on 2015/07/26.
//
//

#include "StageSelectScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "StageComponent.h"
#include "StageComponentReader.h"

#include "Entity.h"
#include "EntityConstants.h"
#include "EntityFactory.h"
#include "GameSceneManager.h"
#include "MenuScene.h"

#include "FlurryHelper.h"

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
    instance->registReaderObject("StageComponentReader", (ObjectFactory::Instance)StageComponentReader::getInstance);

    auto rootNode = CSLoader::createNode("StageSelectScene.csb");

    Size visibleSize = Director::getInstance()->getVisibleSize();
    rootNode->setContentSize(visibleSize);
    ui::Helper::doLayout(rootNode);

    this->pageView = rootNode->getChildByName<ui::PageView*>("PageView");
    this->pageView->setSizePercent(Vec2(0.5f, 1.0f));
    this->pageView->setCustomScrollThreshold(visibleSize.width * 0.1f);

    this->endlessButton = rootNode->getChildByName<ui::Button*>("EndlessButton");

    ui::Button* backButton = rootNode->getChildByName<ui::Button*>("BackButton");
    backButton->addTouchEventListener([this](Ref* pRef, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            Scene* menuScene = MenuScene::createScene();
            TransitionFade* transition = TransitionFade::create(SCENE_TRANSITION_DURATION, menuScene, SCENE_TRANSITION_COLOR);
            Director::getInstance()->replaceScene(transition);
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
    this->setupUI();
    this->expandPageViewTouchHandler();

    // log for analytics
    FlurryHelper::logTransitionScene(FlurryHelper::SCENE_NAME_STAGE_SELECT);
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

    std::unique_ptr<EntityFactory> factory = std::unique_ptr<EntityFactory>(new EntityFactory());

    for (int page = 0, last = totalPageCount; page < last; ++page) {
        EntityType entityType = (EntityType)(page);

        if (entityType >= EntityType::NONE) {
            entityType = EntityType::NONE;
        }

        // StageComponent* stageComponent = dynamic_cast<StageComponent*>(CSLoader::createNode("StageComponent.csb"));
        // stageComponent->setName("Component");
        // stageComponent->setEntityType(entityType);
        // stageComponent->setNormalizedPosition(Vec2(0.5f, 0.5f));

        Entity* entity = factory->createEnemy(
                entityType,
                ENTITY_INITIAL_LEVEL_PARAMETER.at(entityType),
                {}
            );
        entity->setName("Entity");
        entity->setNormalizedPosition(Vec2(0.5f, 0.6f));

        ui::Layout* pageLayout = ui::Layout::create();
        pageLayout->setSwallowTouches(false);
        pageLayout->setPropagateTouchEvents(true);
        pageLayout->addChild(entity);

        this->pageView->addPage(pageLayout);
    }
}

void StageSelectScene::setupUI()
{
    this->endlessButton->addTouchEventListener([this](Ref* pRef, ui::Widget::TouchEventType eEventType) {
        if (eEventType == ui::Widget::TouchEventType::ENDED) {
            const size_t currentPageIndex = this->pageView->getCurPageIndex();
            const ui::Layout* currenPage = this->pageView->getPage(currentPageIndex);
            // const StageComponent* component = currenPage->getChildByName<StageComponent*>("Component");
            const Entity* entity = currenPage->getChildByName<Entity*>("Entity");
            const EntityType entityType = entity->getEntityType();

            GameSceneManager::getInstance()->enterGameScene(entityType, false);
        }
    });
}

void StageSelectScene::expandPageViewTouchHandler()
{
    EventListenerTouchOneByOne* touchListener = EventListenerTouchOneByOne::create();

    touchListener->onTouchBegan = [this](Touch* touch, Event* event) {
            return true;
        };
    touchListener->onTouchMoved = [this](Touch* touch, Event* event) {
            if (this->pageView) {
                pageView->onTouchMoved(touch, event);
            }
        };
    touchListener->onTouchCancelled = [this](Touch* touch, Event* event) {
            if (this->pageView) {
                pageView->onTouchCancelled(touch, event);
            }
        };
    touchListener->onTouchEnded = [this](Touch* touch, Event* event) {
            if (this->pageView) {
                pageView->onTouchEnded(touch, event);
            }
        };

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}
