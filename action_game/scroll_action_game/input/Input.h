#pragma once
#include "DxLib.h"

class Input
{
private:
	boolean is_input_left = false;
	boolean is_input_right = false;
	boolean is_input_up = false;
	boolean is_input_down = false;
	boolean is_input_escape = false;

public:
	void CheckInput();
	boolean IsInputLeft();
	boolean IsInputRight();
	boolean IsInputUp();
	boolean IsInputDown();
	boolean IsInputEscape();
};