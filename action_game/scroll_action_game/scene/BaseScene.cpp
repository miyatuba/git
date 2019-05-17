#include "BaseScene.h"

BaseScene::BaseScene()
{
	Draw draw;
	this->draw = draw;
	Input input;
	this->input = input;
}

void BaseScene::Play()
{	
	this->input.CheckInput();
	return;
}


bool BaseScene::isGameEnd()
{
	return this->input.IsInputEscape() == TRUE;
}
