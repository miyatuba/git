#include "Input.h"

void Input::CheckInput() 
{
	this->is_input_left = (bool)CheckHitKey(KEY_INPUT_LEFT);
	this->is_input_right = (bool)CheckHitKey(KEY_INPUT_RIGHT);
	this->is_input_up = (bool)CheckHitKey(KEY_INPUT_UP);
	this->is_input_down = (bool)CheckHitKey(KEY_INPUT_DOWN);
	this->is_input_a = (bool)CheckHitKey(KEY_INPUT_A);
	
	this->is_input_escape = (bool)CheckHitKey(KEY_INPUT_ESCAPE);


	this->is_input_1 = (bool)CheckHitKey(KEY_INPUT_1);
	this->is_input_2 = (bool)CheckHitKey(KEY_INPUT_2);
	this->is_input_3 = (bool)CheckHitKey(KEY_INPUT_3);
	this->is_input_4 = (bool)CheckHitKey(KEY_INPUT_4);
}

bool Input::isInputLeft() 
{
	return this->is_input_left;
}

bool Input::isInputRight() 
{
	return this->is_input_right;
}

bool Input::isInputUp() 
{
	return this->is_input_up;
}

bool Input::isInputDown() 
{
	return this->is_input_down;
}

bool Input::isInputA()
{
	return this->is_input_a;
}

bool Input::isInputEscape()
{
	return this->is_input_escape;
}

bool Input::isInput1()
{
	return this->is_input_1;
}

bool Input::isInput2()
{
	return this->is_input_2;
}

bool Input::isInput3()
{
	return this->is_input_3;
}

bool Input::isInput4()
{
	return this->is_input_4;
}