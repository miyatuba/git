#include "Hero.h"

const float Hero::X_LEFT_RECT_COLLISION = 0.0f;
const float Hero::X_RIGHT_RECT_COLLISION = 64.0f;
const float Hero::Y_TOP_RECT_COLLISION = 0.0f;
const float Hero::Y_BOTTOM_RECT_COLLISION = 64.0f;

Hero::Hero() 
{
	RectCollision rect_collision((float) this->x,
								 (float) (this->x + Hero::X_SIZE),
								 (float) this->y,
								 (float) (this->y - Hero::Y_SIZE)
	);

	this->stand_image_handle = LoadGraph(this->IMAGE_PATH_STAND.c_str());
	this->jump_image_handle = LoadGraph(this->IMAGE_PATH_JUMP.c_str());
	this->rect_collision = rect_collision;
}

void Hero::initForLoop()
{
	this->can_down_move = true;
	this->can_left_move = true;
	this->can_right_move = true;
	this->can_up_move = true;
	this->UpdateBeforeMovingRectCollision();
}

//この辺り、intで扱って最終的にfloatに変換するか、もしくはその逆か、はっきりさせないと危ない
void Hero::MoveLeft(int x)
{
	if (!this->can_left_move) return;
	this->x -= x;
	this->rect_collision.moveCollisionX(-x);//誤さ起きそう
}

void Hero::MoveRight(int x)
{
	if (!this->can_right_move) return;
	this->x += x;
	this->rect_collision.moveCollisionX(x);//誤さ起きそう
}

void Hero::MoveUp(int y)
{
	if (!this->can_up_move) return;
	this->y += y;
	this->rect_collision.moveCollisionY(y);//誤さ起きそう
}

void Hero::MoveDown(int y)
{
	if (!this->can_down_move) return;
	this->y -= y;
	this->rect_collision.moveCollisionY(-y);//誤さ起きそう
}

void Hero::MovePositionByInput(Input input)
{
	if (input.IsInputLeft()) {
		this->MoveLeft(Hero::MOVE_FORCE_POINT);
		this->changeDirectionLeft();
	}
	if (input.IsInputRight()) {
		this->MoveRight(Hero::MOVE_FORCE_POINT);
		this->changeDirectionRight();
	}
	if (input.IsInputUp()) {
		//this->MoveUp(Hero::MOVE_FORCE_POINT);
	}
	if (input.IsInputDown()) {
		//this->MoveDown(Hero::MOVE_FORCE_POINT);
	}


	if (input.IsInputA()) {
		//空が飛べる前提なので、落下状態は見ない
		this->ChangeJumpStatus();
		this->jump_frame_elapsed_time = Hero::JUMP_FRAME_TIME;
	}
}

void Hero::MoveNoInput()
{
	//this->CheckFallStatus();
	if (this->is_fall) {
		this->MoveDown(Hero::FALL_SPEED);//重力加速度は、加速度に最大値を付けて実装予定
	}

	this->CheckJumpStatus();
	if (this->is_jump) {
		this->MoveUp(Hero::JUMP_FORCE_POINT);
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
	if (this->is_jump) {
		if (this->jump_frame_elapsed_time == 0)
		{
			this->is_jump = false;
			this->is_fall = true;
		}
	}
}


void Hero::OffFallStatus()
{
	//CheckFallStatusに集約することになると思う
	this->is_fall = false;
}

void Hero::OnFallStatus()
{
	//CheckFallStatusに集約することになると思う
	this->is_fall = true;
}

int Hero::getPositionX() const
{
	return this->x;
}

int Hero::getPositionY() const
{
	return this->y;
}

int Hero::getImageHandle()
{
	//アニメーション実装時に、個々の返しは切り替えにする
	if (this->is_jump) {
		return this->jump_image_handle;
	}
	if (this->is_fall) {
		return this->jump_image_handle;
	}
	return this->stand_image_handle;
}

RectCollision Hero::getCollision() const
{
	return this->rect_collision;
}

bool Hero::isFall()
{
	return this->is_fall;
}

bool Hero::isJump()
{
	return this->is_jump;
}

void Hero::UpdateBeforeMovingRectCollision()
{
	RectCollision current_rect_collision = this->rect_collision;
	RectCollision before_moving_rect_collision(
		current_rect_collision.getCurrentXLeft(),
		current_rect_collision.getCurrentXRight(),
		current_rect_collision.getCurrentYTop(),
		current_rect_collision.getCurrentYBottom()
	);
	this->before_moving_rect_collision = before_moving_rect_collision;
}

RectCollision Hero::getBeforeMovingRectCollision()
{
	return this->before_moving_rect_collision;
}

int Hero::getSizeY()
{
	return Hero::Y_SIZE;
}

int Hero::getSizeX()
{
	return Hero::X_SIZE;
}

bool Hero::isDirectionRight() const
{
	return this->direction == Hero::DIRECTION_RIGHT;
}

bool Hero::isDirectionLeft() const
{
	return this->direction == Hero::DIRECTION_LEFT;
}

void Hero::changeDirectionRight()
{
	this->direction = Hero::DIRECTION_RIGHT;
}

void Hero::changeDirectionLeft()
{
	this->direction = Hero::DIRECTION_LEFT;
}