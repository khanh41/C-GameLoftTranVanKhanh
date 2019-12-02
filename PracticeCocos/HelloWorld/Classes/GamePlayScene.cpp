#include "GamePlayScene.h"
Scene* GamePlayScene::createScene()
{
	return GamePlayScene::create();
}

bool GamePlayScene::onTouchMoved(Touch* touch, Event* event)
{
	auto moveBy = MoveBy::create(0.5f, Vec2(400, 100));
	player->runAction(moveBy);
	return true;
}
bool GamePlayScene::onTouchEnded(Touch* touch, Event* event)
{
	auto moveBy = MoveBy::create(0.5f, Vec2(400, 100));
	auto rotaBy = RotateBy::create(0, 180);
	auto sq = Sequence::create(rotaBy, moveBy->reverse(), rotaBy,nullptr);
	player->runAction(sq);
	return true;
}

void GamePlayScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
		auto moveBy = MoveBy::create(0.5f, Vec2(400, 100));
		player->runAction(moveBy);
	}
}

void GamePlayScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
		auto moveBy = MoveBy::create(0.5f, Vec2(400, 100));
		auto rotaBy = RotateBy::create(0, 180);
		auto sq = Sequence::create(rotaBy, moveBy->reverse(), rotaBy, nullptr);
		player->runAction(sq);
	}
}

bool GamePlayScene::init()
{
	if(!Scene::init()) return false;
	scheduleUpdate(); 
	auto spriteCache = SpriteFrameCache::getInstance();
	spriteCache->addSpriteFramesWithFile("spritelist.plist");
	auto spriteFrame = spriteCache->getSpriteFrameByName("logo__.png");
	player = Sprite::createWithSpriteFrame(spriteFrame);
	player->setPosition(200, 200);
	addChild(player);

	Vector<SpriteFrame*> animFrames;
	player = Sprite::create();
	player->setPosition(0, 100);
	player->setRotation(90);
	addChild(player);
	for (int i = 1; i <= 8; i++) {
		std::string temp = std::to_string(i) + ".png";
		spriteFrame = spriteCache->getSpriteFrameByName(temp);
		animFrames.pushBack(spriteFrame);
	}
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	auto animate = Animate::create(animation);
	
	player->runAction(RepeatForever::create(animate));

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GamePlayScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GamePlayScene::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	auto listenerKey = EventListenerKeyboard::create();
	listenerKey->onKeyPressed = CC_CALLBACK_2(GamePlayScene::onKeyPressed, this);
	listenerKey->onKeyReleased = CC_CALLBACK_2(GamePlayScene::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKey, this);


	return true;
}

void GamePlayScene::update(FLOAT deltaTime)
{
}

