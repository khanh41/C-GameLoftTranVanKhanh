#include "GamePlayScene.h"

Scene* GamePlayScene::createScene()
{
	return GamePlayScene::create();
}

int countNext = 0;
bool GamePlayScene::onTouchBegan(Touch* touch, Event* event)
{
	
	auto move = MoveTo::create(0.5f, touch->getLocation());
	m_spaceShip->m_sprite->runAction(move);
	return true;

}

bool GamePlayScene::onTouchEnded(Touch* touch, Event* event)
{
	//auto move = MoveBy::create(0.5f, Vec2(50, 0));
	//m_spaceShip->m_sprite->runAction(move->reverse());
	return true;
}

bool GamePlayScene::onTouchMoved(Touch* touch, Event* event)
{
	auto location = touch->getLocation();
	auto move = MoveTo::create(0, location);
	m_spaceShip->m_sprite->runAction(move);
	return true;
}

bool GamePlayScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	countNext = 0;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	scheduleUpdate();
	background = ResourceManager::GetInstance()->GetSpriteById(8);
	background->removeFromParent();
	this->addChild(background, -1);
	background->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2.2));
	
	m_spaceShip = new SpaceShooter(this);
	m_spaceShip->m_sprite->setPosition(Vec2(origin.x + visibleSize.width / 2,0));
	auto move = MoveBy::create(2.0f, Vec2(0, 100));
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
	countNext += 1;
	CCLOG("log:%d", countNext);
	if (countTEMP >= 1) {
		GenerateRock();
		countTEMP = 0;
	}
	if (countNext == 200) {
		auto visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();
		auto move = MoveBy::create(20, -Vec2(0, origin.y + visibleSize.height));
		auto map = TMXTiledMap::create("D:/PracticeGameLoft/Tiled/untitled.tmx");
		map->setPosition(0, origin.y + visibleSize.height);
		addChild(map, -1);
		background->runAction(move);
		map->runAction(move->clone());
	}
}

void GamePlayScene::GenerateRock()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	int x = cocos2d::RandomHelper::random_int(0, (int)(origin.x + visibleSize.width));
	Rock* rock = new Rock(this);
	m_rocks.push_back(rock);
	rock->m_sprite->setPosition(x, origin.y + visibleSize.height);
}

