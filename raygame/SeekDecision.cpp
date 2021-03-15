#include "SeekDecision.h"
#include "ComplexEnemy.h"

void SeekDecision::makeDecision(Agent* agent, float deltaTime)
{
	ComplexEnemy* enemy = dynamic_cast<ComplexEnemy*>(agent);

	if (enemy)
	{
		enemy->getSeek()->setEnabled(true);
		enemy->getWander()->setEnabled(true);
		enemy->getFlee()->setEnabled(true);
	}
}
