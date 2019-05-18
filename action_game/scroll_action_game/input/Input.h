#pragma once
#include "DxLib.h"

class Input
{
private:
	bool is_input_left = false;
	bool is_input_right = false;
	bool is_input_up = false;
	bool is_input_down = false;
	bool is_input_a = false;
	bool is_input_escape = false;

public:
	void CheckInput();
	bool IsInputLeft();
	bool IsInputRight();
	bool IsInputUp();
	bool IsInputDown();
	bool IsInputA();
	bool IsInputEscape();
};