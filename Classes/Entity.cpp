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
    this->accelerationFactor = 0.0f;
    this->initialColor = CIRCLE_LIGHT_BLUE;

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

void Entity::setEntityParameterLevel(struct EntityParameterLevel entityParameterLevel)
{
    this->EntityParameterLevel = entityParameterLevel;

    this->setRankSymbol(entityParameterLevel.rank);
    this->setupEntityParamerterByLevel(entityParameterLevel);
}

void Entity::setHp(int hp)
{
    if (this->stateMachine->isDead()) {
        return;
    }

    this->hp = MAX(hp, 0);

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

    for (std::map<std::string, EntityAttackParams>::iterator it = this->attackMap.begin(); it != this->attackMap.end(); ++it) {
        attackNameList.push_back(it->first);
    }

    return attackNameList;
}

void Entity::setAttackMap(std::map<std::string, EntityAttackParams> attackMap)
{
    this->attackMap = attackMap;
}

EntityAttackParams Entity::getAttackParamsByName(std::string attackName)
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

std::vector<Rect> Entity::getRectsUseForAttackInWorldSpace()
{
    std::vector<Rect> returnRects;
    Vector<Node*> children = this->getChildren();

    for (int i = 0, last = (int)children.size(); i < last; ++i) {
        Sprite* sprite = dynamic_cast<Sprite*>(children.at(i));

        if (! sprite || ! sprite->isVisible()) {
            continue;
        }

        Size size = sprite->getContentSize();
        float scaleX = sprite->getScaleX();
        float scaleY = sprite->getScaleY();
        Vec2 spritePositionInWorld = this->convertToWorldSpace(sprite->getPosition());

        Rect spriteRect = Rect(
                spritePositionInWorld.x - size.width * sprite->getAnchorPoint().x * scaleX,
                spritePositionInWorld.y - size.height * sprite->getAnchorPoint().y * scaleY,
                size.width * scaleX, size.height * scaleY
            );
        returnRects.push_back(spriteRect);
    }

    return returnRects;
}

std::vector<Rect> Entity::getRectsUseForDamageInWorldSpace()
{
    std::vector<Rect> returnRects;
    Vector<Node*> children = this->getChildren();

    Sprite* body = this->getBody();

    Size size = body->getContentSize();
    float scaleX = body->getScaleX();
    float scaleY = body->getScaleY();
    Vec2 bodyPositionInWorld = this->convertToWorldSpace(body->getPosition());

    Rect bodyRect = Rect(
            bodyPositionInWorld.x - size.width * body->getAnchorPoint().x * scaleX,
            bodyPositionInWorld.y - size.height * body->getAnchorPoint().y * scaleY,
            size.width * scaleX, size.height * scaleY
        );

    returnRects.push_back(bodyRect);

    return returnRects;
}

EntityIdentifier Entity::getIdentifier()
{
    return this->identifier;
}

void Entity::setIdentifier(EntityIdentifier identifier)
{
    this->identifier = identifier;
}

Size Entity::getBodySize()
{
    Sprite* body = this->getBody();
    return body->getContentSize();
}

JSONPacker::EntityState Entity::currentEntityState()
{
    JSONPacker::EntityState entityState;
    entityState.identifier = this->identifier;
    entityState.hp = this->hp;
    entityState.position = this->getPosition();
    entityState.moveState = this->stateMachine->getMoveState();
    entityState.direction = this->stateMachine->getDirection();
    entityState.globalState = this->stateMachine->getGlobalState();
    entityState.attackState = this->stateMachine->getAttackState();
    entityState.attackName = this->currentAttackName;

    entityState.damage.identifier = this->identifier; // FIXME: It should be initialized by null identifier
    entityState.damage.volume = 0;

    return entityState;
}

#pragma mark Game logic

void Entity::activate()
{
    this->stateMachine->alive();
    this->scheduleUpdate();
    this->runAction(this->timeline);
}

void Entity::deactivate()
{
    this->stateMachine->stop();
    this->stateMachine->cancelAttack();
    this->unscheduleAllCallbacks();
    this->stopAllActions();
}

#pragma mark Behavior

void Entity::attack(const std::string attackName)
{
    if (! this->stateMachine->canAttack()) {
        return;
    }

    if (this->stateMachine->isDead()) {
        return;
    }

    EntityAttackParams attackParams = this->getAttackParamsByName(attackName);
    std::string particleFilePath = attackParams.particleFilePath;

    this->timeline->play(attackName, false);
    this->timeline->setFrameEventCallFunc([this, attackName, particleFilePath](Frame* frame) {
        EventFrame* frameEvent = dynamic_cast<EventFrame*>(frame);
        auto eventName = frameEvent->getEvent();

        // log("---- %s ----", eventName.c_str());
        if (eventName == "Ready") {
            this->currentAttackName = attackName;
            this->stateMachine->readyToAttack();
        } else if (eventName == "Attack") {
            this->stateMachine->startToAttack();

            if (particleFilePath != "") {
                ParticleSystemQuad* particle = ParticleSystemQuad::create(particleFilePath);
                this->addChild(particle);
            }
        } else if (eventName == "Cooldown") {
            this->stateMachine->coolDownAttaking();
        } else if (eventName == "Finish") {
            this->stateMachine->finishAttaking();
            this->currentAttackName = "";
        }
    });
}

