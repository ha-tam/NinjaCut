
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
	virtual void initOptions(PhysicsWorld* physicsWorld,
	const string &cut1, const string &cut2,
	const string &path_body, const string &bodyName,
	int pointsValue);
};

#endif