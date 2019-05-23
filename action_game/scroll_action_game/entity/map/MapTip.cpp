#include "MapTip.h"

const float MapTip::X_LEFT_RECT_COLLISION = 0.0f;
const float MapTip::X_RIGHT_RECT_COLLISION = 80.0f;
const float MapTip::Y_TOP_RECT_COLLISION = 0.0f;
const float MapTip::Y_BOTTOM_RECT_COLLISION = 80.0f;

MapTip::MapTip(int map_tip_handle, bool has_collision)
{
	this->map_tip_handle = map_tip_handle;

	RectCollision rect_collision(this->X_LEFT_RECT_COLLISION, this->X_RIGHT_RECT_COLLISION, this->Y_TOP_RECT_COLLISION, this->Y_BOTTOM_RECT_COLLISION);
	this->rect_collision = rect_collision;

	this->has_collision = has_collision;
}

int MapTip::getMapTipHandol()
{
	return map_tip_handle;
}

bool MapTip::hasCollision()
{
	return false;
}

RectCollision MapTip::getCollision()
{
	return this->rect_collision;
}