void Entity::startCharging()
{
    if (! this->stateMachine->canCharge()) {
        return;
    }

    if (this->stateMachine->isDead()) {
        return;
    }

    this->timeline->play("Charging", true);
    this->stateMachine->startCharging();
}

void Entity::receiveDamage(int damage, Vec2 enemyPosition)
{
    if (this->stateMachine->isDead()) {
        return;
    }

    this->setHp(this->hp - damage);

    Sprite* body = this->getBody();

    ParticleSystemQuad* particle = ParticleSystemQuad::create("Particles/Damage.plist");
    particle->setStartColor(Color4F(body->getColor()));
    particle->setEndColor(Color4F(body->getColor()));
    this->addChild(particle);

    EntityDirection knockbackDirection = EntityHelper::directionFromStartPositionAndEndPosition(enemyPosition, this->getPosition());
    this->knockback(knockbackDirection, ENTITY_KNOCKBACK_DISTANCE_PER_SEC, ENTITY_KNOCKBACK_CANCEL_ATTACK);
}

void Entity::knockback(EntityDirection direction, float distance, bool cancelAttack)
{
    this->stateMachine->startKnockback();

    const std::string knockbackScheduleKey = "knockback";
    this->unschedule(knockbackScheduleKey);

    if (cancelAttack) {
        this->stateMachine->cancelAttack();
    }

    this->setVisible(true); // Avoid set original state for blink action false
    this->runAction(Blink::create(ENTITY_KNOCKBACK_DURATION, 4));

    Vec2 unitVector = EntityHelper::unitVectorFronEntityDirection(direction);
    this->schedule([this, unitVector, distance](float dt) {
        this->velocity = unitVector * distance * dt;
    }, knockbackScheduleKey);

    this->scheduleOnce([this, knockbackScheduleKey](float dt) {
        this->stateMachine->stopKnockback();
        this->unschedule(knockbackScheduleKey);
    }, ENTITY_KNOCKBACK_DURATION, "unscheduleKnockback");
}

#pragma mark EntityStateMachineDelegate

void Entity::willStateChange(EntityMoveState moveState, EntityDirection direction, EntityAttackState attackState)
{
}

void Entity::didStateChanged(EntityMoveState moveState, EntityDirection direction, EntityAttackState newAttackState)
{
    if (this->stateMachine->isDead()) {
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

void Entity::setVelocity(float dt)
{
    if (! this->stateMachine->isMoving() || this->stateMachine->isAttacking()) {
        this->deaccelerate(dt);
    } else {
        this->accelerate(dt);
    }

    Vec2 unitVector = EntityHelper::unitVectorFronEntityDirection(this->stateMachine->getDirection());
    this->velocity = ENTITY_VELOCITY_FACTOR * unitVector * dt * accelerationFactor;

    if (this->stateMachine->isCharging()) {
        this->velocity *= 0.4f;
    }
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
        float remainHpPercent = this->hp / static_cast<float>(this->entityParameter.initialHp);

        if (this->stateMachine->isDead()) {
            sprite->setColor(Color3B(CIRCLE_DARK_RED));
            sprite->setOpacity(8);
            continue;
        }

        if (remainHpPercent < 0.2) {
            // TODO: temporary
            if (this->initialColor == CIRCLE_LIGHT_RED) {
                sprite->setColor(Color3B(CIRCLE_DARK_RED));
            } else if (this->initialColor == CIRCLE_LIGHT_BLUE) {
                sprite->setColor(Color3B(CIRCLE_DARK_BLUE));
            }
        } else {
            sprite->setColor(Color3B(this->initialColor));
        }
    }
}

#pragma mark Game logic

void Entity::update(float dt)
{
    Node::update(dt);

    if (this->stateMachine->getMoveState() == EntityMoveState::KNOCKBACK) {
        return;
    }

    // set rotation
    float startAngle = this->getRotation();
    float endAngle = -static_cast<float>(this->stateMachine->getDirection());
    float diffAngle = EntityHelper::diffAngleFromStartAngleAndEndAngle(startAngle, endAngle);
    float anglePerSecond = 15.0f;
    this->setRotation(startAngle + diffAngle * dt * anglePerSecond);

    // set velocity
    this->setVelocity(dt);
}

void Entity::accelerate(float deltaTime)
{
    this->accelerationFactor = MIN(1.0f, this->accelerationFactor + 5.0f * deltaTime);
}

void Entity::deaccelerate(float deltaTime)
{
    this->accelerationFactor = MAX(0.0f, this->accelerationFactor - 5.0f * deltaTime);
}

void Entity::die()
{
    if (this->stateMachine->isDead()) {
        return;
    }

    this->stateMachine->dead();
    Sprite* body = this->getBody();

    ParticleSystemQuad* particle = ParticleSystemQuad::create("Particles/Die.plist");
    particle->setStartColor(Color4F(body->getColor()));
    particle->setEndColor(Color4F(body->getColor()));
    this->addChild(particle);

    this->deactivate();
}
