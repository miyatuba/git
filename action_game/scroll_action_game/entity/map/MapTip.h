#pragma once
#include "../../view/IDraw.h"
#include "../../collision/RectCollision.h"
#include <string>

//IDrawはいらないマップ描画はmapと言う括りで対応した方が良いかも。
class MapTip {
private:
	RectCollision rect_collision;
	bool has_collision;

	const static float X_LEFT_RECT_COLLISION;
	const static float X_RIGHT_RECT_COLLISION;
	const static float Y_TOP_RECT_COLLISION;
	const static float Y_BOTTOM_RECT_COLLISION;
	int map_tip_handle;
public:
	MapTip(int, bool has_collision);
	int getMapTipHandol();
	bool hasCollision();
	RectCollision getCollision();
};