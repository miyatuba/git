#include "CollisionService.h"

//後で、この辺はベクトルを使った判定に変えたい。

//↓結局どの部分がどれだけめり込んでるのか出さないといけないから、各条件に分離
bool CollisionService::checkCollisionByRectandRect(RectCollision rectCollision1, RectCollision rectCollision2)//このメソッドはいらなくなりそう、そもそも間違えてる
{
	/*	if ((rectCollision1.getCurrentXLeft() < rectCollision2.getCurrentXRight()) &&
			(rectCollision1.getCurrentYTop() < rectCollision2.getCurrentYBottom()) &&
			(rectCollision1.getCurrentXRight() > rectCollision2.getCurrentXLeft()) &&
			(rectCollision1.getCurrentYBottom() > rectCollision2.getCurrentYTop())
			) return true;*/

			//	return false;

	if (!(rectCollision1.getCurrentXLeft() < rectCollision2.getCurrentXRight())) {
		return false;
	}

	if (!(rectCollision1.getCurrentYBottom() > rectCollision2.getCurrentYTop())) {
		return false;
	}

	if (!(rectCollision1.getCurrentYTop() < rectCollision2.getCurrentYBottom())) {
		return false;
	}

	if (!(rectCollision1.getCurrentXRight() > rectCollision2.getCurrentXLeft())) {
		return false;
	}

	return true;
}


//矩形の場合、右から、左から、上から、下からの判定を分ける必要があることに気づいた
//右の判定をし、上もしくは下がめり込んでいれば当たっている
bool CollisionService::checkCollisionFromRightByRectandRect(RectCollision rectCollision1, RectCollision rectCollision2)
{
	if (! (rectCollision1.getCurrentXRight() > rectCollision2.getCurrentXLeft()) ) {
		return false;
	}

	if ((rectCollision1.getCurrentYTop() > rectCollision2.getCurrentYBottom()) && (rectCollision1.getCurrentYBottom() < rectCollision2.getCurrentYTop())) {
		return true;
	}

	return false;
}

bool CollisionService::checkCollisionFromLeftByRectandRect(RectCollision rectCollision1, RectCollision rectCollision2)
{
	if (! (rectCollision1.getCurrentXLeft() < rectCollision2.getCurrentXRight()) ) {
		return false;
	}

	if ((rectCollision1.getCurrentYTop() > rectCollision2.getCurrentYBottom()) || (rectCollision1.getCurrentYBottom() < rectCollision2.getCurrentYTop())) {
		return true;
	}
	return false;
}

bool CollisionService::checkCollisionFromUpByRectandRect(RectCollision rectCollision1, RectCollision rectCollision2)
{
	if (! (rectCollision1.getCurrentYTop() > rectCollision2.getCurrentYBottom()) ) {
		return false;
	}

	if ((rectCollision1.getCurrentXRight() > rectCollision2.getCurrentXLeft()) || (rectCollision1.getCurrentXLeft() < rectCollision2.getCurrentXRight())) {
		return true;
	}
	return false;
}

bool CollisionService::checkCollisionFromDownByRectandRect(RectCollision rectCollision1, RectCollision rectCollision2)
{
	if (! (rectCollision1.getCurrentYBottom() < rectCollision2.getCurrentYTop()) ) {
		return false;
	}

	if ((rectCollision1.getCurrentXRight() > rectCollision2.getCurrentXLeft()) || (rectCollision1.getCurrentXLeft() < rectCollision2.getCurrentXRight())) {
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
void CollisionService::drawCollisionByRect(RectCollision rectCollision, int r, int g, int b)
{
	DrawBox(
		(int) rectCollision.getCurrentXLeft(),
		-(int) rectCollision.getCurrentYTop(),
		(int) rectCollision.getCurrentXRight(),
		-(int) rectCollision.getCurrentYBottom(),
		GetColor(r, g, b),
		false
	);

}