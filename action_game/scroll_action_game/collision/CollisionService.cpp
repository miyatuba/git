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


bool CollisionService::checkCollisionLeftAndRightByRectandRect(RectCollision basis_rect_collision, RectCollision target_rect_collision)
{
	if ((basis_rect_collision.getCurrentXLeft() < target_rect_collision.getCurrentXRight()) &&
		(basis_rect_collision.getCurrentXRight() > target_rect_collision.getCurrentXLeft())
		) return true;

	return false;
}


bool CollisionService::checkCollisionUpAndDownByRectandRect(RectCollision basis_rect_collision, RectCollision target_rect_collision)
{
	if ((basis_rect_collision.getCurrentYTop() > target_rect_collision.getCurrentYBottom()) &&
		(basis_rect_collision.getCurrentYBottom() < target_rect_collision.getCurrentYTop())
		) {
		return true;
	}
	return false;
}

// パターン分関数が増えることになるのは如何なものか・・とは言え、値を投げるとオブジェクト指向ではないし。
bool CollisionService::checkShiftedToLeftByRectandRect(RectCollision basis_rect_collision, RectCollision target_rect_collision)
{
	//Aの右とBの左の差分とAの左とBの右の差分を比較し前者が大きければ、左にズレてる
	if ((basis_rect_collision.getCurrentXRight() - target_rect_collision.getCurrentXLeft()) > 
		(target_rect_collision.getCurrentXRight() - basis_rect_collision.getCurrentXLeft())
	   ) return true;

	//Aの右とBの左の差分とAの左のBの右の差分を比較し同値であれば、
	//Aの右とBの右、もしくはAの左のBの左を比べて前者が大きければ、
	//左にずれている
	if ((basis_rect_collision.getCurrentXRight() - target_rect_collision.getCurrentXLeft()) ==
		(target_rect_collision.getCurrentXRight() - basis_rect_collision.getCurrentXLeft())
		) {
		if (basis_rect_collision.getCurrentXRight() >= target_rect_collision.getCurrentXRight()) return true;
	}

	return false;
}
bool CollisionService::checkShiftedToRightByRectandRect(RectCollision basis_rect_collision, RectCollision target_rect_collision)
{
	//Aの右とBの左の差分とAの左とBの右の差分を比較し後者が大きければ、右にズレてる
	if ((basis_rect_collision.getCurrentXRight() - target_rect_collision.getCurrentXLeft()) < 
		(target_rect_collision.getCurrentXRight() - basis_rect_collision.getCurrentXLeft())
		) return true;
	return false;

	//Aの右とBの左の差分とAの左のBの右の差分を比較し同値であれば、
	//Aの右とBの右、もしくはAの左のBの左を比べて後者が大きければ、
	//右にずれている
	if ((basis_rect_collision.getCurrentXRight() - target_rect_collision.getCurrentXLeft()) ==
		(target_rect_collision.getCurrentXRight() - basis_rect_collision.getCurrentXLeft())
		) {
		if (basis_rect_collision.getCurrentXLeft() < target_rect_collision.getCurrentXLeft()) return true;
	}
	
	return false;
}
bool CollisionService::checkShiftedToBottomByRectandRect(RectCollision basis_rect_collision, RectCollision target_rect_collision)
{
	//Aの上とBの下の差分とAの下とBの上の差分を比較し前者が大きければ、下にずれてる
	if ((basis_rect_collision.getCurrentYTop() - target_rect_collision.getCurrentYBottom()) >
		(target_rect_collision.getCurrentYTop() - basis_rect_collision.getCurrentYBottom())
		) return true;

	//Aの上とBの下の差分とAの下のBの上の差分を比較し同値であれば、
	//Aの上とBの上、もしくはAの下のBの下を比べて前者が大きければ、
	//下にずれている
	if ((basis_rect_collision.getCurrentYTop() - target_rect_collision.getCurrentYBottom()) ==
		(target_rect_collision.getCurrentYTop() - basis_rect_collision.getCurrentYBottom())
		) {
		if (basis_rect_collision.getCurrentYTop() >= target_rect_collision.getCurrentYTop()) return true;
		
	}

	return false;
}

bool CollisionService::checkShiftedToTopByRectandRect(RectCollision basis_rect_collision, RectCollision target_rect_collision)
{
	//Aの上とBの下の差分とAの下とBの上の差分を比較し後者が大きければ、上にずれている
	if ((basis_rect_collision.getCurrentYTop() - target_rect_collision.getCurrentYBottom()) <
		(target_rect_collision.getCurrentYTop() - basis_rect_collision.getCurrentYBottom())
		) return true;

	//Aの上とBの下の差分とAの下のBの上の差分を比較し同値であれば、
	//Aの上とBの上、もしくはAの下のBの下を比べて後者が大きければ、
	//上にずれている
	if ((basis_rect_collision.getCurrentYTop() - target_rect_collision.getCurrentYBottom()) ==
		(target_rect_collision.getCurrentYTop() - basis_rect_collision.getCurrentYBottom())
		) {
		if (basis_rect_collision.getCurrentYBottom() < target_rect_collision.getCurrentYBottom()) return true;
	}

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