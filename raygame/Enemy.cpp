#include "Enemy.h"
#include "Game.h"

Enemy::Enemy(float x, float y, float collisionRadius, const char* spriteFilePath, Agent* target, float heath, float damage, float maxSpeed, float maxForce)
	: Character(x, y, collisionRadius, spriteFilePath, heath, damage, maxSpeed, maxForce)
{
	setTarget(target);
}

void Enemy::update(float deltaTime)
{
	Character::update(deltaTime);
	if (getWorldPosition().x > 1024 / 32)
		setWorldPostion(MathLibrary::Vector2(0, getWorldPosition().y));

	if (getWorldPosition().x < 0)
		setWorldPostion(MathLibrary::Vector2(1024 / 32, getWorldPosition().y));
}
