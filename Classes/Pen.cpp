#include "Pen.h"
#include "gameScene.h"

Pen::Pen(void) {}

Pen::~Pen(void) {}

Pen* Pen::create(PhysicsWorld* physicsWorld)
{
	Pen* pSprite = new Pen();

	if (pSprite->initWithFile("pen.png"))
	{
		pSprite->autorelease();
		pSprite->initOptions(physicsWorld, "pen1.png", "pen2.png", "Pen.json", "Pen", 1);
		pSprite->addEvents();
		return pSprite;
	}
	CC_SAFE_DELETE(pSprite);
	return NULL;
}
