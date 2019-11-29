#include "Loading.h"
#include<iostream>
Scene* Loading::createScene()
{
	return Loading::create();
}

bool Loading::init()
{
	if(!Scene::init()) return false;
	scheduleUpdate();
	auto spriteCache = SpriteFrameCache::getInstance();
	spriteCache->addSpriteFramesWithFile("spritelist.plist");
	auto spriteFrame = spriteCache->getSpriteFrameByName("logo__.png");
	player = Sprite::createWithSpriteFrame(spriteFrame);
	player->setPosition(200, 200);
	addChild(player);

	Vector<SpriteFrame*> animFrames;
	player = Sprite::create();
	player->setPosition(0, 100);
	player->setRotation(90);
	addChild(player);
	for (int i = 1; i <= 8; i++) {
		std::string temp = std::to_string(i) + ".png";
		spriteFrame = spriteCache->getSpriteFrameByName(temp);
		animFrames.pushBack(spriteFrame);
	}
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	auto animate = Animate::create(animation);
	auto moveTo = MoveTo::create(6, Vec2(600, 100));
	player->runAction(RepeatForever::create(animate));
	player->runAction(moveTo);
	//auto player = Sprite::createWithSpriteFrameName("blue.png");


	return true;
}

void Loading::update(FLOAT deltaTime)
{
	count += deltaTime;
	if (count >= 5) {
		auto scene = HelloWorld::createScene();
		Director::getInstance()->replaceScene(scene);
	}
}
