#include "ComplexEnemy.h"
#include "WanderBehaviour.h"
#include "SeekBehaviour.h"
#include "FleeBehaviour.h"
#include "Player.h"


void ComplexEnemy::start()
{
	Enemy::start();

	//Initialize behaviours
	m_wanderBehaviour = getBehaviour<WanderBehaviour>();
	m_seekBehaviour = getBehaviour<SeekBehaviour>();
	m_fleeBehaviour = getBehaviour<FleeBehaviour>();

	//Set target to target given from the base class
	setTarget(Enemy::getTarget());
}

void ComplexEnemy::setTarget(Actor* target)
{
	Enemy::setTarget(target);
	m_seekBehaviour->setTarget(target);
	m_fleeBehaviour->setTarget(target);
}


//What happpens when the enemy and player collide with each other
void ComplexEnemy::onCollision(Actor* other)
{
	Enemy::onCollision(other);

	Player* player = dynamic_cast<Player*>(other);

	//If the actor is a player, damage it
	if (player)
	{
		//If the player has died set the target to be null
		player->takeDamage(getDamage());
		if (player->getHealth() <= 0)
		{
			setTarget(nullptr);
		}
	}
}

//Checks to see if the target is in sight
bool ComplexEnemy::checkTargetInSight(float angle)
{
	//Check to see if target is null. If so return false 

	if (getTarget())
	{
		MathLibrary::Vector2 enemyForward;
		MathLibrary::Vector2 angle;

		//Find the direction vector that represents where the target is reletive to the enemy
		MathLibrary::Vector2 direction = getTarget()->getWorldPosition() - Agent::getWorldPosition();

		//Find the dot product of the enemy's forward and the direction vector
		angle.dotProduct(enemyForward, direction);

		//Find the angle using dot product


		//Check if the angle is greater than the enemy's
		if (angle.findAngle(angle, enemyForward))
		{
			return true;
		}


	}

}

//Check if the target is in range of the enemy
bool ComplexEnemy::checkTargetInRange(float range)
{
	if (getTarget())
	{
		MathLibrary::Vector2 enemyForward;
		MathLibrary::Vector2 range;

		//Find the direction vector that represents where the target is reletive to the enemy
		MathLibrary::Vector2 direction = getTarget()->getWorldPosition() - Agent::getWorldPosition();

		//Find the dot product of the enemy's forward and the direction vector
		range.dotProduct(enemyForward, direction);

		//Find the angle using dot product


		//Check if the angle is greater than the enemy's
		if (range.findAngle(range, enemyForward))
		{
			return true;
		}


	};

}
