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
	sprite1 = Sprite::create("blue.png");
	sprite1->setPosition(150, 200);
	sprite1->setColor(Color3B().RED);
	auto actionMove = MoveBy::create(4, Vec2(100,0));
	auto actionRotation = RotateBy::create(4,360.0f);
	auto actionTint = TintBy::create(4,200.0f,200.0f,40.0f);
	auto actionFadeIn = FadeIn::create(4.0f);
	auto actionFadeOut = FadeOut::create(3);
	auto sequen = Spawn::create(actionMove, actionRotation,actionTint,actionFadeOut, actionFadeIn, nullptr);
	sprite1->runAction(RepeatForever::create(sequen));
	addChild(sprite1);


	sprite2 = Sprite::create();
	sprite2->setPosition(300, 100);
	addChild(sprite2);
	Vector<SpriteFrame*> anim;
	anim.pushBack(SpriteFrame::create("bee1.png", Rect(0, 0, 150, 150)));
	anim.pushBack(SpriteFrame::create("bee2.png", Rect(0, 0, 150, 150)));
	auto animate = Animate::create(Animation::createWithSpriteFrames(anim,0.1f));
	sprite2->runAction(RepeatForever::create(animate));

	sprite3 = Sprite::create("blue.png");
	sprite3->setPosition(200, 100);
	addChild(sprite3);

	auto move = MoveBy::create(2, Vec2(300, 100));
	auto moveEase = EaseElasticInOut::create(move->clone());
	auto moveback = moveEase->reverse();
	auto delay = DelayTime::create(0.5f);
	auto seq = Sequence::create(moveEase, delay, moveback,delay->clone(), nullptr);
	sprite3->runAction(RepeatForever::create(seq));
	return true;
}

void LogoScene::update(FLOAT deltaTime)
{
	count += 1;
	if (count >= 1000) {
		auto scene = HelloWorld::createScene();
		Director::getInstance()->replaceScene(scene);
	}
}
