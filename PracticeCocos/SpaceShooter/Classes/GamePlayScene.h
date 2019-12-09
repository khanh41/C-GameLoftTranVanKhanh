
#include "cocos2d.h"
#include<vector>
#include <SpaceShooter.h>

USING_NS_CC;

class GamePlayScene : public cocos2d::Scene
{
public:
	std::vector<Rock*> m_rocks;
	SpaceShooter* m_spaceShip;
	Sprite* background;
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void update(FLOAT deltaTime);
	void GenerateRock();
	virtual bool onTouchBegan(Touch*, Event*);
	virtual bool onTouchEnded(Touch*, Event*);
	virtual bool onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	CREATE_FUNC(GamePlayScene);
};

