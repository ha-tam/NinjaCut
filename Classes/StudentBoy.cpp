#include "StudentBoy.h"
#include "zOrder.h"
#include "gameScene.h"

StudentBoy::StudentBoy(void) {}

StudentBoy::~StudentBoy(void) {}

StudentBoy* StudentBoy::create(PhysicsWorld* physicsWorld)
{
	StudentBoy* pSprite = new StudentBoy();

	if (pSprite->initWithFile("student-boy.png"))
	{
		pSprite->autorelease();
		pSprite->initOptions(physicsWorld, "watermelon1.png", "watermelon2.png", "StudentBoy.json", "StudentBoy", 1);
		pSprite->musicload("argh.wav");
		return pSprite;
	}
	CC_SAFE_DELETE(pSprite);
	return NULL;
}
void StudentBoy::initOptions(PhysicsWorld* physicsWorld,
	const string &cut1, const string &cut2,
	const string &path_body, const string &bodyName,
	int pointsValue)
{
	ACutSprite::initOptions(physicsWorld, cut1, cut2, path_body, bodyName, pointsValue);
	this->getPhysicsBody()->setTag(z_Order_SpriteBomb);
	this->setLocalZOrder(z_Order_SpriteBomb);
}