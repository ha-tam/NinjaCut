#include "ACutSprite.h"
#include "gameScene.h"

ACutSprite::ACutSprite(void){	auto test = CC_CALLBACK_0(ACutSprite::test, this);
	test();}

ACutSprite::~ACutSprite(void){}

ACutSprite* ACutSprite::create(const string &path_name)
{
	ACutSprite* pSprite = new ACutSprite();

	if (pSprite->initWithSpriteFrameName(path_name))
	{
		pSprite->autorelease();
		pSprite->initOptions();
		pSprite->addEvents();
		return pSprite;
	}
	CC_SAFE_DELETE(pSprite);
	return NULL;
}

void ACutSprite::initOptions(PhysicsWorld* physicsWorld,
	const string &cut1, const string &cut2,
	const string &path_body, int pointsValue)
{
	_PhysicsWorld = physicsWorld;

}
void ACutSprite::initPos(e_SpritePath)
{
}

void ACutSprite::addEvents()
{
	auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [](Touch* touch, Event* event)->bool{ return true; };
    touchListener->onTouchEnded = CC_CALLBACK_2(ACutSprite::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void ACutSprite::onTouchEnded(Touch *touch, Event *event)
{
	auto func = CC_CALLBACK_3(ACutSprite::slice, this);
    _PhysicsWorld->rayCast(func, touch->getStartLocation(), touch->getLocation(), nullptr);

}
bool ACutSprite::slice(PhysicsWorld& world, const PhysicsRayCastInfo& info, void* data)
{
	if (info.shape->getBody()->getTag() != _sliceTag)
    {
        return true;
    }

    if (!info.shape->containsPoint(info.start) && !info.shape->containsPoint(info.end))
    {
		CCLOG("%s","Slice Obj Detected !");
		//CREATE NEW SPRITES HERE
        info.shape->getBody()->removeFromWorld();
		info.shape->getBody()->getNode()->removeFromParentAndCleanup(true);
	}
    
    return true;}