#include "StudentGirl.h"
#include "gameScene.h"
#include "zOrder.h"

StudentGirl::StudentGirl(void) {}

StudentGirl::~StudentGirl(void) {}

StudentGirl* StudentGirl::create(PhysicsWorld* physicsWorld)
{
	StudentGirl* pSprite = new StudentGirl();

	if (pSprite->initWithFile("student-girl.png"))
	{
		pSprite->autorelease();
		pSprite->initOptions(physicsWorld, "watermelon1.png", "watermelon2.png", "StudentGirl.json", "StudentGirl", 1);
		return pSprite;
	}
	CC_SAFE_DELETE(pSprite);
	return NULL;
}
void StudentGirl::initOptions(PhysicsWorld* physicsWorld,
	const string &cut1, const string &cut2,
	const string &path_body, const string &bodyName,
	int pointsValue)
{
	ACutSprite::initOptions(physicsWorld, cut1, cut2, path_body, bodyName, pointsValue);
	this->getPhysicsBody()->setTag(z_Order_SpriteBomb);
	this->setLocalZOrder(z_Order_SpriteBomb);
}