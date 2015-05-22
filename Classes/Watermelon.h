
#ifndef __WATERMELON_H__
#define __WATERMELON_H__
#include "cocos2d.h"
#include "ACutSprite.h"
USING_NS_CC;

class Watermelon : public ACutSprite
{
public:
	Watermelon(void);
	virtual ~Watermelon(void);
	static Watermelon* create(PhysicsWorld* physicsWorld);
};

#endif