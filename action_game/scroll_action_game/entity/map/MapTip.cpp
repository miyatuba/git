#include "MapTip.h"

const float MapTip::X_LEFT_RECT_COLLISION = 0.0f;
const float MapTip::X_RIGHT_RECT_COLLISION = 80.0f;
const float MapTip::Y_TOP_RECT_COLLISION = 0.0f;
const float MapTip::Y_BOTTOM_RECT_COLLISION = -80.0f;

const float MapTip::X_RECT_COLLISION = 80.0f;
const float MapTip::Y_RECT_COLLISION = 80.0f;

//map_tip_handle = 0�̓}�b�v�`�b�v�̉摜�`��Ȃ�
MapTip::MapTip(int map_tip_handle, bool has_collision, int x, int y)
{
	this->map_tip_handle = map_tip_handle;

	RectCollision rect_collision(x * MapTip::X_RECT_COLLISION, 
								 (x + 1) * MapTip::X_RECT_COLLISION,
							     y * -MapTip::Y_RECT_COLLISION, 
								 (y + 1) * -MapTip::Y_RECT_COLLISION);

	this->rect_collision = rect_collision;//��������H�������Ȃ�has_collision==false���͐������Ȃ������ǂ�����
	this->has_collision = has_collision;

	this->setMapTipIndex(x, y);
}

//�f�o�b�O�p
void MapTip::setMapTipIndex(int x, int y)
{
	this->map_tip_index_x = x;
	this->map_tip_index_y = y;
}

int MapTip::getMapTipHandol()
{
	return map_tip_handle;
}

bool MapTip::hasCollision()
{
	return this->has_collision;
}

RectCollision MapTip::getCollision()
{
	return this->rect_collision;
}

bool MapTip::hasMapTipHandle()
{
	return this->map_tip_handle != 0;
}
