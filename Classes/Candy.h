
#ifndef __CANDY_H__
#define __CANDY_H__
#include "cocos2d.h"
#include "ACutSprite.h"
USING_NS_CC;

class Candy : public ACutSprite
{
public:
	Candy(void);
	virtual ~Candy(void);
	static Candy* create(PhysicsWorld* physicsWorld);
};

#endif