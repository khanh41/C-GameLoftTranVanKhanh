
#include "MainMenuScene.h"
#include <ResourceManager.h>
#include <GamePlayScene.h>
#include <SettingScene.h>

Scene* MainMenuScene::createScene()
{
	return MainMenuScene::create();
}
bool MainMenuScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	ResourceManager* resource = new ResourceManager();
	resource->Init("Data.bin");
	auto background = resource->GetSpriteById(1);
	background->setPosition(origin.x+visibleSize.width/2, origin.y + visibleSize.height/2);
	addChild(background);

	auto logo = resource->GetSpriteById(2);
	logo->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 1.25);
	addChild(logo);

	auto play = resource->GetButtonById(1);
	play->setPosition(background->getPosition());
	play->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
	{
		if (type == ui::Widget::TouchEventType::ENDED) {
			auto scene = GamePlayScene::createScene();
			Director::getInstance()->replaceScene(scene);
		}
	});
	addChild(play);

	auto setting = resource->GetButtonById(4);
	setting->setPosition(Vec2(origin.x + visibleSize.width - setting->getContentSize().width / 2,
						setting->getContentSize().height/2));
	setting->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
	{
		if (type == ui::Widget::TouchEventType::ENDED) {
			auto scene = SettingScene::createScene();
			Director::getInstance()->replaceScene(scene);
		}
	});
	addChild(setting);
	return true;
}

