
#include "LoadingScene.h"

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

	ResourceManager* resource;
	resource->GetInstance();
	auto sprite = resource->GetSpriteById(1);
	sprite->removeFromParent();
	addChild(sprite, -1);
	return true;
}

void LoadingScene::update(FLOAT deltaTime)
{
}

