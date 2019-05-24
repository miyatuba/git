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

//���̕ӂ�Aint�ň����čŏI�I��float�ɕϊ����邩�A�������͂��̋t���A�͂����肳���Ȃ��Ɗ�Ȃ�
void Hero::MoveLeft(int x)
{
	this->x -= x;
	this->rect_collision.moveCollisionX((float) -x);//�낳�N������
}

void Hero::MoveRight(int x)
{
	this->x += x;
	this->rect_collision.moveCollisionX((float) x);//�낳�N������
}

void Hero::MoveTop(int y)
{
	int display_position = -y;//DX���C�u�����ł͕\����Y���W���t�ɂȂ邽��
	this->y += display_position;
	this->rect_collision.moveCollisionY((float) y);//�낳�N������
}

void Hero::MoveBottom(int y)
{
	int display_position = -y;//DX���C�u�����ł͕\����Y���W���t�ɂȂ邽��
	this->y -= display_position;
	this->rect_collision.moveCollisionY((float) -y);//�낳�N������
}

void Hero::MovePositionByInput(Input input)
{
	if (input.IsInputLeft()) {
		this->MoveLeft(Hero::MOVE_FORCE_POINT);
	}
	if (input.IsInputRight()) {
		this->MoveRight(Hero::MOVE_FORCE_POINT);
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
	this->CheckFallStatus();
	if (this->is_fall) {
		this->MoveBottom(Hero::FALL_SPEED);//�d�͉����x�́A�����x�ɍő�l��t���Ď����\��
	}

	this->CheckJumpStatus();
	if (this->is_jump) {
		this->MoveTop(Hero::JUMP_FORCE_POINT);
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
	//��œ����蔻�菈����ǉ�
	//����160�𒴂��Ȃ��悤�ɂ���
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