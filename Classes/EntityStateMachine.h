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

enum class EntityMoveState
{
    NONE,
    UP,
    UP_LEFT,
    LEFT,
    DOWN_LEFT,
    DOWN,
    DOWN_RIGHT,
    RIGHT,
    UP_RIGHT,
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

class EntityStateMachineDelegate
{
public:
    virtual void willStateChange(EntityMoveState moveState, EntityAttackState attackState) = 0;
    virtual void didStateChanged(EntityMoveState newMoveState, EntityAttackState newAttackState) = 0;
};

class EntityStateMachine
{
public:
    EntityStateMachine();
    ~EntityStateMachine();

    // Accessor
    const EntityMoveState getMoveState();
    void setMoveState(const EntityMoveState moveState);
    const EntityAttackState getAttackState();
    void setAttackState(const EntityAttackState attackState);

    void setDelegate(EntityStateMachineDelegate* delegate);

    // Function to change state
    // These functions return a result
    // MOVE:
    void move(const EntityMoveState movingState);
    // ATTACK:
    void startCharging();
    void readyToAttack();
    void startToAttack();
    void hitAttack();
    void coolDownAttaking();
    void finishAttaking();
    void cancelAttack();

    bool canAttack();
    bool canCharge();
    bool isAttacking();
    bool isCharging();

private:
    EntityStateMachineDelegate* delegate;

    EntityMoveState moveState;
    EntityAttackState attackState;
};

#endif /* defined(__DotWar__EntityStateMachine__) */
