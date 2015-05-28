
#ifndef __BAG_H__
#define __BAG_H__
#include "cocos2d.h"
#include "ACutSprite.h"
USING_NS_CC;

class Bag : public ACutSprite
{
public:
	Bag(void);
	virtual ~Bag(void);
	static Bag* create(PhysicsWorld* physicsWorld);
};

#endif