#pragma once
#include "Decision.h"

///<summary>
///A decision that has two children attached to it
///</summary>
class ABDecision :
	public Decision
{
public:
	ABDecision(Decision* leftChild = nullptr, Decision* rightChild = nullptr);

	///<summary>
	///Checks the condition and transitions to a different decision based on the return value
	///</summary>
	virtual void makeDecision(Agent* agent, float deltaTime) override;

	///<summary>
	/// Checks if a certain condition has been met and returns the result
	///</summary>
	virtual bool checkCondition(Agent* agent, float deltaTime) { return false; }

private:
	Decision* m_leftChild;
	Decision* m_rightChild;
};
