
#include "GamePlayScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* GamePlayScene::createScene()
{
	return GamePlayScene::create();
}

bool GamePlayScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	return true;
}

float count = 0;
void GamePlayScene::update(FLOAT deltaTime)
{
	count += deltaTime;
	if (count >= 0.2) {
		GenerateRock();
	}
}

