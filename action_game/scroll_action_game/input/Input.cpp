#include "Input.h"

void Input::CheckInput() 
{
	this->is_input_left = (boolean)CheckHitKey(KEY_INPUT_LEFT);
	this->is_input_right = (boolean)CheckHitKey(KEY_INPUT_RIGHT);
	this->is_input_up = (boolean)CheckHitKey(KEY_INPUT_UP);
	this->is_input_down = (boolean)CheckHitKey(KEY_INPUT_DOWN);
	this->is_input_escape = (boolean)CheckHitKey(KEY_INPUT_ESCAPE);
}

boolean Input::IsInputLeft() 
{
	return this->is_input_left;
}

boolean Input::IsInputRight() 
{
	return this->is_input_right;
}

boolean Input::IsInputUp() 
{
	return this->is_input_up;
}

boolean Input::IsInputDown() 
{
	return this->is_input_down;
}

boolean Input::IsInputEscape()
{
	return this->is_input_escape;
}