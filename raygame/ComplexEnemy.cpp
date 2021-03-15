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

bool ComplexEnemy::checkTargetInSight(float angle)
{
	return false;
}

bool ComplexEnemy::checkTargetInRange(float range)
{
	return false;
}
