#pragma once
#include "Character.h"
class Enemy : public Character
{
public:

  /// <param name="x">Position on the x axis</param>
  /// <param name="y">Position on the y axis</param>
  /// <param name="icon">The symbol that will appear when drawn</param>
  /// <param name="maxForce">The largest the magnitude of the force the vector can be</param>
    Enemy(float x, float y, float collisionRadius, const char* spriteFilePath,
        Agent* target, float heath = 1, float damage = 1, float maxSpeed =1 , float maxForce = 1);


    void update(float deltaTime) override;
    virtual Actor* getTarget() { return m_target; }
    void setTarget(Agent* agent) { m_target = agent; }

private:
    Agent* m_target;
};

