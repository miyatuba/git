#pragma once
#include "BaseEnemy.h"


class EnemyTest1: public BaseEnemy 
{
private:
	int stand_image_handle;
	std::string IMAGE_PATH = "./resource/image/enemy/test1.jpg";

	const static int X_SIZE = 64;
	const static int Y_SIZE = 64;

	void MoveLeft(int);

public:
	EnemyTest1();
	int getImageHandle();
	void AoutAction();
};