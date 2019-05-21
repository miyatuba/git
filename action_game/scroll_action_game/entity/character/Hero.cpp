#include "Hero.h"

const float Hero::X_LEFT_RECT_COLLISION = 0.0f;
const float Hero::X_RIGHT_RECT_COLLISION = 64.0f;
const float Hero::Y_TOP_RECT_COLLISION = 0.0f;
const float Hero::Y_BOTTOM_RECT_COLLISION = 64.0f;

Hero::Hero() 
{
	RectCollision rect_collision(this->X_LEFT_RECT_COLLISION, this->X_RIGHT_RECT_COLLISION, this->Y_TOP_RECT_COLLISION, this->Y_BOTTOM_RECT_COLLISION);
	this->rect_collision = rect_collision;
}

void Hero::MovePositionByInput(Input input)
{
	if (input.IsInputLeft()) {
		this->x -= 8;
	}
	if (input.IsInputRight()) {
		this->x += 8;
	}

	if (input.IsInputA()) {
		if (! this->is_jump) { //空が飛べる前提なので、落下状態は見ない
			this->ChangeJumpStatus();
			this->jump_frame_elapsed_time = Hero::JUMP_FRAME_TIME;
		}

	}
}

void Hero::MoveNoInput()
{
	this->CheckFallStatus();
	if (this->is_fall) {
		this->y += Hero::FALL_SPEED;//今作では重力加速度はない予定
	}

	this->CheckJumpStatus();
	if (this->is_jump) {
		this->y -= Hero::JUMP_FORCE_POINT;
		this->jump_frame_elapsed_time -= 1;
	}
	
}

void Hero::ChangeJumpStatus()
{
	this->is_fall = false;
	this->is_jump = true;
}

void Hero::CheckJumpStatus()
{
	if (this->jump_frame_elapsed_time == 0)
	{
		this->is_jump = false;
		this->is_fall = true;
	}
}

void Hero::CheckFallStatus()
{
	//後で当たり判定処理を追加
	//今は160を超えないようにする
	if (this->y >= 320) {
		this->is_fall = false;
	}
}

int Hero::getPositionX() const
{
	return this->x;
}

int Hero::getPositionY() const
{
	return this->y;
}

std::string Hero::getImagePath() const
{
	return this->IMAGE_PATH;
}

BaseCollision Hero::getCollision() const
{
	return this->rect_collision;
}