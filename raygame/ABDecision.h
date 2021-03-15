#pragma once
#include "Decision.h"


//A decision that has two children attached to it 
class ABDecision :
	public Decision
{
public:

	ABDecision(Decision* leftChild = nullptr, Decision* rightChild = nullptr);


	//Checks the condition and translate
	virtual void makeDecision(Agent* agent, float deltaTime) override;

	virtual bool checkCondition(Agent* agent, float deltaTime) { return false; }


private:

	Decision* m_leftChild;
	Decision* m_rightChild;
};

