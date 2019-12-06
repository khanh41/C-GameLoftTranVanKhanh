#include "cocos2d.h"
#include"ui/CocosGUI.h"

USING_NS_CC;

class MainMenuScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MainMenuScene);
};

