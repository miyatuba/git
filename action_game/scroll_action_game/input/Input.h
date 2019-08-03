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
	bool isInputLeft();
	bool isInputRight();
	bool isInputUp();
	bool isInputDown();
	bool isInputA();
	bool isInputEscape();
	bool isInput1();
	bool isInput2();
	bool isInput3();
	bool isInput4();

};