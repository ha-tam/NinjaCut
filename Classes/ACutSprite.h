
#ifndef ACUTSPRITE_H
#define ACUTSPRITE_H
#include "cocos2d.h"

USING_NS_CC;
using namespace std;
class gameScene;

typedef std::function<void(int)>	addScore_callBack;
typedef std::function<void(int)>		loseLife_callBack;
typedef std::function<void(Node*)>	addChild_callBack;
extern addScore_callBack Addpoints;
extern addScore_callBack LoseLife;
extern addChild_callBack AddChildToScene;
class ACutSprite : public Sprite
{
public:
	enum e_SpritePath : int {
		PATH0 = 0,
		PATH1,
		PATH2,
		PATH3,
		PATH4,
		PATH5
	};

public:

	ACutSprite(void);
	virtual ~ACutSprite(void);

	static ACutSprite* create(const string &path_name, PhysicsWorld* physicsWorld,
		const string &cut1, const string &cut2,
		const string &path_body, const string &bodyName,
		int pointsValue);

    void initOptions(PhysicsWorld* physicsWorld,
	const string &cut1, const string &cut2,
	const string &path_body, const string &bodyName,
	int pointsValue);
	void initPos(e_SpritePath);
	void clip();

private:
	PhysicsWorld	*_PhysicsWorld;
	string			_cut1;
	string			_cut2;
	int				_pointValue;
	bool			_deleted;
};

#endif