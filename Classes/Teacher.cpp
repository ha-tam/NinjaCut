#include "Teacher.h"
#include "gameScene.h"

Teacher::Teacher(void) {}

Teacher::~Teacher(void) {}

Teacher* Teacher::create(PhysicsWorld* physicsWorld)
{
	Teacher* pSprite = new Teacher();

	if (pSprite->initWithFile("teacher.png"))
	{
		pSprite->autorelease();
		pSprite->initOptions(physicsWorld, "watermelon1.png", "watermelon2.png", "Teacher.json", "Teacher", 1);
		return pSprite;
	}
	CC_SAFE_DELETE(pSprite);
	return NULL;
}
