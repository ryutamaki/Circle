//
// Entity.cpp
// DotWar
//
// Created by ryutamaki on 2015/07/15.
//
//

#include "Entity.h"

USING_NS_CC;
using namespace cocostudio::timeline;

#pragma mark - Initilalizer

bool Entity::init()
{
    if (! Node::init()) {
        return false;
    }

    this->stateMachine = std::unique_ptr<EntityStateMachine>(new EntityStateMachine());
    this->stateMachine->setDelegate(this);
    this->synchronizer = std::unique_ptr<EntitySynchronizer>(new EntitySynchronizer());
    this->velocity = Vec2::ZERO;
    this->initialColor = CIRCLE_LIGHT_BLUE;

    this->setupAttackMap();

    return true;
}

#pragma mark Accessor

EntityType Entity::getEntityType() const
{
    return this->entityType;
}

void Entity::setEntityType(EntityType entityType)
{
    this->entityType = entityType;
}

EntityParameter Entity::getEntityParameter()
{
    return this->entityParameter;
}

EntityParameterLevel Entity::getEntityParameterLevel()
{
    return this->EntityParameterLevel;
}

void Entity::setEntityParameterLevel(struct EntityParameterLevel EntityParameterLevel)
{
    this->EntityParameterLevel = EntityParameterLevel;

    this->setRankSymbol(EntityParameterLevel.rank);
    this->setupEntityParamerterByLevel(EntityParameterLevel);
}

int Entity::getHp()
{
    return this->hp;
}

void Entity::setHp(int hp)
{
    if (this->isDead) {
        return;
    }

    int currentHp = this->hp;
    this->hp = MAX(hp, 0);

    if (this->hp < currentHp) {
        this->receiveDamage();
    }

    if (this->hp <= 0) {
        this->die();
    }

    this->setBodyColorByCurrentHp();
}

Vec2 Entity::getVelocity()
{
    return this->velocity;
}

void Entity::setInitialColor(Color4B initialColor)
{
    this->initialColor = initialColor;
}

std::string Entity::getCurrentAttackName()
{
    return this->currentAttackName;
}

std::vector<std::string> Entity::getAttackNameList()
{
    std::vector<std::string> attackNameList;

    for (std::map<std::string, AttackParams>::iterator it = this->attackMap.begin(); it != this->attackMap.end(); ++it) {
        attackNameList.push_back(it->first);
    }

    return attackNameList;
}

AttackParams Entity::getAttackParamsByName(std::string attackName)
{
    auto itr = this->attackMap.find(attackName);

    if (itr != this->attackMap.end()) {
        return this->attackMap[attackName];
    }

    CCASSERT(false, "Undefined attack is selected");
}

Rect Entity::getBodyRect()
{
    Size size = this->getBodySize();
    Vec2 position = this->getPosition();

    Rect returnRect = Rect(
            position.x - size.width * 0.5f,
            position.y - size.height * 0.5f,
            size.width, size.height
        );
    return returnRect;
}

Rect Entity::getBodyRectInWorldSpace()
{
    Rect returnRect;
    Vector<Node*> children = this->getChildren();

    for (int i = 0, last = (int)children.size(); i < last; ++i) {
        Sprite* sprite = dynamic_cast<Sprite*>(children.at(i));

        if (! sprite || ! sprite->isVisible()) {
            continue;
        }

        Size size = sprite->getContentSize();
        Vec2 bodyPosition = sprite->getPosition();
        Vec2 bodyPositionInWorld = this->convertToWorldSpace(bodyPosition);

        Rect spriteRect = Rect(
                bodyPositionInWorld.x - size.width * sprite->getAnchorPoint().x,
                bodyPositionInWorld.y - size.height * sprite->getAnchorPoint().y,
                size.width, size.height
            );

        if (returnRect.equals(Rect::ZERO)) {
            returnRect = spriteRect;
        } else {
            returnRect.merge(spriteRect);
        }
    }

    return returnRect;
}

std::string Entity::getIdentifier()
{
    return this->identifier;
}

void Entity::setIdentifier(std::string identifier)
{
    this->identifier = identifier;
}

Size Entity::getBodySize()
{
    Sprite* body = this->getBody();
    return body->getContentSize();
}

bool Entity::getIsDead()
{
    return this->isDead;
}

JSONPacker::EntityState Entity::currentEntityState()
{
    JSONPacker::EntityState entityState;
    entityState.identifier = this->identifier;
    entityState.hp = this->getHp();
    entityState.position = this->getPosition();
    entityState.moveState = this->stateMachine->getMoveState();
    entityState.attackState = this->stateMachine->getAttackState();

    entityState.damage.identifier = "";
    entityState.damage.volume = 0;

    return entityState;
}

#pragma mark Game logic

void Entity::activate()
{
    this->isDead = false;
    this->scheduleUpdate();
    this->runAction(this->timeline);
}

void Entity::deactivate()
{
    this->isDead = true;
    this->stateMachine->move(EntityMoveState::NONE);
    this->stateMachine->cancelAttack();
    this->unscheduleUpdate();
    this->stopAllActions();
}

#pragma mark Behavior

