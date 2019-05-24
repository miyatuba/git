#pragma once
#include "DxLib.h"
#include <string>
#include "../../input/Input.h"
#include "../../view/IDraw.h"
#include "../../collision/ICollision.h"
#include "../../collision/RectCollision.h"

class Hero : virtual public IDraw, ICollision
{
private:
	const static int JUMP_FORCE_POINT = 32;
	const static int JUMP_FRAME_TIME = 5;
	const static int FALL_SPEED = 16;
	const static int MOVE_FORCE_POINT = 8;
	
	std::string IMAGE_PATH = "./resource/image/test_image.jpg";
	RectCollision rect_collision;
	const static float X_LEFT_RECT_COLLISION;
	const static float X_RIGHT_RECT_COLLISION;
	const static float Y_TOP_RECT_COLLISION;
	const static float Y_BOTTOM_RECT_COLLISION;

	int x = 90;
	int y = 120;

	bool is_fall = true;
	bool is_jump = false;

	int jump_frame_elapsed_time = this->JUMP_FRAME_TIME;

public:
	Hero();

	void MoveLeft(int);
	void MoveRight(int);
	void MoveTop(int);
	void MoveBottom(int);

	void MovePositionByInput(Input);
	void MoveNoInput();

	void CheckJumpStatus();
	void ChangeJumpStatus();

	void CheckFallStatus();

	bool isFall();
	bool isJump();

	virtual int getPositionX() const;
	virtual int getPositionY() const;
	virtual std::string getImagePath() const;
	virtual RectCollision getCollision() const;
};
