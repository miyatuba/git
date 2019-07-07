#include "EnemyTest1.h"

EnemyTest1::EnemyTest1()
{
	this->x = 0;
	this->y = 0;

	RectCollision rect_collision((float)this->x,
		(float)(this->x + EnemyTest1::X_SIZE),
		(float)this->y,
		(float)(this->y - EnemyTest1::Y_SIZE)
	);

	this->stand_image_handle = LoadGraph(this->IMAGE_PATH.c_str());

	this->rect_collision = rect_collision;
}

int EnemyTest1::getImageHandle()
{
	return 1;
}