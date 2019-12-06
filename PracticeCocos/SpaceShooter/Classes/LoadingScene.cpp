
#include "LoadingScene.h"
#include <GamePlayScene.h>
#include <MainMenuScene.h>

Scene* LoadingScene::createScene()
{
    return LoadingScene::create();
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
	auto loadBG = resource->GetSpriteById(6);
	loadBG->setPosition(Vec2(origin.x + visibleSize.width / 2,
						origin.y + visibleSize.height/2));
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

	return true;
}
void LoadingScene::update(FLOAT deltaTime)
{
	countT += deltaTime;
	if (countT >= 3) {
		auto scene = MainMenuScene::createScene();
		Director::getInstance()->replaceScene(scene);
	}
}

