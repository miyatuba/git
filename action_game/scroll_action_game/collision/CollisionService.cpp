#include "CollisionService.h"

//後で、この辺はベクトルを使った判定に変えたい。
bool CollisionService::checkCollisionByRectandRect(RectCollision rectCollision1, RectCollision rectCollision2)
{
	if ((rectCollision1.getCurrentXLeft() < rectCollision2.getCurrentXRight()) &&
		(rectCollision1.getCurrentYTop() < rectCollision2.getCurrentYBottom()) &&
		(rectCollision1.getCurrentXRight() > rectCollision2.getCurrentXLeft()) &&
		(rectCollision1.getCurrentYBottom() > rectCollision2.getCurrentYTop())
		) return true;

	return false;
}


void CollisionService::drawCollisionByRect(RectCollision rectCollision)
{
	DrawBox(
		(int) rectCollision.getCurrentXLeft(),
		(int) rectCollision.getCurrentYTop(),
		(int) rectCollision.getCurrentXRight(),
		(int) rectCollision.getCurrentYBottom(),
		GetColor(0, 255, 0),
		true
	);
		
	
}