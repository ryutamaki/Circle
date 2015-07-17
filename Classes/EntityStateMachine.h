//
//  EntityStateMachine.h
//  DotWar
//
//  Created by ryutamaki on 2015/07/16.
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
    READY,
    ATTAKING,
    COOL_DOWN,
};


class EntityStateMachine
{
public:
    EntityStateMachine();
    ~EntityStateMachine();

    // Getter
    EntityMoveState getMoveState();
    EntityAttackState getAttackState();

    void setMoveState(EntityMoveState moveState);
    void setAttackState(EntityAttackState attackState);

    // Function to change state
    // These functions return a result
    void stopMoving();
    void startMoving(EntityMoveState movingState);
    void readyToAttack();
    void startToAttack();
    void coolDownAttaking();
    void finishAttaking();

    bool canAttack();

private:
    EntityMoveState moveState;
    EntityAttackState attackState;

    void sendCurrentEntityState();

};

#endif /* defined(__DotWar__EntityStateMachine__) */
