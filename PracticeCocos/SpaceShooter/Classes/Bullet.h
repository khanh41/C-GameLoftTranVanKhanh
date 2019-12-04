#include "cocos2d.h"

class Bullet : public Object
{
public:
	Bullet(Scene* scene);
	~Bullet();
	void Init();
	void Update(FLOAT deltaTime);
};

