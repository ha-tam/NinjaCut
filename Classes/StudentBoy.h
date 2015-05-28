
#ifndef __STUDENTBOY_H__
#define __STUDENTBOY_H__
#include "cocos2d.h"
#include "ACutSprite.h"
USING_NS_CC;

class StudentBoy : public ACutSprite
{
public:
	StudentBoy(void);
	virtual ~StudentBoy(void);
	static StudentBoy* create(PhysicsWorld* physicsWorld);
};

#endif