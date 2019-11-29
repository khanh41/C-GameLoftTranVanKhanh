#ifndef __LOADING_SCENE_H__
#define __LOADING_SCENE_H__
#include"cocos2d.h"
#include"HelloWorldScene.h"
USING_NS_CC;
class Loading: public Scene
{
public:
	float count=0;
	static Scene* createScene();
	virtual bool init();
	void update(FLOAT deltaTime);
	CREATE_FUNC(Loading);

	Sprite *player;
};
#endif // __LOADING_SCENE_H__

