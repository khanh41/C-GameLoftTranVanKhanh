#include "SpaceShooter.h"
#include <Bullet.h>
#include <GameOverScene.h>
SpaceShooter::SpaceShooter(cocos2d::Scene* scene)
{
	this->scene = scene;
	Init();
}

SpaceShooter::~SpaceShooter()
{
}

void SpaceShooter::Init()
{
	auto spriteCache = SpriteFrameCache::getInstance();
	spriteCache->addSpriteFramesWithFile("spritelist.plist");
	auto spriteFrame = spriteCache->getSpriteFrameByName("1.png");
	m_sprite = Sprite::createWithSpriteFrame(spriteFrame);
	scene->addChild(m_sprite);
	Vector<SpriteFrame*> animFrames;
	for (int i = 1; i <= 8; i++) {
		std::string temp = std::to_string(i) + ".png";
		spriteFrame = spriteCache->getSpriteFrameByName(temp);
		animFrames.pushBack(spriteFrame);
	}
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	auto animate = Animate::create(animation);
	m_sprite->runAction(RepeatForever::create(animate));
}

void SpaceShooter::Update(FLOAT deltaTime)
{
	countTime += deltaTime;
	if (countTime >= 0.15f) {
		countTime = 0;
		Shoot();
	}
}

void SpaceShooter::Shoot()
{

	Bullet* bullet = new Bullet(this->scene);
	bullet->m_sprite->setPosition((this->m_sprite->getPosition()+Vec2(-1,50)));
	m_bullets.push_back(bullet);
	for (std::list<ObjectParent*>::iterator it = m_bullets.begin(); it != m_bullets.end(); ++it) {
		if ((*it)->m_sprite->getPosition().y >= Director::getInstance()->getVisibleSize().height) {
			delete (*it);
			m_bullets.remove((*it));
			it = m_bullets.begin();
		}
	}
}
int countt = 0;
void SpaceShooter::Collision(std::vector<Rock*> rocks) {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	for (std::vector<Rock*>::iterator it = rocks.begin(); it != rocks.end(); ++it) {
		if (m_sprite->getBoundingBox().containsPoint((*it)->m_sprite->getPosition()))
		{
			ResourceManager* rs = new ResourceManager();
			if (rs->score < countt) rs->setHighScore(countt);
			rs->setYourScore(countt);
			countt = 0;
			auto scene = GameOverScene::createScene();
			Director::getInstance()->replaceScene(scene);
		}
		else {
			for (std::list<ObjectParent*>::iterator bl = m_bullets.begin(); bl != m_bullets.end(); ++bl) {

				if ((*it)->m_sprite->getBoundingBox().containsPoint((*bl)->m_sprite->getPosition())
					|| (*it)->m_sprite->getPosition().y == 0)
				{
					if ((*it)->m_sprite->getPosition().y > 0) {

						if ((*it)->m_sprite->getPosition().y != 0) {
							auto spriteCache = SpriteFrameCache::getInstance();
							spriteCache->addSpriteFramesWithFile("spritelist.plist");
							auto spriteFrame = spriteCache->getSpriteFrameByName("1_0.png");
							auto bang = Sprite::createWithSpriteFrame(spriteFrame);
							bang->retain();
							bang->setPosition((*it)->m_sprite->getPosition());
							scene->addChild(bang);
							Vector<SpriteFrame*> animFrames;
							for (int i = 1; i <= 16; i++) {
								std::string temp = "1_" + std::to_string(i) + ".png";
								spriteFrame = spriteCache->getSpriteFrameByName(temp);
								animFrames.pushBack(spriteFrame);
							}
							auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
							auto animate = Animate::create(animation);
							bang->runAction(animate);
						}
					}
					auto move = MoveBy::create(2.0f, Vec2(0, -Director::getInstance()->getVisibleSize().height));
					(*bl)->m_sprite->removeFromParent();
					delete (*bl);
					m_bullets.remove((*bl));
					bl = m_bullets.begin();
					int x = cocos2d::RandomHelper::random_int(0, (int)(origin.x + visibleSize.width));
					(*it)->m_sprite->setPosition(x, origin.y + visibleSize.height);
					(*it)->m_sprite->runAction(move);
					countt++;
				}
			}
		}
	}
}
/*void SpaceShooter::Collision(std::vector<Rock*> rocks)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	FLOAT minX = this->m_sprite->getPosition().x - 20;
	FLOAT maxX = this->m_sprite->getPosition().x + 20;
	FLOAT minY = this->m_sprite->getPosition().y - 20;
	FLOAT maxY = this->m_sprite->getPosition().y + 20;


	for (std::vector<Rock*>::iterator it = rocks.begin(); it != rocks.end(); ++it) {
		if ((*it)->m_sprite->getPosition().x >= minX && (*it)->m_sprite->getPosition().x <= maxX
			&& (*it)->m_sprite->getPosition().y >= minY && (*it)->m_sprite->getPosition().y <= maxY)
		{
			auto scene = GameOverScene::createScene();
			Director::getInstance()->replaceScene(scene);
		}
		else {
			for (std::list<ObjectParent*>::iterator bl = m_bullets.begin(); bl != m_bullets.end(); ++bl) {
				FLOAT minBX = (*bl)->m_sprite->getPosition().x - 10;
				FLOAT maxBX = (*bl)->m_sprite->getPosition().x + 10;
				FLOAT minBY = (*bl)->m_sprite->getPosition().y - 10;
				FLOAT maxBY = (*bl)->m_sprite->getPosition().y + 10;

				if ((*it)->m_sprite->getPosition().x >= minBX && (*it)->m_sprite->getPosition().x <= maxBX
					&& (*it)->m_sprite->getPosition().y >= minBY && (*it)->m_sprite->getPosition().y <= maxBY)
				{
					(*bl)->m_sprite->removeFromParent();
					delete (*bl);
					m_bullets.remove((*bl));
					bl = m_bullets.begin();
					int x = cocos2d::RandomHelper::random_int(0, (int)(origin.x + visibleSize.width));
					(*it)->m_sprite->setPosition(x, origin.y + visibleSize.height);
				}
			}
		}
	}*/
