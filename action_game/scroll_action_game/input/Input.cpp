#include "Input.h"

void Input::CheckInput() 
{
	this->is_input_left = (bool)CheckHitKey(KEY_INPUT_LEFT);
	this->is_input_right = (bool)CheckHitKey(KEY_INPUT_RIGHT);
	this->is_input_up = (bool)CheckHitKey(KEY_INPUT_UP);
	this->is_input_down = (bool)CheckHitKey(KEY_INPUT_DOWN);
	this->is_input_a = (bool)CheckHitKey(KEY_INPUT_A);
	
	this->is_input_escape = (bool)CheckHitKey(KEY_INPUT_ESCAPE);


}

bool Input::IsInputLeft() 
{
	return this->is_input_left;
}

bool Input::IsInputRight() 
{
	return this->is_input_right;
}

bool Input::IsInputUp() 
{
	return this->is_input_up;
}

bool Input::IsInputDown() 
{
	return this->is_input_down;
}

bool Input::IsInputA()
{
	return this->is_input_a;
}

bool Input::IsInputEscape()
{
	return this->is_input_escape;
}