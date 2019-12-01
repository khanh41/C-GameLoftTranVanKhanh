#include "Loading.h"
#include<iostream>
#include <cocos\ui\CocosGUI.h>
Scene* Loading::createScene()
{
	return Loading::create();
}
void Loading::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
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

	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		CC_CALLBACK_1(Loading::menuCloseCallback, this));
	closeItem->setPosition(300, 300);
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	auto play = ui::Button::create("play_normal.png", "play_pressed.png");
	play->setPosition(Vec2(200,200));
	play->setTitleText("Play");
	play->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		auto scene = HelloWorld::createScene();
		Director::getInstance()->replaceScene(scene);
	});
	addChild(play);

	auto loadBG = Sprite::create("loadingbar_bg.png");
	loadBG->setPosition(200,100);
	addChild(loadBG);

	static auto load = ui::LoadingBar::create("loadingbar.png");
	load->setPosition(loadBG->getPosition());
	load->setPercent(0);
	load->setDirection(ui::LoadingBar::Direction::LEFT);
	addChild(load);	

	auto updateLoadingBar = CallFunc::create([]() {
		if (load->getPercent() < 100)
		{
			load->setPercent(load->getPercent() + 1);
		}

	});
	auto sqLoad = Sequence::createWithTwoActions(updateLoadingBar, DelayTime::create(0.1f));
	auto repeat = Repeat::create(sqLoad, 100);
	load->runAction(repeat);

	static auto textField = ui::TextField::create("Hello Cocos2d-x", "Arial", 30);
	textField->setMaxLengthEnabled(true);
	textField->setMaxLength(10);
	textField->setPasswordEnabled(true);
	textField->setPosition(Vec2(200, 70));
	textField->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
	{
		log("editing a TextField");
	});
	addChild(textField);

	return true;
}

void Loading::update(FLOAT deltaTime)
{
	count += deltaTime;
	if (count >= 10) {
		auto scene = HelloWorld::createScene();
		Director::getInstance()->replaceScene(scene);
	}
}
