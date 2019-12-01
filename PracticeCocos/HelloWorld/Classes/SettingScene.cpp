#include "SettingScene.h"
#include<iostream>
#include <cocos\ui\CocosGUI.h>
Scene* SettingScene::createScene()
{
	return SettingScene::create();
}

void SettingScene::ClickItemAbout(Ref* pSender)
{
	auto scrollView = ui::ScrollView::create();
	scrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
	scrollView->setContentSize(Size(300, 200));
	scrollView->setInnerContainerSize(Size(1280, 2500));
	scrollView->setBounceEnabled(true);
	scrollView->setPosition(Vec2(200, 100));
	for (int i = 0; i < 50; i++)
	{
		auto label = Label::createWithSystemFont("line " + std::to_string(i), "Arial", 20);
		label->setPosition(Vec2(scrollView->getContentSize().width / 2, i * 50));
		scrollView->addChild(label);
	}
	addChild(scrollView);

	static auto textField = ui::TextField::create("Player name", "Arial", 30);
	textField->setMaxLengthEnabled(true);
	textField->setMaxLength(10);
	textField->setPasswordEnabled(true);
	textField->setPosition(Vec2(200, 50));
	textField->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
	{
		log("editing a TextField");
	});
	addChild(textField);

}
void SettingScene::ClickItemSound(Ref* pSender)
{
	auto checkbox = ui::CheckBox::create("checkbox_normal.png",
		"checkbox_pressed.png",
		"checkbox_checked.png",
		"checkbox_normal_disable.png",
		"checkbox_checked_disable.png");
	checkbox->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			log("checkbox 1 clicked");
			break;
		default:
			break;
		}
	});
	checkbox->setPosition(Vec2(200, 150));
	this->addChild(checkbox);

	static auto slider = ui::Slider::create();
	slider->loadBarTexture("slider_bar_bg.png");
	slider->loadSlidBallTextures("slider_ball_normal.png", "slider_ball_pressed.png", "slider_ball_disable.png");
	slider->loadProgressBarTexture("slider_bar_pressed.png");
	slider->setPercent(10);
	slider->setPosition(Vec2(200, 80));
	slider->addClickEventListener([](Ref* event) {
		log("Slider: %d", slider->getPercent());
	});
	addChild(slider);

}

bool SettingScene::init()
{
	if(!Scene::init()) return false;
	scheduleUpdate();
	
	auto itemSound = MenuItemFont::create("Sound", CC_CALLBACK_1(SettingScene::ClickItemSound, this));
	auto itemAbout = MenuItemFont::create("About", CC_CALLBACK_1(SettingScene::ClickItemAbout, this));
	auto menu = Menu::create(itemSound, itemAbout,nullptr);
	itemSound->setPosition(200, 200);
	itemAbout->setPosition(200, 300);
	menu->setPosition(0, 0);
	addChild(menu);

	return true;
}

void SettingScene::update(FLOAT deltaTime)
{
	count += deltaTime;
	if (count >= 30) {
		auto load = Loading::createScene();
		Director::getInstance()->replaceScene(load);
	}
}

