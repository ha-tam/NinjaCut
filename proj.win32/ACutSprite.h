
#ifndef ACUTSPRITE_H
#define ACUTSPRITE_H
#include "cocos2d.h"

USING_NS_CC;
using namespace std;
class gameScene;

class ACutSprite : public Sprite
{
public:
	enum e_SpritePath : int {
		PATH1 = 0,
		PATH2,
		PATH3,
		PATH4,
		PATH5
	};

public:
	
	ACutSprite(void);
	virtual ~ACutSprite(void);

	static ACutSprite* create(const string &path_name);

    void initOptions(PhysicsWorld* physicsWorld,
	const string &cut1, const string &cut2,
	const string &path_body, int pointsValue);
	void initPos(e_SpritePath);
	void test() {CCLOG("lol%s", "-- :D");}

	bool slice(PhysicsWorld& world, const PhysicsRayCastInfo& info, void* data);
    void addEvents();
    void onTouchEnded(Touch *touch, Event *event);

private:
	int				_sliceTag;
	PhysicsWorld	*_PhysicsWorld;
};

#endif