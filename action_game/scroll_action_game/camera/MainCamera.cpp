#include "MainCamera.h"

//上下と左右それぞれの中心座標から、Heroが移動する際に計算しスクロール距離を求める。
//描画するものに、描画する際にその座標にスクロール距離を渡して補正を掛けて、カメラスクロールしているように見せる
//座標は上下の中心とHeroの座標、左右の中心とHeroの座標、また画面補正を掛ける時に、外側の移動できるかどうかも判断する

MainCamera::MainCamera()
{

}

MainCamera::MainCamera(int initial_position_x, int initial_position_y)
{
	this->initial_left_position_x = initial_position_x;
	this->initial_top_position_y = initial_position_y;
	this->current_left_position_x = initial_position_x;
	this->current_top_position_y = initial_position_y;
}


void MainCamera::moveLeftX(int x)
{
	this->current_left_position_x -= x;
}
void MainCamera::moveRightX(int x)
{
	this->current_left_position_x += x;
}
void MainCamera::moveUpY(int y)
{
	this->current_top_position_y += y;
}
void MainCamera::moveDownY(int y)
{
	this->current_top_position_y -= y;
}

int MainCamera::MovingDistanceX()
{
	return this->current_left_position_x;
}

int MainCamera::MovingDistanceY()
{
	return this->current_top_position_y;
}

void MainCamera::TrackingByTargetPosition(int x, int y)
{
	if (! this->shouldRevision()) return;

	int center_position_x = this->getCenterPositionX();
	int difference_distance_x = x - center_position_x;
	this->current_left_position_x += difference_distance_x;

	int center_position_y = this->getCenterPositionY();
	int difference_distance_y = -y - center_position_y;
	this->current_top_position_y += difference_distance_y;
}

//private
int MainCamera::getCenterPositionX()
{
	return this->current_left_position_x + (MainCamera::WIDTH / 2);
}

//private
int MainCamera::getCenterPositionY()
{
	return this->current_top_position_y + (MainCamera::HEIGHT / 2);
}


void MainCamera::OnShouldRevision()
{
	this->should_revision = true;
}

void MainCamera::OffShouldRevision()
{
	this->should_revision = false;
}

bool MainCamera::shouldRevision()
{
	return this->should_revision;
}

RectCollision MainCamera::createRectCollision()
{
	RectCollision rect_collision(
		this->current_left_position_x,
		this->current_left_position_x + MainCamera::WIDTH,
		this->current_top_position_y,
		this->current_top_position_y - MainCamera::HEIGHT
		);

	return rect_collision;
}