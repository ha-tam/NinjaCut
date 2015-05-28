
#ifndef __STUDENTGIRL_H__
#define __STUDENTGIRL_H__
#include "cocos2d.h"
#include "ACutSprite.h"
USING_NS_CC;

class StudentGirl : public ACutSprite
{
public:
	StudentGirl(void);
	virtual ~StudentGirl(void);
	static StudentGirl* create(PhysicsWorld* physicsWorld);
};

#endif