#pragma once
#include "ABDecision.h"


class SeekDecision :
	public ABDecision
{
public:
	using ABDecision::ABDecision;
	void makeDecision(Agent* agent, float deltaTime)override;

};