void Entity::attack(const std::string attackName)
{
    if (! this->stateMachine->canAttack()) {
        return;
    }

    if (this->getIsDead()) {
        return;
    }

    this->timeline->play(attackName, false);
    this->timeline->setFrameEventCallFunc([this, attackName](Frame* frame) {
        EventFrame* frameEvent = dynamic_cast<EventFrame*>(frame);
        auto eventName = frameEvent->getEvent();

        // log("---- %s ----", eventName.c_str());
        if (eventName == "Ready") {
            this->stateMachine->readyToAttack();
            this->currentAttackName = attackName;
        } else if (eventName == "Attack") {
            this->stateMachine->startToAttack();
        } else if (eventName == "Cooldown") {
            this->stateMachine->coolDownAttaking();
        } else if (eventName == "Finish") {
            this->stateMachine->finishAttaking();
            this->currentAttackName = "";
        }
    });
}

void Entity::attack(const std::string attackName, float chargeduration)
{
    this->attack(attackName);

    ParticleSystemQuad* particle = ParticleSystemQuad::create("Particles/Circle_ChargeAttack_Smoke.plist");
    this->addChild(particle);
}

void Entity::startCharging()
{
    if (! this->stateMachine->canCharge()) {
        return;
    }

    if (this->isDead) {
        return;
    }

    this->timeline->play("Charging", true);

    this->stateMachine->startCharging();
    this->schedule(CC_SCHEDULE_SELECTOR(Entity::updateCharge));
}

void Entity::endCharging()
{
    if (! this->stateMachine->isCharging()) {
        return;
    }

    if (this->isDead) {
        return;
    }

    this->attack("ChargeAttack", this->chargeDuration);
    this->unschedule(CC_SCHEDULE_SELECTOR(Entity::updateCharge));
    this->chargeDuration = 0.0f;
}

#pragma mark EntityStateMachineDelegate

void Entity::willStateChange(EntityMoveState moveState, EntityAttackState attackState)
{
}

void Entity::didStateChanged(EntityMoveState newMoveState, EntityAttackState newAttackState)
{
    if (this->getIsDead()) {
        return;
    }

    JSONPacker::EntityState currentEntityState = this->currentEntityState();
    this->synchronizer->sendData(currentEntityState);
}

#pragma mark - Protected method

#pragma mark View lifecycle

void Entity::onEnter()
{
    Node::onEnter();

    this->setHp(this->entityParameter.initialHp);

    Vector<Node*> children = this->getChildren();

    for (int i = 0, last = (int)children.size(); i < last; ++i) {
        Sprite* sprite = dynamic_cast<Sprite*>(children.at(i));

        if (! sprite) {
            continue;
        }
        sprite->setCascadeColorEnabled(false);
    }
}

void Entity::onExit()
{
    Node::onExit();

    this->deactivate();
}

Sprite* Entity::getBody()
{
    Sprite* body = this->getChildByName<Sprite*>("Body");
    CCASSERT(body, "There are no body, please make a body in cocos studio.");
    return body;
}

void Entity::setRankSymbol(int rank)
{
    if (! EntityHelper::isRankExists(rank)) {
        return;
    }

    std::string symbolPath = ENTITY_RANK_SYMBOL_PATH.at(rank);

    if (symbolPath == "") {
        return;
    }

    Sprite* body = this->getBody();

    Sprite* symbol = Sprite::create(symbolPath);
    symbol->setNormalizedPosition(Vec2(0.5f, 0.5f));
    symbol->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    body->addChild(symbol);
}

void Entity::setBodyColorByCurrentHp()
{
    Vector<Node*> children = this->getChildren();

    for (int i = 0, last = (int)children.size(); i < last; ++i) {
        Sprite* sprite = dynamic_cast<Sprite*>(children.at(i));

        if (! sprite) {
            continue;
        }

        // TODO: わかりにくいから、なんか考える
        sprite->setColor(Color3B(this->initialColor));

        float minimumOpacity = 0.1f;
        float remainHpPercent = this->hp / static_cast<float>(this->entityParameter.initialHp);
        float opacity = remainHpPercent * ((1.0f - minimumOpacity) / 1.0f) + minimumOpacity;
        sprite->setOpacity(static_cast<GLubyte>(opacity * 255));
    }
}

#pragma mark Game logic

void Entity::update(float dt)
{
    Node::update(dt);

    EntityMoveState currentMoveState = this->stateMachine->getMoveState();
    Vec2 direction = EntityHelper::directionFromMoveState(currentMoveState);
    this->velocity = (float)this->entityParameter.velocityFactor * direction * dt;

    if (this->stateMachine->getAttackState() == EntityAttackState::CHARGING) {
        this->velocity *= 0.4f;
    }
    this->setRotation(EntityHelper::rotationFromMoveState(currentMoveState, this->getRotation()));
}

void Entity::updateCharge(float dt)
{
    this->chargeDuration += dt;
}

void Entity::receiveDamage()
{
    if (this->getIsDead()) {
        return;
    }

    Sprite* body = this->getBody();

    ParticleSystemQuad* particle = ParticleSystemQuad::create("Particles/Damage.plist");
    particle->setStartColor(Color4F(body->getColor()));
    particle->setEndColor(Color4F(body->getColor()));
    this->addChild(particle);
}

void Entity::die()
{
    if (this->getIsDead()) {
        return;
    }

    Sprite* body = this->getBody();

    ParticleSystemQuad* particle = ParticleSystemQuad::create("Particles/Die.plist");
    particle->setStartColor(Color4F(body->getColor()));
    particle->setEndColor(Color4F(body->getColor()));
    this->addChild(particle);

    this->deactivate();
}
