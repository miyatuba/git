#include "CollisionService.h"

//後で、この辺はベクトルを使った判定に変えたい。

bool CollisionService::checkCollisionByRectAndRect(RectCollision basis_rect_collision, RectCollision target_rect_collision)
{
	if ((basis_rect_collision.getCurrentXLeft() < target_rect_collision.getCurrentXRight()) &&
		(basis_rect_collision.getCurrentXRight() > target_rect_collision.getCurrentXLeft()) &&
		(basis_rect_collision.getCurrentYTop() > target_rect_collision.getCurrentYBottom()) &&
		(basis_rect_collision.getCurrentYBottom() < target_rect_collision.getCurrentYTop())
		) return true;

	return false;
}

//マイナスを考えるとわけわからんので絶対値で出す。
float CollisionService::differenceXLeftByRectandRect(RectCollision basis_rect_collision, RectCollision target_rect_collision)
{
	float difference = basis_rect_collision.getCurrentXLeft() - target_rect_collision.getCurrentXRight();
	return fabsf(difference);
}

float CollisionService::differenceXRightByRectandRect(RectCollision basis_rect_collision, RectCollision target_rect_collision)
{
	float difference = basis_rect_collision.getCurrentXRight() - target_rect_collision.getCurrentXLeft();
	return fabsf(difference);
}

float CollisionService::differenceYTopByRectandRect(RectCollision basis_rect_collision, RectCollision target_rect_collision)
{
	float difference = basis_rect_collision.getCurrentYTop() - target_rect_collision.getCurrentYBottom();
	return fabsf(difference);
}

float CollisionService::differenceYBottomByRectandRect(RectCollision basis_rect_collision, RectCollision target_rect_collision)
{
	float difference = basis_rect_collision.getCurrentYBottom() - target_rect_collision.getCurrentYTop();
	return fabsf(difference);
}


//debug用
void CollisionService::drawCollisionByRect(RectCollision rect_collision, int r, int g, int b, MainCamera main_camera)
{
	DrawBox(
		(int) rect_collision.getCurrentXLeft() - main_camera.MovingDistanceX(),
		-(int) (rect_collision.getCurrentYTop() - main_camera.MovingDistanceY()),
		(int) rect_collision.getCurrentXRight() - main_camera.MovingDistanceX(),
		-(int) (rect_collision.getCurrentYBottom() - main_camera.MovingDistanceY()),
		GetColor(r, g, b),
		false
	);

}