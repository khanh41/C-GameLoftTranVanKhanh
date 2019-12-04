
#include "SettingScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* SettingScene::createScene()
{
	return SettingScene::create();
}

bool SettingScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	return true;
}

