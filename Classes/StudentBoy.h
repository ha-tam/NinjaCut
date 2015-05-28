
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
	virtual void initOptions(PhysicsWorld* physicsWorld,
	const string &cut1, const string &cut2,
	const string &path_body, const string &bodyName,
	int pointsValue);
};

#endif