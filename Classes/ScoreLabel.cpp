//
// ScoreLabel.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/28.
//
//

#include "ScoreLabel.h"

USING_NS_CC;
using namespace cocostudio::timeline;

#pragma mark - Public methods

#pragma mark Initializer

bool ScoreLabel::init()
{
    if (! Node::init()) {
        return false;
    }

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("ScoreLabel.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->timeline->retain();

    return true;
}

#pragma mark Accessor

void ScoreLabel::setScore(int score)
{
    this->timeline->play("CountUp", false);
    this->timeline->setFrameEventCallFunc([this, score](Frame* frame) {
        EventFrame* frameEvent = dynamic_cast<EventFrame*>(frame);
        auto eventName = frameEvent->getEvent();

        if (eventName == "CountUp") {
            this->scoreLabel->setString(std::to_string(score));
        }
    });
}

#pragma mark - Private methods

#pragma mark View lifecycle

void ScoreLabel::onEnter()
{
    Node::onEnter();
    this->runAction(this->timeline);

    this->scoreLabel = this->getChildByName<ui::TextBMFont*>("ScoreLabel");
}

void ScoreLabel::onExit()
{
    Node::onExit();

    this->stopAllActions();
}
