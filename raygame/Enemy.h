#pragma once
#include "Character.h"

class Enemy :
    public Character
{
public:

  
    Enemy(float x, float y, float collisionRadius, const char* spriteFilePath,
        Actor* target, float health = 1, float damage = 1, float maxSpeed = 1, float maxForce = 1);

    void update(float deltaTime) override;
    virtual Actor* getTarget() { return m_target; }
    virtual void setTarget(Actor* agent) { m_target = agent; }

private:
    Actor* m_target;
};

