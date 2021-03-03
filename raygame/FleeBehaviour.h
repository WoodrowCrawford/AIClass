#pragma once
#include "SteeringBehaviour.h"

class Actor;
class FleeBehaviour : public SteeringBehaviour
{
public:
	FleeBehaviour();
	FleeBehaviour(Actor* target, float fleeForce = 1);

	Actor* getTarget() { return m_target; }
	void setTarget(Actor* target) { m_target = target; }


	MathLibrary::Vector2 calculateForce(Agent* agent) override;
	void update(Agent* agent, float deltaTime) override;

private:
	//The agent the behaviour is fleeing fro,
	Actor* m_target;
	float m_fleeForce;
};

