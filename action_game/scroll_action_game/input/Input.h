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
	bool is_input_1 = false;
	bool is_input_2 = false;
	bool is_input_3 = false;
	bool is_input_4 = false;

public:
	void CheckInput();
	bool IsInputLeft();
	bool IsInputRight();
	bool IsInputUp();
	bool IsInputDown();
	bool IsInputA();
	bool IsInputEscape();
	bool IsInput1();
	bool IsInput2();
	bool IsInput3();
	bool IsInput4();

};