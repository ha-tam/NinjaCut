
#ifndef __CAT_H__
#define __CAT_H__
#include "cocos2d.h"
#include "ACutSprite.h"
USING_NS_CC;

class Cat : public ACutSprite
{
public:
	Cat(void);
	virtual ~Cat(void);
	static Cat* create(PhysicsWorld* physicsWorld);
};

#endif