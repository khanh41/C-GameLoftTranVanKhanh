#include "cocos2d.h"

class Object
{
public:
	Sprite* m_sprite; // image Object
public:
	Object();
	~Object();
	virtual void Init() = 0; //	handles all game objects logic
	virtual void Update(FLOAT deltaTime) = 0; // setup initial values for object
};

