#include "cocos2d.h"

class LoadingScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void update(FLOAT deltaTime);
	CREATE_FUNC(LoadingScene);
};

