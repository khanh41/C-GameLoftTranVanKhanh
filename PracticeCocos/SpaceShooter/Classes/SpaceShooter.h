#include "cocos2d.h"
#include<list>
#include<vector>
#include <Rock.h>

class SpaceShooter: public Object
{
public:
	std::list<Object*> m_bullets;
public:
	SpaceShooter();
	~SpaceShooter();
	void Init();
	void Update(FLOAT deltaTime);
	void Shoot();
	void Collision(std::vector<Rock*>);
};

