#include "gameScene.h"
#include "MyBodyParser.h"
#include "PRKit/PRFilledPolygon.h"
#include "Watermelon.h"
#include "zOrder.h"

USING_NS_CC;

Scene* gameLayer::createScene()
{
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Point(0, -20));
    auto test = new ACutSprite();
    auto layer = gameLayer::create();
    layer->SetPhysicsWorld(scene->getPhysicsWorld());

    scene->addChild(layer);
	layer->_scene = scene;
	LoseLife = CC_CALLBACK_1(gameLayer::loseLife, layer);
	Addpoints = CC_CALLBACK_1(gameLayer::modifScore, layer);
	AddChildToScene = CC_CALLBACK_1(gameLayer::add_child, layer);
    return scene;
}

void gameLayer::onEnter()
{
    Layer::onEnter();
	_score = 0;
	_life = 3;

//TEST
	auto sprite = Watermelon::create(_scene->getPhysicsWorld());
	addChild(sprite);
	sprite = Watermelon::create(_scene->getPhysicsWorld());
	sprite->getPhysicsBody()->setVelocity(Vect(0.0,0.0));
	sprite->setPosition(Point(400.0,400.0));
	addChild(sprite);
//END TEST

    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(gameLayer::onContactBegin, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	scheduleUpdate();
}

bool gameLayer::onContactBegin(PhysicsContact& contact)
{
	return true;
}

void gameLayer::update(float dt)
{

	cleanSprite();
//	ADD GAME LOGIC HERE (PUSH SOME SPRITE)
}

void	gameLayer::cleanSprite()
{
	for (auto b = _scene->getPhysicsWorld()->getAllBodies().begin();
		b != _scene->getPhysicsWorld()->getAllBodies().end(); ++b)
    {
		Node *sprite = ((*b)->getNode());
        if (sprite != NULL) {
            auto *sprite = (*b)->getNode();
            Point position = (*b)->getPosition();
            if (position.y < -100.0f || position.x < -100.0f)
            {
                if (sprite->getLocalZOrder() == z_Order_Sprite)
                {
					loseLife(1);
                }
				_scene->getPhysicsWorld()->removeBody(sprite->getPhysicsBody());
				sprite->removeFromParentAndCleanup(true);
				return;
            }
        }
    }
}

void	gameLayer::modifScore(int ScoreModifier)
{
	_score += ScoreModifier;
}

void	gameLayer::add_child(Node* node)
{
	addChild(node);
}

void	gameLayer::loseLife(int lose)
{
	if (lose == 0)
		return;
	this->_life -= lose;
	CCLOG("Life : %i, lost : %i", _life, lose);
	if (_life == 0)
	{
		CCLOG("%s", "END GAME");
		//Trigger END GAME
	}
}