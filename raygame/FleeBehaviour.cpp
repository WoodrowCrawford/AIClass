#include "FleeBehaviour.h"
#include "Agent.h"	
#include "Actor.h"

FleeBehaviour::FleeBehaviour()
{
	m_target = nullptr;
	m_fleeForce = 1;
}

FleeBehaviour::FleeBehaviour(Actor* target, float fleeForce)
{
	m_target = target;
	m_fleeForce = fleeForce;
}



MathLibrary::Vector2 FleeBehaviour::calculateForce(Agent* agent)
{
	//Find the direction to run to 
	MathLibrary::Vector2 direction = MathLibrary::Vector2::normalize(agent->getWorldPosition() - m_target->getWorldPosition());

	//Scale the direction vector by the FleeForce
	MathLibrary::Vector2 desiredVelocity = direction * m_fleeForce;

	//Subtract current velocity from desired velocity to find steering force
	MathLibrary::Vector2 steeringForce = desiredVelocity - agent->getVelocity();

	return steeringForce;
}

void FleeBehaviour::update(Agent* agent, float deltaTime)
{
	//If the agent is not null, calculate a new force and apply it to the agent
	if (agent)
	{
		agent->addForce(calculateForce(agent));
	}
}
