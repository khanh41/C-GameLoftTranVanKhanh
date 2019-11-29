#ifndef __LOAD_SCENE_H__
#define __LOAD_SCENE_H__
#include"cocos2d.h"
#include"HelloWorldScene.h"
USING_NS_CC;
class LogoScene: public Scene
{
public:
	int count=0;
	static Scene* createScene();
	virtual bool init();
	void update(FLOAT deltaTime);
	CREATE_FUNC(LogoScene);

	Sprite *sprite1, *sprite2, *sprite3;
};
#endif // __LOAD_SCENE_H__

