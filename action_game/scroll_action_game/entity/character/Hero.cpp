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

	this->defult_image = LoadGraph(this->IMAGE_PATH.c_str());
	this->rect_collision = rect_collision;
}

//���̕ӂ�Aint�ň����čŏI�I��float�ɕϊ����邩�A�������͂��̋t���A�͂����肳���Ȃ��Ɗ�Ȃ�
void Hero::MoveLeft(int x)
{
	this->x -= x;
	this->rect_collision.moveCollisionX(-x);//�낳�N������
}

void Hero::MoveRight(int x)
{
	this->x += x;
	this->rect_collision.moveCollisionX(x);//�낳�N������
}

void Hero::MoveUp(int y)
{
	this->y += y;
	this->rect_collision.moveCollisionY(y);//�낳�N������
}

void Hero::MoveDown(int y)
{
	this->y -= y;
	this->rect_collision.moveCollisionY(-y);//�낳�N������
}

void Hero::MovePositionByInput(Input input)
{
	if (input.IsInputLeft()) {
		this->MoveLeft(Hero::MOVE_FORCE_POINT);
	}
	if (input.IsInputRight()) {
		this->MoveRight(Hero::MOVE_FORCE_POINT);
	}
	if (input.IsInputUp()) {
		//this->MoveUp(Hero::MOVE_FORCE_POINT);
	}
	if (input.IsInputDown()) {
		//this->MoveDown(Hero::MOVE_FORCE_POINT);
	}


	if (input.IsInputA()) {
		if (! this->is_jump) { //�󂪔�ׂ�O��Ȃ̂ŁA������Ԃ͌��Ȃ�
			this->ChangeJumpStatus();
			this->jump_frame_elapsed_time = Hero::JUMP_FRAME_TIME;
		}

	}
}

void Hero::MoveNoInput()
{
	//this->CheckFallStatus();
	if (this->is_fall) {
		this->MoveDown(Hero::FALL_SPEED);//�d�͉����x�́A�����x�ɍő�l��t���Ď����\��
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

//�����g��Ȃ�
void Hero::CheckFallStatus()
{
	//��œ����蔻�菈����ǉ�
	//����160�𒴂��Ȃ��悤�ɂ���
}

void Hero::OffFallStatus()
{
	//CheckFallStatus�ɏW�񂷂邱�ƂɂȂ�Ǝv��
	this->is_fall = false;
}

void Hero::OnFallStatus()
{
	//CheckFallStatus�ɏW�񂷂邱�ƂɂȂ�Ǝv��
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

int Hero::getImageHandle() const
{
	//�A�j���[�V�����������ɁA�X�̕Ԃ��͐؂�Ԃ��C�ɂ���
	return this->defult_image;
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

//�v��Ȃ�����
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
