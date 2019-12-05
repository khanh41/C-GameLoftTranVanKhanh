#include "cocos2d.h"
#include"ObjectParent.h"
#include"ResourceManager.h"
#include"LoadingScene.h"
class Rock : public ObjectParent
{
public:
	cocos2d::Scene* scene;
	Rock(cocos2d::Scene*);
	~Rock();
	void Init();
	void Update(FLOAT deltaTime);
};

