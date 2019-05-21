#pragma once
#include "BaseCollision.h"

class RectCollision : public BaseCollision
{
private:
	float x_left;
	float x_right;
	float y_top;
	float y_bottom;

	float current_x_left;
	float current_x_right;
	float current_y_top;
	float current_y_bottom;
	
public:
	RectCollision();
	RectCollision(float, float, float, float);
	void moveCollisionX(float);
	void moveCollisionY(float);
};