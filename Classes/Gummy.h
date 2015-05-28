
#ifndef __GUMMY_H__
#define __GUMMY_H__
#include "cocos2d.h"
#include "ACutSprite.h"
USING_NS_CC;

class Gummy : public ACutSprite
{
public:
	Gummy(void);
	virtual ~Gummy(void);
	static Gummy* create(PhysicsWorld* physicsWorld);
};

#endif