#include "SeekDecision.h"
#include "ComplexEnemy.h"

void SeekDecision::makeDecision(Agent* agent, float deltaTime)
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
	if (enemy->checkTargetInSight())
	{
		enemy->getBehaviour<SeekBehaviour>();
	}
	
}
