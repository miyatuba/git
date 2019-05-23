#pragma once
#include "../../view/IDraw.h"
#include "../../collision/RectCollision.h"
#include <string>

//IDrawはいらないマップ描画はmapと言う括りで対応した方が良いかも。
class MapTip {
private:
	RectCollision rectCollision;
	int map_tip_handle;
public:
	MapTip(int);
	int getMapTipHandol();
	bool hasCollision();
};