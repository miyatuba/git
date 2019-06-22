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

	const static float X_RECT_COLLISION;
	const static float Y_RECT_COLLISION;

	const static int TYPE_ID_CAMERA_MOVEMENT_RESTRICTION = -1;

	int map_tip_handle;

	int map_tip_id;

	//デバッグ用
	int map_tip_index_x;
	int map_tip_index_y;

public:
	MapTip(int, int, bool has_collision, int, int);
	int getMapTipHandol();
	bool hasCollision();
	RectCollision getCollision();

	bool hasMapTipHandle();
	bool isCameraMovementRestriction();

	void setMapTipIndex(int x, int y);
};