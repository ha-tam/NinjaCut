#include "Bag.h"
#include "gameScene.h"

Bag::Bag(void) {}

Bag::~Bag(void) {}

Bag* Bag::create(PhysicsWorld* physicsWorld)
{
	Bag* pSprite = new Bag();

	if (pSprite->initWithFile("bag.png"))
	{
		pSprite->autorelease();
		pSprite->initOptions(physicsWorld, "bag1.png", "bag2.png", "Bag.json", "Bag", 1);
		pSprite->addEvents();
		return pSprite;
	}
	CC_SAFE_DELETE(pSprite);
	return NULL;
}
