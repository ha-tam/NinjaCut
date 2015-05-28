
#ifndef __PEN_H__
#define __PEN_H__
#include "cocos2d.h"
#include "ACutSprite.h"
USING_NS_CC;

class Pen : public ACutSprite
{
public:
	Pen(void);
	virtual ~Pen(void);
	static Pen* create(PhysicsWorld* physicsWorld);
};

#endif