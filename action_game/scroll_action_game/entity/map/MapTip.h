#pragma once
#include "../../view/IDraw.h"
#include <string>

//IDraw�͂���Ȃ��}�b�v�`���map�ƌ�������őΉ����������ǂ������B
class MapTip {
private:
	int map_tip_handle;
public:
	MapTip(int);
	int getMapTipHandol();
};