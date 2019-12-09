#include "SpaceShooter.h"
#include <Bullet.h>
#include <GameOverScene.h>
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

auto audio = SimpleAudioEngine::getInstance();
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
float countLevel = 0;
void SpaceShooter::Update(FLOAT deltaTime)
{
	countLevel += deltaTime;
	countTime += deltaTime;
	if (countTime >= 0.15f) {
		countTime = 0;
		Shoot();
		audio->playEffect("fire.wav", false, 1.0f, 1.0f, 1.0f);
	}
	if (countLevel >= 5) {
		auto emitter = ParticleSnow::create();
		scene->addChild(emitter);
		emitter->setDuration(2.0f);
		countLevel = 0;
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
			if (ResourceManager::GetInstance()->getHighScore() < countt) ResourceManager::GetInstance()->setHighScore(countt);
			ResourceManager::GetInstance()->setYourScore(countt);
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
							audio->playEffect("Sounds/killed.wav", false, 1.0f, 1.0f, 1.0f);
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
					if (m_bullets.size() == 0) break;
				}
			}
		}
	}
}
