
#include "SettingScene.h"

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

void SettingScene::CreateSoundLayer(Ref*)
{
}

void SettingScene::CreateAboutLayer(Ref*)
{
}

void SettingScene::ChangePlayerName(Ref*)
{
}

