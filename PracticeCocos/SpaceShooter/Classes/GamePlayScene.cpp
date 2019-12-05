#include "GamePlayScene.h"

Scene* GamePlayScene::createScene()
{
	return GamePlayScene::create();
}

bool GamePlayScene::onTouchBegan(Touch* touch, Event* event)
{
	auto move = MoveBy::create(0.5f, Vec2(50, 0));
	m_spaceShip->m_sprite->runAction(move);
	return true;

}

bool GamePlayScene::onTouchEnded(Touch* touch, Event* event)
{
	auto move = MoveBy::create(0.5f, Vec2(50, 0));
	m_spaceShip->m_sprite->runAction(move->reverse());
	return true;
}

bool GamePlayScene::onTouchMoved(Touch* touch, Event* event)
{
	auto move = MoveBy::create(0.5f, Vec2(50, 0));
	m_spaceShip->m_sprite->runAction(move);
	return true;
}

bool GamePlayScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	scheduleUpdate();
	m_spaceShip = new SpaceShooter(this);
	m_spaceShip->m_sprite->setPosition(100, 100);
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GamePlayScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GamePlayScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GamePlayScene::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	m_spaceShip->Update(0.1f);
	return true;

}

auto countTEMP = 0.0f;
void GamePlayScene::update(FLOAT deltaTime)
{
	m_spaceShip->Collision(m_rocks);
	m_spaceShip->Update(deltaTime);
	countTEMP += deltaTime;
	if (countTEMP >= 2) {
		GenerateRock();
		countTEMP = 0;
	}
}

void GamePlayScene::GenerateRock()
{
	int x = cocos2d::RandomHelper::random_int(1, 500);
	Rock* rock = new Rock(this);
	m_rocks.push_back(rock);
	rock->m_sprite->setPosition(x, 400);
}

