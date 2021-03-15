#pragma once
#include "Enemy.h"

class WanderBehaviour;
class SeekBehaviour;
class FleeBehaviour;

class ComplexEnemy :
	public Enemy
{
public:

	using Enemy::Enemy;
	void start()override;

	void setTarget(Actor* target) override;
	void onCollision(Actor* other)override;

	WanderBehaviour* getWander() { return m_wanderBehaviour; }	
	SeekBehaviour* getSeek() { return m_seekBehaviour; }
	FleeBehaviour* getFlee() { return m_fleeBehaviour; }

	bool checkTargetInSight(float angle = 2);
	bool checkTargetInRange(float range);

private:

	WanderBehaviour* m_wanderBehaviour;
	SeekBehaviour* m_seekBehaviour;
	FleeBehaviour* m_fleeBehaviour;
};

