#include "Gummy.h"
#include "gameScene.h"

Gummy::Gummy(void) {}

Gummy::~Gummy(void) {}

Gummy* Gummy::create(PhysicsWorld* physicsWorld)
{
	Gummy* pSprite = new Gummy();

	if (pSprite->initWithFile("gummy.png"))
	{
		pSprite->autorelease();
		pSprite->initOptions(physicsWorld, "gummy1.png", "gummy2.png", "Gummy.json", "Gummy", 1);
		return pSprite;
	}
	CC_SAFE_DELETE(pSprite);
	return NULL;
}
