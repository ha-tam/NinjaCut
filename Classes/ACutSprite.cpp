#include "ACutSprite.h"
#include "gameScene.h"
#include "MyBodyParser.h"
#include "zOrder.h"
#include <iostream>

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

		auto rd = rand()%6;
		initPos(e_SpritePath(rd));
    }
}

void ACutSprite::initPos(e_SpritePath path)
{
	switch (path)
	{
	  case 0:
		this->setPosition(200, 0); // X, Y
		this->getPhysicsBody()->setVelocity(Vect(100,500)); //longueur, hauteur max
		this->getPhysicsBody()->setAngularVelocity(1.1f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 5.0f))); //Rotate speed
		break;
	  case 1: // higher, right to left
		this->setPosition(1200, 50);
		this->getPhysicsBody()->setVelocity(Vect(-200, 450));
		this->getPhysicsBody()->setAngularVelocity(1.1f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 5.0f)));
		break;
	  case 2: // candle
		  this->setPosition(550, 0);
		  this->getPhysicsBody()->setVelocity(Vect(50, 500));
		  this->getPhysicsBody()->setAngularVelocity(1.1f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 5.0f)));
		  break;
	  case 3: //random high
		  this->setPosition(100 + rand() % 500 , rand() % 30);
		  this->getPhysicsBody()->setVelocity(Vect(50 + rand() % 300, 300 + rand() % 300));
		  this->getPhysicsBody()->setAngularVelocity(1.1f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 5.0f)));
		  break;
	  case 4: // left, middle high, random
		  this->setPosition(700, 50);
		  this->getPhysicsBody()->setVelocity(Vect(-300 + rand() % 200, 200 + rand() % 300));
		  this->getPhysicsBody()->setAngularVelocity(1.1f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 5.0f)));
		  break;
	  case 5:
		  this->setPosition(0, 300);
		  this->getPhysicsBody()->setVelocity(Vect(500, 200));
		  this->getPhysicsBody()->setAngularVelocity(1.1f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 5.0f)));
		  break;
		 //...
	  default:
	  	this->setPosition(0, 0);
		this->getPhysicsBody()->setVelocity(Vect(0, 0));
	}
}

void ACutSprite::clip()
{
	if (_deleted == true)
		return;
	CCLOG("%s - %i","Slice Obj Detected !  - ", this);
	_deleted = true;
	if (this->getLocalZOrder() == z_Order_SpriteBomb)
	{
			CCLOG("%s - %i","BOMB CUT  - ", this);
		LoseLife(1);
	}
	else
		Addpoints(this->_pointValue);
	this->setOpacity(0);
	this->setLocalZOrder(z_Order_SpriteCut);
	auto body = this->getPhysicsBody();
	{
		auto sprite = Sprite::create(_cut1);
		sprite->setPosition(this->getPosition());
		auto spriteBody = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0, 1, 0));
		spriteBody->setVelocity(body->getVelocity() * 0.9);
		spriteBody->setAngularVelocity(body->getAngularVelocity() * 0.9);
		sprite->setPhysicsBody(spriteBody);
		sprite->setOpacity(90);
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
		sprite->setOpacity(90);
		sprite->getPhysicsBody()->setTag(z_Order_SpriteCut);
		sprite->getPhysicsBody()->setCategoryBitmask(0x02);    // 0010
		sprite->getPhysicsBody()->setContactTestBitmask(0x08); // 1000
		sprite->getPhysicsBody()->setCollisionBitmask(0x01);   // 0001
		sprite->setLocalZOrder(z_Order_SpriteCut);
		AddChildToScene(sprite);
	}
}