#pragma once
#include "../../view/IDraw.h"
#include "../../collision/RectCollision.h"
#include <string>

//IDraw�͂���Ȃ��}�b�v�`���map�ƌ�������őΉ����������ǂ������B
class MapTip {
private:
	RectCollision rect_collision;
	bool has_collision;

	const static float X_LEFT_RECT_COLLISION;
	const static float X_RIGHT_RECT_COLLISION;
	const static float Y_TOP_RECT_COLLISION;
	const static float Y_BOTTOM_RECT_COLLISION;

	const static float X_RECT_COLLISION;
	const static float Y_RECT_COLLISION;

	int map_tip_handle;

	//�f�o�b�O�p
	int map_tip_index_x;
	int map_tip_index_y;
	void setMapTipIndex(int x, int y);

public:
	MapTip(int, bool has_collision, int, int);
	int getMapTipHandol();
	bool hasCollision();
	RectCollision getCollision();

	bool hasMapTipHandle();
};