#include "cocos2d.h"
#include"ui/CocosGUI.h"
USING_NS_CC;

class SettingScene : public cocos2d::Scene
{
public:
	Label* aboutUI;
	Sprite* backgroundUI;
	static ui::Slider* slider;
	static cocos2d::Scene* createScene();
	virtual bool init();
	void CreateSoundLayer(Ref*);
	void CreateAboutLayer(Ref*);
	void ChangePlayerName(Ref*);
	CREATE_FUNC(SettingScene);
};

