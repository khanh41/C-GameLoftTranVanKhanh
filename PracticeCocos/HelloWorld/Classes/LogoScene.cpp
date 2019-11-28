#include "LogoScene.h"
#include<iostream>
Scene* LogoScene::createScene()
{
	return LogoScene::create();
}

bool LogoScene::init()
{
	if(!Scene::init()) return false;
	scheduleUpdate();
	return true;
}

void LogoScene::update(FLOAT deltaTime)
{
	count += 1;
	if (count >= 10) {
		auto scene = HelloWorld::createScene();
		Director::getInstance()->replaceScene(scene);
	}
}
