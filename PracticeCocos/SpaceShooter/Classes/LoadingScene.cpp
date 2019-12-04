
#include "LoadingScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

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
    return true;
}

