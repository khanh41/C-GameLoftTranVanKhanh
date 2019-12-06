#include "GameOverScene.h"
#include <ResourceManager.h>
#include <GamePlayScene.h>
#include <MainMenuScene.h>

Scene* GameOverScene::createScene()
{
	return GameOverScene::create();
}

bool GameOverScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = ResourceManager::GetInstance()->GetSpriteById(1);
	background->removeFromParent();
	background->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	addChild(background);

	auto getLabel = ResourceManager::GetInstance()->GetLabelById(1);
	getLabel->removeFromParent();
	auto gameOver = Label::create("Game Over",getLabel->getBMFontFilePath(),40);
	gameOver->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 1.2);
	addChild(gameOver);

	auto yourScore = Label::create("Your Score: "+std::to_string(ResourceManager::GetInstance()->score), getLabel->getBMFontFilePath(), 20);
	yourScore->setPosition(gameOver->getPosition() + Vec2(0, -20 - gameOver->getContentSize().width/2));
	addChild(yourScore);
	auto highScore = Label::create("High Score: " + std::to_string(ResourceManager::GetInstance()->getHighScore()), getLabel->getBMFontFilePath(), 20);
	highScore->setPosition(yourScore->getPosition() + Vec2(0, -20 ));
	addChild(highScore);

	auto reset = ResourceManager::GetInstance()->GetButtonById(2);
	reset->removeFromParent();
	reset->setPosition(gameOver->getPosition() + Vec2(-100, -20-gameOver->getContentSize().width));
	reset->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
	{
		if (type == ui::Widget::TouchEventType::ENDED) {
			auto scene = GamePlayScene::createScene();
			Director::getInstance()->replaceScene(scene);
		}
	});
	addChild(reset);
	
	auto home = ResourceManager::GetInstance()->GetButtonById(3);
	home->removeFromParent();
	home->setPosition(gameOver->getPosition() + Vec2(100, -20 - gameOver->getContentSize().width));
	home->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
	{
		if (type == ui::Widget::TouchEventType::ENDED) {
			auto scene = MainMenuScene::createScene();
			Director::getInstance()->replaceScene(scene);
		}
	});
	addChild(home);
	return true;
}

