#pragma once
#include "DxLib.h"
#include <string>
#include "../../input/Input.h"
#include "../../view/IDraw.h"

class Hero : virtual public IDraw
{
private:
	const static int JUMP_FORCE_POINT = 32;
	const static int JUMP_FRAME_TIME = 5;
	const static int FALL_SPEED = 16;

	int x = 0;
	int y = 10;
	std::string image_path = "./resource/image/test_image.jpg";
	bool is_fall = true;
	bool is_jump = false;

	int jump_frame_elapsed_time = this->JUMP_FRAME_TIME;

public:
	Hero();
	void MovePositionByInput(Input);
	void MoveNoInput();

	void CheckJumpStatus();
	void ChangeJumpStatus();

	void CheckFallStatus();
	virtual int getPositionX() const;
	virtual int getPositionY() const;
	virtual std::string getImagePath() const;
};
