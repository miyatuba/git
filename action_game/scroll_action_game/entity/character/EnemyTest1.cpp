#include "EnemyTest1.h"

EnemyTest1::EnemyTest1()
{
	this->x = 270;
	this->y = -250;

	RectCollision rect_collision(
		(float)this->x,
		(float)(this->x + EnemyTest1::X_SIZE),
		(float)this->y,
		(float)(this->y - EnemyTest1::Y_SIZE)
	);
	this->rect_collision = rect_collision;

	this->stand_image_handle = LoadGraph(this->IMAGE_PATH.c_str());
}

int EnemyTest1::getImageHandle()
{
	return this->stand_image_handle;
}

void EnemyTest1::AoutAction()
{
	//状態に応じて変更することになるが、まずは左に移動するだけのAI
	this->MoveLeft(1);

}

void EnemyTest1::MoveLeft(int x)
{
	this->x -= x;
	this->rect_collision.moveCollisionX(-x);
}