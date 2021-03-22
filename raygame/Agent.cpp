#include "Agent.h"
#include "Behaviour.h"

Agent::Agent() : Actor()
{
	m_force = { 0, 0 };
	m_maxForce = 1;
}

Agent::Agent(float x, float y, float collisionRadius, char icon, float maxSpeed, float maxForce) :
	Actor(x, y, collisionRadius, icon, maxSpeed)
{
	m_force = { 0, 0 };
	m_maxForce = maxForce;
}

Agent::Agent(float x, float y, float collisionRadius, Sprite* sprite, float maxSpeed, float maxForce) :
	Actor(x, y, collisionRadius, sprite, maxSpeed)
{
	m_force = { 0, 0 };
	m_maxForce = maxForce;
}

Agent::Agent(float x, float y, float collisionRadius, const char* spriteFilePath, float maxSpeed, float maxForce) :
	Actor(x, y, collisionRadius, spriteFilePath, maxSpeed)
{
	m_force = { 0, 0 };
	m_maxForce = maxForce;
}

void Agent::update(float deltatime)
{
	//Reset force to be zero
	m_force = { 0,0 };

	//Call update for each behaviour in the list
	for (int i = 0; i < m_behaviours.size(); i++)
	{
		if (m_behaviours[i]->getEnabled())
			m_behaviours[i]->update(this, deltatime);
	}

	//Updates velocity with the new force
	setVelocity(getVelocity() + m_force * deltatime);

	//Rotates the agent to face the direction its moving in
	updateFacing();

	Actor::update(deltatime);
}

void Agent::addForce(MathLibrary::Vector2 force)
{
	//Add the force given to the total force
	m_force = m_force + force;

	//If the total force is greater than the max force, set its magnitude to be the max force
	if (m_force.getMagnitude() > getMaxForce())
		m_force = m_force.getNormalized() * getMaxForce();
}

void Agent::addBehaviour(Behaviour* behaviour)
{
	if (behaviour)
		m_behaviours.push_back(behaviour);
}