#pragma once
#include "Behaviour.h"
#include <Vector2.h>

class SteeringBehaviour : public Behaviour
{
public:
	//Pure abraction
	virtual MathLibrary::Vector2 calculateForce(Agent* agent) = 0;
};