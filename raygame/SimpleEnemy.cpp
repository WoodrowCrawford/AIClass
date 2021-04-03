#include "SimpleEnemy.h"
#include "SeekBehaviour.h"
#include "WanderBehaviour.h"

bool SimpleEnemy::checkTargetInSight()
{
	//checks if target is null. if so return false
	if (getTarget() == NULL)
		return false;
	//find the direction vector that represent where the target is relative to the enemy
	MathLibrary::Vector2 direction = getTarget()->getWorldPosition() - getWorldPosition();

	//find the dot product of the enemy's forward and direction vector
	MathLibrary::Vector2::dotProduct(getTarget()->getForward(), direction);

	//find the angle using the dot product 
	float angle = (float)MathLibrary::Vector2::findAngle(getTarget()->getForward(), direction);

	//check if that angle is greater than the enemy's  viewing angle(any value you see fit is fine)
	if (angle > 2)
		//returns if the enemy saw something
		return true;
	//returns if the enemy saw nothing
	return false;
}

void SimpleEnemy::onCollision(Actor* other)
{
	//Check to see if the enemy ran into the player

	//If enemy has ran into the player, deal damage to the player

 //If the player's health is less than 0, set the target to null pointer
}

void SimpleEnemy::start()
{
	//Call base start function
	Enemy::start();

	//Set the default state of the enemy
	m_currentState = STATE_WANDER;

	//Initialize member variables
	m_seek = getBehaviour<SeekBehaviour>();
	m_wander = getBehaviour<WanderBehaviour>();

	setTarget(Enemy::getTarget());
}

void SimpleEnemy::update(float deltaTime)
{

	//Create a switch statement for the state machine

	switch (EnemyState::STATE_SEEK, EnemyState::STATE_WANDER)
	{
	case STATE_SEEK:
		if (checkTargetInSight() == true)
		{
			m_currentState = STATE_SEEK;
		}
		break;

	case STATE_WANDER:
		if (checkTargetInSight() == false)
		{
			m_currentState = STATE_WANDER;
			m_seek->setForceScale(0);
			m_wander->setForceScale(3);
			break;
		}


		//The switch should transition to the wander state if the target is not in sight.
		//You can set the wander force to be whatever value you see fit but be sure to
		//set the seek force to be 0.

		//The switch should transition to the seek 
	}

	Enemy::update(deltaTime);
}

void SimpleEnemy::setTarget(Actor* target)
{
	Enemy::setTarget(target);
	m_seek->setTarget(target);
}
