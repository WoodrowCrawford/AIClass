#include "WanderBehaviour.h"
#include "Agent.h"	
#include "Actor.h"
#include "raylib.h"


WanderBehaviour::WanderBehaviour()
{
	m_target = nullptr;
	m_seekForce = 1;
}

WanderBehaviour::WanderBehaviour(Actor* target, float seekForce)
{
	m_target = target;
	m_seekForce = seekForce;
}

MathLibrary::Vector2 WanderBehaviour::calculateForce(Agent* agent)
{
	//Makes a circle distance in front of the Agent
	MathLibrary::Vector2 cirleDistance = agent->getForward() * 30;

	//MathLibrary::Vector2 cirleDistanceX = MathLibrary::Vector2::normalize(cirleDistance + agent->getForward());
	//MathLibrary::Vector2 cirleDistanceY = MathLibrary::Vector2::normalize(cirleDistance - agent->getVelocity());


	//Find the direction to move in
	MathLibrary::Vector2 direction = MathLibrary::Vector2::normalize(cirleDistance - agent->getWorldPosition() *2);
	
	


	//Scale the direction vector by the seekForce
	MathLibrary::Vector2 desiredVelocity = direction * m_seekForce;

	//Subtract current velocity from desired velocity to find steering force
	MathLibrary::Vector2 steeringForce = desiredVelocity - agent->getVelocity();


	return steeringForce;
}

void WanderBehaviour::update(Agent* agent, float deltaTime)
{
	//If the agent is not null, calculate a new force and apply it to the agent
	if (agent)
	{
		agent->addForce(calculateForce(agent));
		
	}
}
