#ifndef __SETTING_SCENE_H__
#define __SETTING_SCENE_H__
#include"cocos2d.h"
#include"HelloWorldScene.h"
#include"Loading.h"
#include<iostream>
#include <cocos\ui\CocosGUI.h>
USING_NS_CC;
class SettingScene: public Scene
{
public:
	ui::CheckBox* checkbox;
	ui::Slider* slider;
	bool cls = true;
	float count=0;
	static Scene* createScene();
	virtual bool init();
	void update(FLOAT deltaTime);
	CREATE_FUNC(SettingScene);

	void ClickItemSound(Ref* pSender);
	void ClickItemAbout(Ref* pSender);
};
#endif // __Setting_SCENE_H__

