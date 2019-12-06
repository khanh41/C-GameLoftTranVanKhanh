
#include "LoadingScene.h"
#include <GamePlayScene.h>
#include <MainMenuScene.h>

Scene* LoadingScene::createScene()
{
    return LoadingScene::create();
}
void LoadingScene::changScene(float deltaTime) {
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene, Color3B(0, 255, 255)));
}

bool LoadingScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
	scheduleUpdate();
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	ResourceManager* resource = new ResourceManager();
	resource->Init("Data.bin");

	auto background = resource->GetSpriteById(8);
	background->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2.2));
	this->addChild(background, -1);

	auto getLabel = resource->GetLabelById(1);
	auto loading = Label::create("Loading...", getLabel->getBMFontFilePath(), 40);
	loading->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	addChild(loading);

	auto loadBG = resource->GetSpriteById(6);
	loadBG->setPosition(loading->getPosition()+Vec2(0,-40));
	addChild(loadBG);
	static auto load = ui::LoadingBar::create("progress.png");
	load->setPosition(loadBG->getPosition());
	load->setPercent(0);
	load->setDirection(ui::LoadingBar::Direction::LEFT);
	addChild(load);

	auto updateLoadingBar = CallFunc::create([]() {
		if (load->getPercent() < 100)
		{
			load->setPercent(load->getPercent() + 3);
		}

	});
	auto sqLoad = Sequence::createWithTwoActions(updateLoadingBar, DelayTime::create(0.1f));
	auto repeat = Repeat::create(sqLoad, 100);
	load->runAction(repeat);
	this->schedule(schedule_selector(LoadingScene::changScene), 3.0f);
	return true;
}
void LoadingScene::update(FLOAT deltaTime)
{
}

