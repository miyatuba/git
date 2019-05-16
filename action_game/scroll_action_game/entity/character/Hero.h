#pragma once
#include "DxLib.h"
#include <string>
#include "../../input/Input.h"
#include "../../view/IDraw.h"

class Hero : virtual public IDraw
{
private:
	int x = 0;
	int y = 0;
	std::string image_path = "./resource/image/test_image.jpg";
public:
	Hero();
	void MovePositionByInput(Input);
	virtual int getPositionX() const;
	virtual int getPositionY() const;
	virtual std::string getImagePath() const;
};
