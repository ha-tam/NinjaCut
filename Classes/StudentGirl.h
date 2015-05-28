
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
	virtual void initOptions(PhysicsWorld* physicsWorld,
	const string &cut1, const string &cut2,
	const string &path_body, const string &bodyName,
	int pointsValue);
};

#endif