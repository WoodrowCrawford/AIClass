#include "Character.h"

Character(float x, float y, float collisionRadius, const char* spriteFilePath, float health = 1,
	float damage = 1, float maxSpeed = 1, float maxForce = 1) :Agent()
{
	m_health = health;
	m_damage = damage;
}