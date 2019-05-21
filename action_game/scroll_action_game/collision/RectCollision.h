#pragma once
#include "BaseCollision.h"

class RectCollision : public BaseCollision
{
private:
	float x_left;
	float x_right;
	float y_top;
	float y_bottom;
	
public:
	RectCollision();
	RectCollision(float, float, float, float);
};