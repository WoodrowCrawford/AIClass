#include "SimpleEnemy.h"
#include "SeekBehaviour.h"
#include "WanderBehaviour.h"

bool SimpleEnemy::checkTargetInSight()
{
	//Check to see if target is null. If so return false 
	if (getTarget() != NULL)
	{

		//Find the direction vector that represents where the target is reletive to the enemy
		MathLibrary::Vector2 direction = getTarget()->getWorldPosition() - Agent::getWorldPosition();

		//Find the dot product of the enemy's forward and the direction vector
		MathLibrary::Vector2 enemyForward = Enemy::getForward();
		enemyForward.dotProduct(direction, enemyForward);

		//Find the angle using dot product
	
		
		direction.getNormalized();

		//Check if the angle is greater than the enemy's
		 
		
		//if (direction.getNormalized() > enemyForward.getNormalized())
		//{
			//return true;
		//}
		
	}
	
 
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
	m_currentState = WANDER;

	//Initialize member variables
	m_seek = getBehaviour<SeekBehaviour>();
	m_wander = getBehaviour<WanderBehaviour>();

	setTarget(Enemy::getTarget());
}

void SimpleEnemy::update(float deltaTime)
{
	//Create a switch statement for the state machine
	
	
	//The switch should transition to the wander state if the target is not in sight.
	//You can set the wander force to be whatever value you see fit but be sure to
	//set the seek force to be 0.
	
	//The switch should transition to the seek 
}

void SimpleEnemy::setTarget(Actor* target)
{
	Enemy::setTarget(target);
	m_seek->setTarget(target);
}
