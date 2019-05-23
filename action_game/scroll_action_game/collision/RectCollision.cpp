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

	this->current_x_left = x_left;
	this->current_x_right = x_right;
	this->current_y_top = y_top;
	this->current_y_bottom = y_bottom;
}

void RectCollision::moveCollisionX(float x)
{
	this->current_x_left = this->x_left + x;
	this->current_x_right = this->x_right + x;
}

void RectCollision::moveCollisionY(float y)
{
	this->current_y_top = this->y_top + y;
	this->current_y_bottom = this->y_bottom + y;
}


float RectCollision::getCurrentXLeft()
{
	return this->current_x_left;
}
float RectCollision::getCurrentXRight()
{
	return this->current_x_right;
}
float RectCollision::getCurrentYTop()
{
	return this->current_y_top;
}
float RectCollision::getCurrentYBottom()
{
	return this->current_y_bottom;
}