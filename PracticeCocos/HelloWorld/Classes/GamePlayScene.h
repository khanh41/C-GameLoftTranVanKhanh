#ifndef __GAMEPLAY_SCENE_H__
#define __GAMEPLAY_SCENE_H__
#include"cocos2d.h"
#include"HelloWorldScene.h"
#include"Loading.h"
#include<iostream>
#include <cocos\ui\CocosGUI.h>
USING_NS_CC;
class GamePlayScene: public Scene
{
public:
	static Scene* createScene();
	virtual bool init();
	void update(FLOAT deltaTime);
	CREATE_FUNC(GamePlayScene);
	virtual bool onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual bool onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

	Sprite* player;
};
#endif // __GAMEPLAY_SCENE_H__

