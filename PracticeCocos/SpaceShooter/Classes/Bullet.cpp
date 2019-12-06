
#include "Bullet.h"
#include <ResourceManager.h>

Bullet::Bullet(cocos2d::Scene* scene)
{
	Init();
	m_sprite->setPosition(100, 150);
	auto move = MoveBy::create(1.0f, Vec2(0, 1000));
	m_sprite->setRotation(1.5);
	m_sprite->runAction(move);
	scene->addChild(m_sprite);
}

Bullet::~Bullet()
{
	delete m_sprite;
}

void Bullet::Init()
{
	m_sprite = ResourceManager::GetInstance()->DuplicateSprite(ResourceManager::GetInstance()->GetSpriteById(4));
}

void Bullet::Update(FLOAT deltaTime)
{
}
