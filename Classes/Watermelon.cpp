#include "Watermelon.h"
#include "gameScene.h"

Watermelon::Watermelon(void) {}

Watermelon::~Watermelon(void) {}

Watermelon* Watermelon::create(PhysicsWorld* physicsWorld)
{
	Watermelon* pSprite = new Watermelon();

	if (pSprite->initWithFile("watermelon.png"))
	{
		pSprite->autorelease();
		pSprite->initOptions(physicsWorld, "watermelon1.png", "watermelon2.png", "watermelon.json", "Watermelon", 1);
		pSprite->addEvents();
		return pSprite;
	}
	CC_SAFE_DELETE(pSprite);
	return NULL;
}
