
#ifndef __POTATOES_H__
#define __POTATOES_H__
#include "cocos2d.h"
#include "ACutSprite.h"
USING_NS_CC;

class Potatoes : public ACutSprite
{
public:
	Potatoes(void);
	virtual ~Potatoes(void);
	static Potatoes* create(PhysicsWorld* physicsWorld);
};

#endif