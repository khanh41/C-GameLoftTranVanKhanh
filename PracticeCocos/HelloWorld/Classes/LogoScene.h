#ifndef __LOGO_SCENE_H__
#define __LOGO_SCENE_H__
#include"cocos2d.h"
#include"HelloWorldScene.h"
#include"Loading.h"
USING_NS_CC;
class LogoScene: public Scene
{
public:
	float count=0;
	static Scene* createScene();
	virtual bool init();
	void update(FLOAT deltaTime);
	CREATE_FUNC(LogoScene);

	Sprite *sprite1, *sprite2, *sprite3;
};
#endif // __LOGO_SCENE_H__

