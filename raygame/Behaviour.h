#pragma once

class Agent;

//Abstract class for all behaviours
class Behaviour
{
public:

	//Pure abstraction
	virtual void update(Agent* agent, float deltaTime) = 0;
};