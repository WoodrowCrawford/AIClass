#pragma once

class Agent;

//Abstract class for a
class Behaviour
{
public:

	virtual void update(Agent* agent, float deltaTime) = 0;
};