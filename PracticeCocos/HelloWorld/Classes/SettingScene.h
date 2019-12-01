#ifndef __SETTING_SCENE_H__
#define __SETTING_SCENE_H__
#include"cocos2d.h"
#include"HelloWorldScene.h"
#include"Loading.h"
USING_NS_CC;
class SettingScene: public Scene
{
public:
	float count=0;
	static Scene* createScene();
	virtual bool init();
	void update(FLOAT deltaTime);
	CREATE_FUNC(SettingScene);

	void ClickItemSound(Ref* pSender);
	void ClickItemAbout(Ref* pSender);
};
#endif // __Setting_SCENE_H__

