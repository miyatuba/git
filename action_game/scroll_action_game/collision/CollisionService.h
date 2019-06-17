#pragma once
#include "RectCollision.h"
#include "DxLib.h"
#include "math.h"
#include "../camera/mainCamera.h"

class CollisionService 
{
private:

public:
	static bool checkCollisionByRectandRect(RectCollision, RectCollision);
	static bool checkCollisionLeftAndRightByRectandRect(RectCollision, RectCollision);
	static bool checkCollisionUpAndDownByRectandRect(RectCollision, RectCollision);
	static bool checkShiftedToLeftByRectandRect(RectCollision, RectCollision);
	static bool checkShiftedToRightByRectandRect(RectCollision, RectCollision);
	static bool checkShiftedToBottomByRectandRect(RectCollision, RectCollision);
	static bool checkShiftedToTopByRectandRect(RectCollision, RectCollision);

	static float differenceXLeftByRectandRect(RectCollision, RectCollision);
	static float differenceXRightByRectandRect(RectCollision, RectCollision);
	static float differenceYTopByRectandRect(RectCollision, RectCollision);
	static float differenceYBottomByRectandRect(RectCollision, RectCollision);
	static void drawCollisionByRect(RectCollision, int, int, int, MainCamera);
};
