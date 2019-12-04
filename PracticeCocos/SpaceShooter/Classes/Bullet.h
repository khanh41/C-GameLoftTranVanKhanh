#include "cocos2d.h"
#include"Object.h"

class Bullet : public Object
{
public:
	Bullet(cocos2d::Scene* scene);
	~Bullet();
	void Init();
	void Update(FLOAT deltaTime);
};

