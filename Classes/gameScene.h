#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class ACutSprite;

class gameLayer : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    CREATE_FUNC(gameLayer);

    void onEnter() override;
	void	cleanSprite();
	void	modifScore(int ScoreModifier);
	void	add_child(Node* node);
	void	loseLife(int lose);
	virtual void	update(float dt);
    bool onContactBegin(PhysicsContact& contact);
	void	throwItem();
	void	throwWave();
	ACutSprite	*getRandomItem();
	void nodeUnderTouch(cocos2d::Touch *touch);
    bool onTouchBegan(Touch *touch, Event *event);
    void onTouchMoved(Touch *touch, Event *event);

private:
    int		_sliceTag;
	Point	_sprite_size;
	Scene	*_scene;
	int		_score;
	int		_life;
	float	_ticClock;
	float	_ticTimeLimit;
	int		_waveSize;
private:
    cocos2d::PhysicsWorld *sceneWorld;

    void SetPhysicsWorld( cocos2d::PhysicsWorld *world ) { sceneWorld = world; };
};

#endif // __GAME_SCENE_H__
