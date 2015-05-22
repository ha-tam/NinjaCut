#ifndef __ZORDER_H__
#define __ZORDER_H__

#include "cocos2d.h"


enum e_zOrder : int {
	z_Order_Background = 0,
	z_Order_SpriteCut,
	z_Order_Sprite,
	z_Order_SpriteBomb,
	z_Order_UI
};

#endif // __ZORDER_H__
