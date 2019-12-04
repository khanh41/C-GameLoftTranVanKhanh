#include "cocos2d.h"
#include<list>
#include<vector>
#include "Rock.h"
#include"Object.h"

class SpaceShooter: public Object
{
public:
	float count = 0;
	std::list<Object*> m_bullets;
public:
	SpaceShooter(cocos2d::Scene* scene);
	~SpaceShooter();
	void Init();
	void Update(FLOAT deltaTime);
	void Shoot();
	void Collision(std::vector<Rock*>);
};

