#pragma once
#include "../collision/RectCollision.h"

class MainCamera
{
private:
	int initial_left_position_x = 0;//èâä˙ç¿ïW
	int initial_top_position_y = 0;//èâä˙ç¿ïW
	int current_left_position_x = 0;
	int current_top_position_y = 0;
	int before_left_position_x = 0;
	int before_top_position_y = 0;

	const static int WIDTH = 640;
	const static int HEIGHT = 480;

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
	void TrackingByTargetPositionX(int);
	void TrackingByTargetPositionY(int);

	bool isCameraMovedLeft();
	bool isCameraMovedRight();
	bool isCameraMovedUp();
	bool isCameraMovedDown();

	void OnShouldRevision();
	void OffShouldRevision();

	RectCollision createRectCollision();
	RectCollision createBeforeRectCollision();

	void initForLoop();

};