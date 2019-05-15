#pragma once
#include "DxLib.h"
#include <string>
#include "../../input/Input.h"

class Hero
{
private:
	int x = 0;
	int y = 0;
	std::string image_path = "../../resource/image/test_image.jpg";
public:
	Hero();
	void MovePositionByInput(Input);
	int getPositionX();
	int getPositionY();
	std::string getImagePath();
};
