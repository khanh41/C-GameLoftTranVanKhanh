#include "GamePlayScene.h"

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

void GamePlayScene::GenerateRock()
{
}

void GamePlayScene::onTouchBegan(Touch*, Event*)
{
}

void GamePlayScene::onTouchEnded(Touch*, Event*)
{
}

bool GamePlayScene::onTouchMove(Touch*, Event*)
{
	return false;
}

