#include "gameScene.h"
#include "MyBodyParser.h"
#include "Watermelon.h"
#include "BookItem.h"
#include "Bag.h"
#include "Candy.h"
#include "Cat.h"
#include "Gummy.h"
#include "Pen.h"
#include "Potatoes.h"
#include "StudentBoy.h"
#include "StudentGirl.h"
#include "Teacher.h"
#include "zOrder.h"
#include <sstream>
#include "SimpleAudioEngine.h"
USING_NS_CC;

#define MOTION_STREAK_TAG 4242


int __SpriteFall = 1;

Scene* gameLayer::createScene()
{
    auto scene = Scene::createWithPhysics();
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Point(0, -250));
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
	_score = 100;
	_life = 5;
	_ticClock = 0;
	_ticTimeLimit = 4;
	_waveSize = 3+rand()%5;

	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	audio->preloadBackgroundMusic("macicbg.wav");

	// set the background music and continuously play it.
	audio->playBackgroundMusic("macicbg.wav", true);
	audio->setBackgroundMusicVolume(0.3);
	m_iCount = 0;
	MotionStreak::create(0.5f, 1, 10, Color3B(255,255,0), "Line.png");
	auto bg = Sprite::create("bg.png");
	bg->setAnchorPoint(Point(1, 1));
	bg->setPosition(Point(1280, 720));
	addChild(bg);

	_scoreLabel = Label::createWithSystemFont("Score : 0", "Arial", 76);
	_scoreLabel->enableShadow();
	_scoreLabel->setAnchorPoint(Point(1, 1));
	_scoreLabel->setPosition(Point(1260, 720));
	addChild(_scoreLabel, z_Order_UI);

	_lifeLabel = Label::createWithSystemFont("Life : 5", "Arial", 76);
	_lifeLabel->enableShadow();
	_lifeLabel->setAnchorPoint(Point(0, 1));
	_lifeLabel->setPosition(Point(0, 720));
	addChild(_lifeLabel, z_Order_UI);

    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(gameLayer::onContactBegin, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(gameLayer::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(gameLayer::onTouchMoved, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
	scheduleUpdate();
}


void gameLayer::resetMotionStreak() {
    this->removeChildByTag(MOTION_STREAK_TAG, true);
    MotionStreak* streak = MotionStreak::create(0.5f, 1, 10, Color3B(255, 255, 0), "line.png");
    this->addChild(streak, 5, MOTION_STREAK_TAG);
}

void gameLayer::addMotionStreakPoint(cocos2d::Point point) {
    MotionStreak* streak = (MotionStreak*)this->getChildByTag(MOTION_STREAK_TAG);
    streak->setPosition(point);
    
    if (++m_iCount>100) {
        int r = rand()%256;
        int b = rand()%265;
        int g = rand()%256;
        streak->setColor(Color3B(r, b, g));
        m_iCount = 0;
    }
}

bool gameLayer::onContactBegin(PhysicsContact& contact)
{
	return true;
}

void gameLayer::nodeUnderTouch(cocos2d::Touch *touch)
{
    Node* node = nullptr;
    auto scene = Director::getInstance()->getRunningScene();
    auto arr = scene->getPhysicsWorld()->getShapes(touch->getLocation());
	ACutSprite *sprite;
    for (auto& obj : arr)
    {
		sprite = dynamic_cast<ACutSprite*>(obj->getBody()->getNode());
		if ( sprite != nullptr)
        {
			sprite->clip();
			break;
        }
    }
}

bool gameLayer::onTouchBegan(Touch* touch, Event* event)
{
    nodeUnderTouch(touch);
    this->resetMotionStreak();
    Point point = this->convertTouchToNodeSpace(touch);
    this->addMotionStreakPoint(point);
    return true;
}

void gameLayer::onTouchMoved(Touch *touch, Event *event)
{
    nodeUnderTouch(touch);
    Point point = this->convertTouchToNodeSpace(touch);
    this->addMotionStreakPoint(point);
}

void gameLayer::update(float dt)
{
	cleanSprite();
	_ticClock += dt;
	if (_ticClock >= _ticTimeLimit) {
		_ticClock = 0;
		throwWave();
	}

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
					modifScore(-__SpriteFall);
				_scene->getPhysicsWorld()->removeBody(sprite->getPhysicsBody());
				sprite->removeFromParentAndCleanup(true);
				return;
            }
        }
    }
}

void	gameLayer::add_child(Node* node)
{
	addChild(node);
}

void	gameLayer::modifScore(int ScoreModifier)
{
	_score += ScoreModifier;
	std::stringstream  label;
	label << "Score : " << _score;
	_scoreLabel->setString(label.str());
	if (_score <= 0)
	{
		CCLOG("%s", "END GAME BY SCORE");
		//Trigger END GAME
	}
}

void	gameLayer::loseLife(int lose)
{
	if (lose == 0)
		return;
	this->_life -= lose;
	std::stringstream  label;
	label << "Life : " << _life;
	_lifeLabel->setString(label.str());

	CCLOG("Life : %i, lost : %i", _life, lose);
	if (_life <= 0)
	{
		CCLOG("%s", "END GAME BY LIFE");
		//Trigger END GAME
	}
}

void	gameLayer::throwWave()
{
	int i = 1;
	while (i <= _waveSize) {
		ACutSprite *sprite = getRandomItem();
		if (sprite != NULL) {
			//sprite->setPosition(Point(0.0 + (100 * i),100.0));
			addChild(sprite);
		}
		i++;
	}
}

ACutSprite* gameLayer::getRandomItem() {
	ACutSprite *sprite = NULL;
	switch (rand() % 10 + 1) {
		case 1: sprite = BookItem::create(_scene->getPhysicsWorld()); break;
		case 2: sprite = Bag::create(_scene->getPhysicsWorld()); break;
		case 3: sprite = Candy::create(_scene->getPhysicsWorld()); break;
		case 4: sprite = Cat::create(_scene->getPhysicsWorld()); break;
		case 5: sprite = Gummy::create(_scene->getPhysicsWorld()); break;
		case 6: sprite = Pen::create(_scene->getPhysicsWorld()); break;
		case 7: sprite = Potatoes::create(_scene->getPhysicsWorld()); break;
		case 8: sprite = StudentBoy::create(_scene->getPhysicsWorld()); break;
		case 9: sprite = StudentGirl::create(_scene->getPhysicsWorld()); break;
		case 10: sprite = Teacher::create(_scene->getPhysicsWorld()); break;
		default: sprite = Watermelon::create(_scene->getPhysicsWorld()); break;
	}
	return sprite;
}