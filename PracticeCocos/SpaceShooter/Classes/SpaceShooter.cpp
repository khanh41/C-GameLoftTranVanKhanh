#include "SpaceShooter.h"
#include <Bullet.h>
#include <GameOverScene.h>

SpaceShooter::SpaceShooter(cocos2d::Scene* scene)
{
	this->scene = scene;
	Init();
	scene->addChild(m_sprite);
}

SpaceShooter::~SpaceShooter()
{
}

void SpaceShooter::Init()
{
	ResourceManager* resource = new ResourceManager();
	resource->Init("Data.bin");
	m_sprite = resource->GetSpriteById(5);
}

void SpaceShooter::Update(FLOAT deltaTime)
{
	countTime += deltaTime;
	if (countTime >= 0.25f) {
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

void SpaceShooter::Collision(std::vector<Rock*> rocks)
{
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
					delete (*bl);
					m_bullets.remove((*bl));
					bl = m_bullets.begin();
				}
			}
		}
	}
}
