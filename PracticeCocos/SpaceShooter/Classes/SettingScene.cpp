
#include "SettingScene.h"
#include "ResourceManager.h"
#include <MainMenuScene.h>

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

	ResourceManager* resource = new ResourceManager;
	resource->Init("Data.bin");
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto getLabel = resource->GetLabelById(1);
	auto setting = Label::create("Setting", getLabel->getBMFontFilePath(), 100);
	setting->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 1.35));
	addChild(setting);

	auto sound = Label::create("Sound", getLabel->getBMFontFilePath(), 30);
	auto soundClick = MenuItemLabel::create(sound, CC_CALLBACK_1(SettingScene::CreateSoundLayer, this));
	soundClick->setPosition(setting->getPosition() + Vec2(0,-setting->getContentSize().height));

	auto about = Label::create("About", getLabel->getBMFontFilePath(), 30);
	auto aboutClick = MenuItemLabel::create(about, CC_CALLBACK_1(SettingScene::CreateAboutLayer, this));
	aboutClick->setPosition(soundClick->getPosition() + Vec2(0, -soundClick->getContentSize().height));

	auto name = Label::create("Player's Name", getLabel->getBMFontFilePath(),30);
	auto nameClick = MenuItemLabel::create(name, CC_CALLBACK_1(SettingScene::ChangePlayerName, this));
	nameClick->setPosition(aboutClick->getPosition() + Vec2(0, -aboutClick->getContentSize().height));

	auto myMenu = Menu::create(soundClick, aboutClick, nameClick, nullptr);
	myMenu->setPosition(0, 0);
	addChild(myMenu);

	auto settingClick = resource->GetButtonById(4);
	settingClick->setPosition(Vec2(origin.x + visibleSize.width - settingClick->getContentSize().width / 2,
		settingClick->getContentSize().height / 2));
	settingClick->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
	{
		if (type == ui::Widget::TouchEventType::ENDED) {
			auto scene = MainMenuScene::createScene();
			Director::getInstance()->replaceScene(scene);
		}
	});
	addChild(settingClick);


	return true;
}

void SettingScene::CreateSoundLayer(Ref* ref)
{
	ResourceManager* resource = new ResourceManager;
	resource->Init("Data.bin");
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto background = resource->GetSpriteById(8);
	background->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	this->addChild(background);

	auto about = resource->GetLabelById(1);
	about->setString("ABOUT\nNothing :))");
	about->setScale(3);
	about->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 1.2));
	addChild(about);
}

void SettingScene::CreateAboutLayer(Ref* ref)
{
	ResourceManager* resource = new ResourceManager;
	resource->Init("Data.bin");
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto background = resource->GetSpriteById(8);
	background->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	this->addChild(background);

	auto about = resource->GetLabelById(1);
	about->setString("Sound\nNothing :))");
	about->setScale(3);
	about->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 1.2));
	addChild(about);
}

void SettingScene::ChangePlayerName(Ref*)
{
}

