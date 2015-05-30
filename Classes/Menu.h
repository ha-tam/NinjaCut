#ifndef __MENU_H__
#define __MENU_H__

#include "cocos2d.h"

USING_NS_CC;
#define __STR_HIGHSCORE "nomoreScore"

class ACutSprite;

class gameMenu : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene(int score);
    CREATE_FUNC(gameMenu);
	void lunchGame(Ref* _ref);
    void onEnter() override;
	void score(int score);
};
extern int _scoreHigh;
#endif // __MENU_H__
