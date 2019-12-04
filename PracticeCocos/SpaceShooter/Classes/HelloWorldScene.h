#ifndef  _HELLOWORLD_SCENE_H_
#define  _HELLOWORLD_SCENE_H_
#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void update(FLOAT deltaTime); 
	void menuCloseCallback(Ref* pSender);
	CREATE_FUNC(HelloWorld);
};
#endif //_HELLOWORLD_SCENE_H_

