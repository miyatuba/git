#pragma once
#include "RectCollision.h"
#include "DxLib.h"
#include "math.h"

class CollisionService 
{
private:

public:
	static bool checkCollisionByRectandRect(RectCollision, RectCollision);
	static bool checkCollisionFromRightByRectandRect(RectCollision, RectCollision);
	static bool checkCollisionFromLeftByRectandRect(RectCollision, RectCollision);
	static bool checkCollisionFromUpByRectandRect(RectCollision, RectCollision);
	static bool checkCollisionFromDownByRectandRect(RectCollision, RectCollision);

	static float differenceXLeftByRectandRect(RectCollision, RectCollision);
	static float differenceXRightByRectandRect(RectCollision, RectCollision);
	static float differenceYTopByRectandRect(RectCollision, RectCollision);
	static float differenceYBottomByRectandRect(RectCollision, RectCollision);
	static void drawCollisionByRect(RectCollision, int, int, int);
};
