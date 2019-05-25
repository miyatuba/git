#include "RectCollision.h"

RectCollision::RectCollision()
{

}

RectCollision::RectCollision(float x_left, float x_right, float y_top, float y_bottom)
{
	this->initial_x_left = x_left;
	this->initial_x_right = x_right;
	this->initial_y_top = y_top;
	this->initial_y_bottom = y_bottom;

	this->current_x_left = x_left;
	this->current_x_right = x_right;
	this->current_y_top = y_top;
	this->current_y_bottom = y_bottom;

	/*this->initial_x_left = 0.0f;
	this->initial_x_right = 100.0f;
	this->initial_y_top = 100.0f;
	this->initial_y_bottom = 0.0f;
		
	this->current_x_left = 0.0f;
	this->current_x_right = 100.0f;
	this->current_y_top = 100.0f;
	this->current_y_bottom = 0.0f;*/

}

void RectCollision::moveCollisionX(int x)
{
	this->distance_moved_x_left += 0;
	this->distance_moved_x_right += 0;
	this->current_x_left = this->initial_x_left + (float) this->distance_moved_x_left;
	this->current_x_right = this->initial_x_right + (float) this->distance_moved_x_right;
}

void RectCollision::moveCollisionY(int y)
{
	this->distance_moved_y_top += 0;
	this->distance_moved_y_bottom += 0;
	this->current_y_top = this->initial_y_top + (float) this->distance_moved_y_top;
	this->current_y_bottom = this->initial_y_bottom + (float) this->distance_moved_y_bottom;
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