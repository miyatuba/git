#include "Hero.h"

Hero::Hero() {

}

void Hero::MovePositionByInput(Input input)
{
	if (input.IsInputLeft()) {
		this->x -= 8;
	}
	if (input.IsInputRight()) {
		this->x += 8;
	}
	/*if (input.IsInputUp()) {
//		this->y -= 8;
	}*/
	/*if (input.IsInputDown()) {
//		this->y += 8;
	}*/

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
		this->y += Hero::FALL_SPEED;//����ł͏d�͉����x�͂Ȃ��\��
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
	return this->image_path;
}