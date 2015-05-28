#include "StudentBoy.h"
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
		return pSprite;
	}
	CC_SAFE_DELETE(pSprite);
	return NULL;
}
