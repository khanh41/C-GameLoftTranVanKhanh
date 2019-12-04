#include "SpaceShooter.h"

SpaceShooter::SpaceShooter(cocos2d::Scene* scene)
{
}

SpaceShooter::~SpaceShooter()
{
}

void SpaceShooter::Init()
{
}

void SpaceShooter::Update(FLOAT deltaTime)
{
	count += deltaTime;
	if (count >= deltaTime) {
		count = 0;
		Shoot();
	}
}

void SpaceShooter::Shoot()
{
}

void SpaceShooter::Collision(std::vector<Rock*>)
{
}
