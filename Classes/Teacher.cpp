#include "Teacher.h"
#include "gameScene.h"
#include "zOrder.h"

Teacher::Teacher(void) {}

Teacher::~Teacher(void) {}

Teacher* Teacher::create(PhysicsWorld* physicsWorld)
{
	Teacher* pSprite = new Teacher();

	if (pSprite->initWithFile("teacher.png"))
	{
		pSprite->autorelease();
		pSprite->initOptions(physicsWorld, "watermelon1.png", "watermelon2.png", "Teacher.json", "Teacher", 1);
		pSprite->musicload("kya.wav");
		return pSprite;
	}
	CC_SAFE_DELETE(pSprite);
	return NULL;
}
void Teacher::initOptions(PhysicsWorld* physicsWorld,
	const string &cut1, const string &cut2,
	const string &path_body, const string &bodyName,
	int pointsValue)
{
	ACutSprite::initOptions(physicsWorld, cut1, cut2, path_body, bodyName, pointsValue);
	this->getPhysicsBody()->setTag(z_Order_SpriteBomb);
	this->setLocalZOrder(z_Order_SpriteBomb);
}