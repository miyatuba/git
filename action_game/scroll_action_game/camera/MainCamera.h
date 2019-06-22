#pragma once
#include "../collision/RectCollision.h"

class MainCamera
{
private:
	int initial_left_position_x = 0;//初期座標
	int initial_top_position_y = 0;//初期座標
	int current_left_position_x = 0;
	int current_top_position_y = 0;
	int before_left_position_x = 0;
	int before_top_position_y = 0;

	const static int WIDTH = 640;
	const static int HEIGHT = 640;

	bool should_revision = true;

	int getCenterPositionX();
	int getCenterPositionY();

	bool shouldRevision();
public:
	MainCamera();
	MainCamera(int, int);
	void moveLeftX(int);
	void moveRightX(int);
	void moveUpY(int);
	void moveDownY(int);
	int MovingDistanceX();
	int MovingDistanceY();
	void TrackingByTargetPosition(int, int);
	void TrackingByTargetPositionX(int);
	void TrackingByTargetPositionY(int);

	bool isCameraMoveLeft();
	bool isCameraMoveRight();

	void OnShouldRevision();
	void OffShouldRevision();

	RectCollision createRectCollision();
	RectCollision createBeforeRectCollision();

	void initForLoop();

};