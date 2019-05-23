#pragma once
#include "RectCollision.h"
#include "DxLib.h"

class CollisionService 
{
private:

public:
	static bool checkCollisionByRectandRect(RectCollision, RectCollision);
	static void drawCollisionByRect(RectCollision);
};
