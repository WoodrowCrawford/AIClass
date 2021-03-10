#pragma once
#include "Character.h"

class Player : public Character
{
public:

	Player(float x, float y, float collisionRadius, const char* spriteFilePath, float maxSpeed = 1, float maxForce = 1);
	void update(float deltatime) override;
	void debug() override;
};

