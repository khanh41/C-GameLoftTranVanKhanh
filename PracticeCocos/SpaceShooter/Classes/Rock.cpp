
#include "Rock.h"

Rock::Rock(cocos2d::Scene* scene)
{
	Init();
	auto move = MoveBy::create(2.0f, Vec2(0, -Director::getInstance()->getVisibleSize().height));
	m_sprite->setRotation(2);
	m_sprite->runAction(move);
	scene->addChild(m_sprite);
}

Rock::~Rock()
{
	delete m_sprite;
}

void Rock::Init()
{
	ResourceManager* resource = new ResourceManager();
	resource->Init("Data.bin");
	m_sprite = resource->GetSpriteById(4);
}

void Rock::Update(FLOAT deltaTime)
{
	
}
