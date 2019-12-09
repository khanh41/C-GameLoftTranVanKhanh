#include "SettingScene.h"
#include "ResourceManager.h"
#include <MainMenuScene.h>
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

bool aboutClick = false;
ui::Slider* SettingScene::slider;
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

	this->aboutUI = ResourceManager::GetInstance()->GetLabelById(1);
	this->slider = ui::Slider::create();
	this->backgroundUI = ResourceManager::GetInstance()->GetSpriteById(8);
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	backgroundUI->removeFromParent();
	backgroundUI->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	this->addChild(backgroundUI, 1);
	backgroundUI->setVisible(false);

	aboutUI->removeFromParent();
	aboutUI->setString("Sound\nNothing :))");
	aboutUI->setScale(3);
	aboutUI->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 1.2));
	addChild(aboutUI, 1);
	aboutUI->setVisible(false);

	slider->loadBarTexture("slider_bar_bg.png");
	slider->loadSlidBallTextures("slider_ball_normal.png", "slider_ball_pressed.png", "slider_ball_disable.png");
	slider->loadProgressBarTexture("slider_bar_pressed.png");
	slider->setPercent(10);
	slider->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	addChild(slider, 1);
	slider->setVisible(false);

	auto getLabel = ResourceManager::GetInstance()->GetLabelById(1);
	getLabel->removeFromParent();
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

	auto settingClick = ResourceManager::GetInstance()->GetButtonById(4);
	settingClick->removeFromParent();
	settingClick->setPosition(Vec2(origin.x + visibleSize.width - settingClick->getContentSize().width / 2,
		settingClick->getContentSize().height / 2));
	settingClick->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
	{
		if (type == ui::Widget::TouchEventType::ENDED) {
			auto scene = MainMenuScene::createScene();
			Director::getInstance()->pushScene(this);
			Director::getInstance()->replaceScene(scene);
		}
	});
	addChild(settingClick,2);


	return true;
}

void SettingScene::CreateSoundLayer(Ref* ref)
{
	auto audio = SimpleAudioEngine::getInstance();
	backgroundUI->setVisible(true);
	aboutUI->setVisible(true);
	slider->setVisible(true);
	slider->setPercent(audio->getBackgroundMusicVolume());
	slider->addClickEventListener([](Ref* event) {
		log("Slider: %f", slider->getPercent()/100.0f);
	});
	audio->setEffectsVolume(slider->getPercent() / 100.0f);
	audio->setBackgroundMusicVolume(slider->getPercent() / 100.0f);
}

void SettingScene::CreateAboutLayer(Ref* ref)
{
		
}

void SettingScene::ChangePlayerName(Ref*){}

