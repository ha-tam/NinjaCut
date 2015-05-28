
#ifndef __BOOKITEM_H__
#define __BOOKITEM_H__
#include "cocos2d.h"
#include "ACutSprite.h"
USING_NS_CC;

class BookItem : public ACutSprite
{
public:
	BookItem(void);
	virtual ~BookItem(void);
	static BookItem* create(PhysicsWorld* physicsWorld);
};

#endif