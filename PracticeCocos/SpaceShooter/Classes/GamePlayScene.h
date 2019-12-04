
#include "cocos2d.h"
#include<vector>
#include <SpaceShooter.h>

USING_NS_CC;

class GamePlayScene : public cocos2d::Scene
{
public:
	std::vector<Rock*> m_rocks;
	SpaceShooter* m_spaceShip;
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void update(FLOAT deltaTime);
	void GenerateRock();
	void onTouchBegan(Touch*, Event*);
	void onTouchEnded(Touch*, Event*);
	bool onTouchMove(Touch*, Event*);
	CREATE_FUNC(GamePlayScene);
};

