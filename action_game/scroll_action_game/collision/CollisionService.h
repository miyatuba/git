#pragma once
#include "RectCollision.h"
#include "DxLib.h"
#include "math.h"
#include "../camera/mainCamera.h"

class CollisionService 
{
private:

public:
	static bool checkCollisionByRectAndRect(RectCollision, RectCollision);

	static float differenceXLeftByRectAndRect(RectCollision, RectCollision);
	static float differenceXRightByRectAndRect(RectCollision, RectCollision);
	static float differenceYTopByRectAndRect(RectCollision, RectCollision);
	static float differenceYBottomByRectAndRect(RectCollision, RectCollision);
	static void drawCollisionByRect(RectCollision, int, int, int, MainCamera);
};
