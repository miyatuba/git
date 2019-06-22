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

	const static int X_SIZE = 64;
	const static int Y_SIZE = 64;
	
	std::string IMAGE_PATH = "./resource/image/test_image.jpg";
	int defult_image;

	RectCollision rect_collision;
	RectCollision before_moving_rect_collision;
	const static float X_LEFT_RECT_COLLISION;
	const static float X_RIGHT_RECT_COLLISION;
	const static float Y_TOP_RECT_COLLISION;
	const static float Y_BOTTOM_RECT_COLLISION;

	int x = 170;//初期ポジションを入れておく（普通コンストラクターで設定する気が
	int y = -250;//初期ポジションを入れておく（普通コンストラクターで設定する気が

	bool is_fall = true;
	bool is_jump = false;

	bool can_left_move = true;
	bool can_right_move = true;
	bool can_up_move = true;
	bool can_down_move = true;

	int jump_frame_elapsed_time = this->JUMP_FRAME_TIME;

public:
	Hero();

	void initForLoop();

	void MoveLeft(int);
	void MoveRight(int);
	void MoveUp(int);
	void MoveDown(int);

	void MovePositionByInput(Input);
	void MoveNoInput();

	void UpdateBeforeMovingRectCollision();

	void CheckJumpStatus();
	void ChangeJumpStatus();

	void OffFallStatus();
	void OnFallStatus();

	bool isFall();
	bool isJump();

	virtual int getPositionX() const;
	virtual int getPositionY() const;
	virtual int getImageHandle() const;
	virtual RectCollision getCollision() const;

	RectCollision getBeforeMovingRectCollision();

	int getSizeY();
	int getSizeX();
};
