#include "cocos2d.h"
#include<list>
#include<vector>
#include "Rock.h"
#include"ObjectParent.h"

class SpaceShooter: public ObjectParent
{
public:
	cocos2d::Scene* scene;
	FLOAT countTime = 0;
	std::list<ObjectParent*> m_bullets;
	Label* CountScore;
public:
	SpaceShooter(cocos2d::Scene*);
	~SpaceShooter();
	void Init();
	void Update(FLOAT deltaTime);
	void Shoot();
	void Collision(std::vector<Rock*>);
};

