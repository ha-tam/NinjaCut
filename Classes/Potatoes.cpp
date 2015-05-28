#include "Potatoes.h"
#include "gameScene.h"

Potatoes::Potatoes(void) {}

Potatoes::~Potatoes(void) {}

Potatoes* Potatoes::create(PhysicsWorld* physicsWorld)
{
	Potatoes* pSprite = new Potatoes();

	if (pSprite->initWithFile("potatoes.png"))
	{
		pSprite->autorelease();
		pSprite->initOptions(physicsWorld, "potatoes1.png", "potatoes2.png", "Potatoes.json", "Potatoes", 1);
		pSprite->addEvents();
		return pSprite;
	}
	CC_SAFE_DELETE(pSprite);
	return NULL;
}
