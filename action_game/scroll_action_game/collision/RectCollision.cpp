#include "RectCollision.h"

RectCollision::RectCollision()
{

}

RectCollision::RectCollision(float x_left, float x_right, float y_top, float y_bottom)
{
	this->x_left = x_left;
	this->x_right = x_right;
	this->y_top = y_top;
	this->y_bottom = y_bottom;
}
