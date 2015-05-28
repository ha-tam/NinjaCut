
#ifndef __TEACHER_H__
#define __TEACHER_H__
#include "cocos2d.h"
#include "ACutSprite.h"
USING_NS_CC;

class Teacher : public ACutSprite
{
public:
	Teacher(void);
	virtual ~Teacher(void);
	static Teacher* create(PhysicsWorld* physicsWorld);
};

#endif