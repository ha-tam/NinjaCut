#include "ACutSprite.h"
#include "gameScene.h"
#include "MyBodyParser.h"
#include "zOrder.h"

addScore_callBack Addpoints;
addScore_callBack LoseLife;
addChild_callBack AddChildToScene;

ACutSprite::ACutSprite(void) {}

ACutSprite::~ACutSprite(void) {}

ACutSprite* ACutSprite::create(const string &path_name, PhysicsWorld* physicsWorld,
							   const string &cut1, const string &cut2, const string &path_body,
							   const string &bodyName, int pointsValue)
{
	ACutSprite* pSprite = new ACutSprite();
	if (pSprite->initWithSpriteFrameName(path_name))
	{
		pSprite->autorelease();
		pSprite->initOptions(physicsWorld, cut1, cut2, path_body, bodyName, pointsValue);
		pSprite->addEvents();
		return pSprite;
	}
	CC_SAFE_DELETE(pSprite);
	return NULL;
}

void ACutSprite::initOptions(PhysicsWorld* physicsWorld,
							 const string &cut1, const string &cut2, const string &path_body,
							 const string &bodyName, int pointsValue)
{
	_deleted = false;
	_PhysicsWorld = physicsWorld;
	_cut1 = cut1;
	_cut2 = cut2;
	_pointValue = pointsValue;
	this->setLocalZOrder(z_Order_Sprite);
	MyBodyParser::getInstance()->parseJsonFile(path_body);
    auto spriteBody = MyBodyParser::getInstance()->bodyFormJson(this, bodyName, PhysicsMaterial(1, 1, 0));
    if (spriteBody != nullptr)
    {
        spriteBody->setDynamic(true);
        this->setPhysicsBody(spriteBody);
		this->getPhysicsBody()->setTag(z_Order_Sprite);
		this->getPhysicsBody()->setCategoryBitmask(0x02);    // 0010
		this->getPhysicsBody()->setContactTestBitmask(0x08); // 1000
		this->getPhysicsBody()->setCollisionBitmask(0x01);   // 0001
		//MAKE RANDOM PATH HERE!
		initPos(PATH0);
    }
}

void ACutSprite::initPos(e_SpritePath path)
{
	//make the path !
	// look for setPosition and setVelocity
	switch (path)
	{
	  case PATH0:
		  //TEST CHANGE THE VALUE AFTER
		this->setPosition(200, 200);
		this->getPhysicsBody()->setVelocity(Vect(70,70));
		this->getPhysicsBody()->setAngularVelocity(7.0f);
		break;
	  //case PATH1:
		 //break;
		 //...
	  default:
	  	this->setPosition(0, 0);
		this->getPhysicsBody()->setVelocity(Vect(0, 0));
	}
}

void ACutSprite::addEvents()
{
	touchListener = EventListenerTouchOneByOne::create();
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
	if (_deleted == true)
		return true;
	if (info.shape->getBody()->getTag() == z_Order_SpriteBomb)
		LoseLife(1);
	if (info.shape->getBody()->getTag() != z_Order_Sprite)
		return true;
    if (!info.shape->containsPoint(info.start) && !info.shape->containsPoint(info.end))
    {
		CCLOG("%s - %i","Slice Obj Detected !  - ", this);
		Addpoints(this->_pointValue);
		_eventDispatcher->removeEventListener(touchListener);
		this->setOpacity(0);
		this->setLocalZOrder(z_Order_SpriteCut);
		_deleted = true;
		auto body = this->getPhysicsBody();
		{
			auto sprite = Sprite::create(_cut1);
			sprite->setPosition(this->getPosition());
			auto spriteBody = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0, 1, 0));
			spriteBody->setVelocity(body->getVelocity() * 0.9);
			spriteBody->setAngularVelocity(body->getAngularVelocity() * 0.9);
			sprite->setPhysicsBody(spriteBody);
			sprite->getPhysicsBody()->setTag(z_Order_SpriteCut);
			sprite->getPhysicsBody()->setCategoryBitmask(0x02);    // 0010
			sprite->getPhysicsBody()->setContactTestBitmask(0x08); // 1000
			sprite->getPhysicsBody()->setCollisionBitmask(0x01);   // 0001
			sprite->setLocalZOrder(z_Order_SpriteCut);
			AddChildToScene(sprite);
		}
		{
			auto sprite = Sprite::create(_cut2);
			sprite->setPosition(this->getPosition());
			auto spriteBody = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0, 1, 0));
			spriteBody->setVelocity(body->getVelocity() * 1.1);
			spriteBody->setAngularVelocity(body->getAngularVelocity() * 1.1);
			sprite->setPhysicsBody(spriteBody);
			sprite->getPhysicsBody()->setTag(z_Order_SpriteCut);
			sprite->getPhysicsBody()->setCategoryBitmask(0x02);    // 0010
			sprite->getPhysicsBody()->setContactTestBitmask(0x08); // 1000
			sprite->getPhysicsBody()->setCollisionBitmask(0x01);   // 0001
			sprite->setLocalZOrder(z_Order_SpriteCut);
			AddChildToScene(sprite);
		}
	}
    return true;
}