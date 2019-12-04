#include "cocos2d.h"

class SettingScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void CreateSoundLayer(Ref*);
	void CreateAboutLayer(Ref*);
	void ChangePlayerName(Ref*);
	CREATE_FUNC(SettingScene);
};

