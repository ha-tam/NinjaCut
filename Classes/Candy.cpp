#include "Candy.h"
#include "gameScene.h"

Candy::Candy(void) {}

Candy::~Candy(void) {}

Candy* Candy::create(PhysicsWorld* physicsWorld)
{
	Candy* pSprite = new Candy();

	if (pSprite->initWithFile("candy.png"))
	{
		pSprite->autorelease();
		pSprite->initOptions(physicsWorld, "candy1.png", "candy2.png", "Candy.json", "Candy", 1);
		pSprite->addEvents();
		return pSprite;
	}
	CC_SAFE_DELETE(pSprite);
	return NULL;
}
