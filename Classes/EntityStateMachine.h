//
// EntityStateMachine.h
// DotWar
//
// Created by ryutamaki on 2015/07/16.
//
//

#ifndef __DotWar__EntityStateMachine__
#define __DotWar__EntityStateMachine__

class Entity;
class EntityStateDelegate;

typedef int EntityDirection;

enum class EntityMoveState
{
    NONE,
    MOVING,
    KNOCKBACK,
};

enum class EntityAttackState
{
    NONE,
    CHARGING,
    READY,
    ATTACKING,
    HIT,
    COOL_DOWN,
};

enum class EntityGlobalState
{
    READY,
    ALIVE,
    DEAD,
};

class EntityStateMachineDelegate
{
public:
    virtual void willStateChange(EntityMoveState moveState, EntityDirection direction, EntityAttackState attackState) = 0;
    virtual void didStateChanged(EntityMoveState moveState, EntityDirection direction, EntityAttackState newAttackState) = 0;
};

class EntityStateMachine
{
public:
    EntityStateMachine();
    ~EntityStateMachine();

    // Accessor
    const EntityMoveState getMoveState();
    void setMoveState(const EntityMoveState moveState);
    const EntityDirection getDirection();
    void setDirection(const EntityDirection direction);
    const EntityAttackState getAttackState();
    void setAttackState(const EntityAttackState attackState);
    const EntityGlobalState getGlobalState();
    void setGlobalState(const EntityGlobalState globalState);

    void setDelegate(EntityStateMachineDelegate* delegate);

    // Function to change state
    // These functions return a result
    // MOVE:
    // void move(const EntityMoveState movingState);
    void move(const EntityDirection direction);
    void stop();
    void startKnockback();
    void stopKnockback();
    // ATTACK:
    void startCharging();
    void readyToAttack();
    void startToAttack();
    void hitAttack();
    void coolDownAttaking();
    void finishAttaking();
    void cancelAttack();
    // GLOBAL
    void ready();
    void alive();
    void dead();

    bool canAttack();
    bool canCharge();

    bool isDead();
    bool isMoving();
    bool isAttacking();
    bool isCharging();

private:
    EntityStateMachineDelegate* delegate;

    // EntityMoveState moveState;
    EntityDirection direction;
    EntityMoveState moveState;
    EntityAttackState attackState;
    EntityGlobalState globalState;
};

#endif /* defined(__DotWar__EntityStateMachine__) */
