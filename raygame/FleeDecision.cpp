#include "FleeDecision.h"
#include "ComplexEnemy.h"

void FleeDecision::makeDecision(Agent* agent, float deltaTime)
{
	ComplexEnemy* enemy = dynamic_cast<ComplexEnemy*>(agent);

	//If enemy isn't nullptr give the enemy all behaviours
	//for future use
	if (enemy)
	{
		enemy->getSeek();
		enemy->getWander();
		enemy->getFlee();

	}

	//Checks to see if the enemy has low health
	if (enemy->getHealth() < 1)
	{
		//If the enemy has low health, the enemy will
		//begin to flee.
		enemy->getBehaviour<FleeBehaviour>();
	}
}
