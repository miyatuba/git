#include "CollisionService.h"

//後で、この辺はベクトルを使った判定に変えたい。

bool CollisionService::checkCollisionByRectandRect(RectCollision rectCollision1, RectCollision rectCollision2)
{
	if ((rectCollision1.getCurrentXLeft() < rectCollision2.getCurrentXRight()) &&
		(rectCollision1.getCurrentXRight() > rectCollision2.getCurrentXLeft()) &&
		(rectCollision1.getCurrentYTop() > rectCollision2.getCurrentYBottom()) &&
		(rectCollision1.getCurrentYBottom() < rectCollision2.getCurrentYTop())
		) return true;

	return false;

}


bool CollisionService::checkCollisionLeftAndRightByRectandRect(RectCollision rectCollision1, RectCollision rectCollision2)
{
	if ((rectCollision1.getCurrentXLeft() < rectCollision2.getCurrentXRight()) &&
		(rectCollision1.getCurrentXRight() > rectCollision2.getCurrentXLeft())
		) return true;

	return false;
}


bool CollisionService::checkCollisionUpAndDownByRectandRect(RectCollision rectCollision1, RectCollision rectCollision2)
{
	if ((rectCollision1.getCurrentYTop() > rectCollision2.getCurrentYBottom()) &&
		(rectCollision1.getCurrentYBottom() < rectCollision2.getCurrentYTop())
		) {
		return true;
	}
	return false;
}



//マイナスを考えるとわけわからんので絶対値で出す。
float CollisionService::differenceXLeftByRectandRect(RectCollision rectCollision1, RectCollision rectCollision2)
{
	float difference = rectCollision1.getCurrentXLeft() - rectCollision2.getCurrentXRight();
	return fabsf(difference);
}

float CollisionService::differenceXRightByRectandRect(RectCollision rectCollision1, RectCollision rectCollision2)
{
	float difference = rectCollision1.getCurrentXRight() - rectCollision2.getCurrentXLeft();
	return fabsf(difference);
}

float CollisionService::differenceYTopByRectandRect(RectCollision rectCollision1, RectCollision rectCollision2)
{
	float difference = rectCollision1.getCurrentYTop() - rectCollision2.getCurrentYBottom();
	return fabsf(difference);
}

float CollisionService::differenceYBottomByRectandRect(RectCollision rectCollision1, RectCollision rectCollision2)
{
	float difference = rectCollision1.getCurrentYBottom() - rectCollision2.getCurrentYTop();
	return fabsf(difference);
}


//debug用
void CollisionService::drawCollisionByRect(RectCollision rectCollision, int r, int g, int b, MainCamera main_camera)
{
	DrawBox(
		(int) rectCollision.getCurrentXLeft() - main_camera.MovingDistanceX(),
		-(int) (rectCollision.getCurrentYTop() - main_camera.MovingDistanceY()),
		(int) rectCollision.getCurrentXRight() - main_camera.MovingDistanceX(),
		-(int) (rectCollision.getCurrentYBottom() - main_camera.MovingDistanceY()),
		GetColor(r, g, b),
		false
	);

}