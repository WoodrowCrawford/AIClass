#pragma once

class Agent;
	
class Decision
{
public:
	virtual void makeDecision(Agent* agent, float deltaTime) = 0;
};