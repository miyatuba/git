#include "MainCamera.h"

//�㉺�ƍ��E���ꂼ��̒��S���W����AHero���ړ�����ۂɌv�Z���X�N���[�����������߂�B
//�`�悷����̂ɁA�`�悷��ۂɂ��̍��W�ɃX�N���[��������n���ĕ␳���|���āA�J�����X�N���[�����Ă���悤�Ɍ�����
//���W�͏㉺�̒��S��Hero�̍��W�A���E�̒��S��Hero�̍��W�A�܂���ʕ␳���|���鎞�ɁA�O���̈ړ��ł��邩�ǂ��������f����

MainCamera::MainCamera()
{

}

MainCamera::MainCamera(int initial_position_x, int initial_position_y)
{
	this->initial_left_position_x = initial_position_x;
	this->initial_top_position_y = initial_position_y;
	this->current_left_position_x = initial_position_x;
	this->current_top_position_y = initial_position_y;
}


void MainCamera::moveLeftX(int x)
{
	this->current_left_position_x -= x;
}
void MainCamera::moveRightX(int x)
{
	this->current_left_position_x += x;
}
void MainCamera::moveUpY(int y)
{
	this->current_top_position_y += y;
}
void MainCamera::moveDownY(int y)
{
	this->current_top_position_y -= y;
}

int MainCamera::MovingDistanceX()
{
	return this->current_left_position_x;
}

int MainCamera::MovingDistanceY()
{
	return this->current_top_position_y;
}

void MainCamera::TrackingByTargetPosition(int x, int y)
{
	if (! this->shouldRevision()) return;

	int center_position_x = this->getCenterPositionX();
	int difference_distance_x = x - center_position_x;
	this->current_left_position_x += difference_distance_x;

	int center_position_y = this->getCenterPositionY();
	int difference_distance_y = -y - center_position_y;
	this->current_top_position_y += difference_distance_y;
}

//private
int MainCamera::getCenterPositionX()
{
	return this->current_left_position_x + (MainCamera::WIDTH / 2);
}

//private
int MainCamera::getCenterPositionY()
{
	return this->current_top_position_y + (MainCamera::HEIGHT / 2);
}


void MainCamera::OnShouldRevision()
{
	this->should_revision = true;
}

void MainCamera::OffShouldRevision()
{
	this->should_revision = false;
}

bool MainCamera::shouldRevision()
{
	return this->should_revision;
}

RectCollision MainCamera::createRectCollision()
{
	RectCollision rect_collision(
		this->current_left_position_x,
		this->current_left_position_x + MainCamera::WIDTH,
		this->current_top_position_y,
		this->current_top_position_y - MainCamera::HEIGHT
		);

	return rect_collision;
}