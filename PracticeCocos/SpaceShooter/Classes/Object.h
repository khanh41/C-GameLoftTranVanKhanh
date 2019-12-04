#ifndef  _OBJECT_H_
#define  _OBJECT_H_
#include "cocos2d.h"

class Object
{
public:
	cocos2d::Sprite* m_sprite; // image Object
public:
	Object();
	~Object();
	virtual void Init() = 0; //	handles all game objects logic
	virtual void Update(FLOAT deltaTime) = 0; // setup initial values for object
};
#endif // _OBJECT_H_

