
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

	ResourceManager* resource = new ResourceManager();
	auto sprite = resource->GetSpriteById(2);
	addChild(sprite);
	return true;
}

void LoadingScene::update(FLOAT deltaTime)
{
}

