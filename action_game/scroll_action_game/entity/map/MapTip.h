#pragma once
#include "../../view/IDraw.h"
#include "../../collision/RectCollision.h"
#include <string>

//IDraw�͂���Ȃ��}�b�v�`���map�ƌ�������őΉ����������ǂ������B
class MapTip {
private:
	RectCollision rectCollision;
	int map_tip_handle;
public:
	MapTip(int);
	int getMapTipHandol();
	bool hasCollision();
};