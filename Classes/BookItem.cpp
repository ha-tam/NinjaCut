#include "BookItem.h"
#include "gameScene.h"

BookItem::BookItem(void) {}

BookItem::~BookItem(void) {}

BookItem* BookItem::create(PhysicsWorld* physicsWorld)
{
	BookItem* pSprite = new BookItem();

	if (pSprite->initWithFile("book.png"))
	{
		pSprite->autorelease();
		pSprite->initOptions(physicsWorld, "exam-sheet.png", "exam-sheet.png", "BookItem.json", "BookItem", 1);
		return pSprite;
	}
	CC_SAFE_DELETE(pSprite);
	return NULL;
}
