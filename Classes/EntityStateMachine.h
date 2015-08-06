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
typedef int Moving;

// enum class EntityMoveState
// {
// NONE,
// UP,
// UP_LEFT,
// LEFT,
// DOWN_LEFT,
// DOWN,
// DOWN_RIGHT,
// RIGHT,
// UP_RIGHT,
// };

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
    virtual void willStateChange(Moving moving, EntityDirection direction, EntityAttackState attackState) = 0;
    virtual void didStateChanged(Moving moving, EntityDirection direction, EntityAttackState newAttackState) = 0;
};

class EntityStateMachine
{
public:
    EntityStateMachine();
    ~EntityStateMachine();

    // Accessor
    const Moving getMoving();
    void setMoving(const Moving moving);
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
    Moving moving;
    EntityDirection direction;
    EntityAttackState attackState;
    EntityGlobalState globalState;
};

#endif /* defined(__DotWar__EntityStateMachine__) */
