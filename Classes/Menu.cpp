#include "gameScene.h"
#include "Menu.h"
#include "zOrder.h"
#include <sstream>
#include "SimpleAudioEngine.h"
USING_NS_CC;

int _scoreHigh;
Scene* gameMenu::createScene(int score)
{
    auto scene = Scene::create();
	auto layer = gameMenu::create();
    scene->addChild(layer);
	layer->score(score);
    return scene;
}

void gameMenu::onEnter()
{
    Layer::onEnter();
	int	w = 1280;
	int h = 720;
	auto bg = Sprite::create("bg.png");
	bg->setAnchorPoint(Point(0, 0));
	bg->setPosition(Point(0, 0));
	addChild(bg);

	UserDefault *def = UserDefault::getInstance();
    auto highScore = def->getIntegerForKey(__STR_HIGHSCORE, _scoreHigh);
	{
		auto TitleLabel = Label::createWithTTF(TTFConfig("Marker Felt.ttf",100), "NO MORE STUDIES !");
		TitleLabel->setColor(Color3B::BLACK);
		TitleLabel->setPosition(Point(w/2, h * 0.75));
		TitleLabel->setAnchorPoint(Point(0.5,0.5));
		TitleLabel->enableShadow();
		this->addChild(TitleLabel);
	}
	{
	    auto _menu = Menu::create();
        auto label = Label::createWithTTF(TTFConfig("Marker Felt.ttf",160), "Start !");
        auto menuItem = MenuItemLabel::create(label, CC_CALLBACK_1(gameMenu::lunchGame, this));

        _menu->addChild(menuItem);
        menuItem->setPosition(w * 0.5, h * 0.4);
		menuItem->setAnchorPoint(Point(0.5,0.5));
		menuItem->setColor(Color3B::BLACK);
		_menu->setAnchorPoint(Point(0,0));
		_menu->setPosition(Point(0, 0));
		addChild(_menu, 5);
    }
	{
		__String *tempHighScore = __String::createWithFormat( "High Score : %i.", highScore );
        auto highScoreLabel =Label::createWithTTF(TTFConfig("Marker Felt.ttf",76), tempHighScore->getCString());
		highScoreLabel->setColor(Color3B::BLUE);
		highScoreLabel->setPosition(Point(0, 0));
		highScoreLabel->setAnchorPoint(Point(0,0));
		highScoreLabel->enableShadow();
		this->addChild(highScoreLabel);
	}
}
void gameMenu::score(int score)
{
	if (score > _scoreHigh)
		_scoreHigh = score;
}
void gameMenu::lunchGame(Ref* ref)
{
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	auto scene = gameLayer::createScene();
	Director::getInstance()->replaceScene(TransitionMoveInL::create(1, scene));

}