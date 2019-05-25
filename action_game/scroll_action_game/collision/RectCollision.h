#pragma once
#include "BaseCollision.h"

class RectCollision : public BaseCollision
{
private:
	float initial_x_left;
	float initial_x_right;
	float initial_y_top;
	float initial_y_bottom;

	float current_x_left;
	float current_x_right;
	float current_y_top;
	float current_y_bottom;
	
	int distance_moved_x_left = 0;
	int distance_moved_x_right = 0;
	int distance_moved_y_top = 0;
	int distance_moved_y_bottom = 0;
	

public:
	RectCollision();
	RectCollision(float, float, float, float);
	void moveCollisionX(int);
	void moveCollisionY(int);

	float getCurrentXLeft();
	float getCurrentXRight();
	float getCurrentYTop();
	float getCurrentYBottom();
};