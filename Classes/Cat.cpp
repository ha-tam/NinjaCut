#include "Cat.h"
#include "gameScene.h"

Cat::Cat(void) {}

Cat::~Cat(void) {}

Cat* Cat::create(PhysicsWorld* physicsWorld)
{
	Cat* pSprite = new Cat();

	if (pSprite->initWithFile("cat.png"))
	{
		pSprite->autorelease();
		pSprite->initOptions(physicsWorld, "cat1.png", "cat2.png", "Cat.json", "Cat", 1);
		pSprite->addEvents();
		return pSprite;
	}
	CC_SAFE_DELETE(pSprite);
	return NULL;
}
