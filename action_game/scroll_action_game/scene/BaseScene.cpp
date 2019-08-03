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
	Audio audio;
	this->audio = audio;
}

void BaseScene::Play()
{	
	this->input.CheckInput();
	return;
}


bool BaseScene::isGameEnd()
{
	return this->input.isInputEscape() == true;
}
