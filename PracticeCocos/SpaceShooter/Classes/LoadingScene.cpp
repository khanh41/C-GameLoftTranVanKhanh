
#include "LoadingScene.h"
#include <GamePlayScene.h>

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
	ResourceManager* resource = new ResourceManager();
	resource->Init("Data.bin");
	auto loadBG = resource->GetSpriteById(6);
	loadBG->setPosition(250, 150);
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
		auto scene = GamePlayScene::createScene();
		Director::getInstance()->replaceScene(scene);
	}
}

