#include "Agent.h"
#include "Behaviour.h"

Agent::Agent() : Actor()
{
	m_force = { 0, 0 };
	m_maxForce = 1;
}

Agent::~Agent()
{
}

Agent::Agent(float x, float y, float collisionRadius, char icon, float maxSpeed, float maxForce) :
	Actor(x, y, collisionRadius, icon, maxSpeed)
{
	m_force = { 0, 0 };
	m_maxForce = maxForce;
}

void Agent::update(float deltatime)
{
	//Resets the force to be zero
	m_force = { 0, 0 };

	//TO DO: Update forces
	for (int i = 0; i < m_behaviours.size(); i++)
		m_behaviours[i]->update(this, deltatime);
	//Updated velocity with the new force
	setVelocity(getVelocity()  + m_force * deltatime);
	
	//Rotates the agent to face the direction it is moving
	updateFacing();

	Actor::update(deltatime);

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

void Agent::addForce(MathLibrary::Vector2 force)
{
	//Add the force given to the total force
	m_force = m_force + force;

	//If the total force is greater than the max force, set its magnitude to be the max force
	if (m_force.getMagnitude() > getMaxForce())
	{
		m_force = m_force.getNormalized() * getMaxForce();
	}
}

void Agent::addBehaviour(Behaviour* behaviour)
{
	if (behaviour)
		m_behaviours.push_back(behaviour);
}



