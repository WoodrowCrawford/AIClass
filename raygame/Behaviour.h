#pragma once

class Agent;

//Abstract class for all behaviours
class Behaviour
{
public:

	//Pure abstraction
	virtual void update(Agent* agent, float deltaTime) = 0;
	virtual void draw(Agent* agent) {};

	bool getEnabled() { return m_enabled; }
	void setEnabled(bool enabled) { m_enabled = enabled; }

private:
	bool m_enabled = true;
};