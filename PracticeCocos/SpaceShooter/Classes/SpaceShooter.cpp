#include "SpaceShooter.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
float count = 0;
void SpaceShooter::Update(FLOAT deltaTime)
{
	count += deltaTime;
	if (count >= deltaTime) {
		count = 0;
		Shoot();
	}
}
