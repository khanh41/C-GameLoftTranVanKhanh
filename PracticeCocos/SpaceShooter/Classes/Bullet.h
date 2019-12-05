#include "cocos2d.h"
#include"ObjectParent.h"
class Bullet : public ObjectParent
{
public:
	Bullet(cocos2d::Scene*);
	~Bullet();
	void Init();
	void Update(FLOAT deltaTime);
};

