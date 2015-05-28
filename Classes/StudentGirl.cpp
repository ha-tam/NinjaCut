#include "StudentGirl.h"
#include "gameScene.h"

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
