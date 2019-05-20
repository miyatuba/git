#pragma once
#include "../../view/IDraw.h"
#include <string>

//IDrawはいらないマップ描画はmapと言う括りで対応した方が良いかも。
class MapTip {
private:
	int map_tip_handle;
public:
	MapTip(int);
	int getMapTipHandol();
};