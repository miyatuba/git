#include "BaseScene.h"

BaseScene::BaseScene()
{

}

BaseScene::BaseScene(int stage_number)
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
	return this->input.IsInputEscape() == true;
}
