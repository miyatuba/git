#include "DemoScene.h"

DemoScene::DemoScene()
{
	Hero hero;
	this->hero = hero;
}


void DemoScene::Play()
{
	BaseScene::Play();
	
	this->hero.MovePositionByInput(this->input);
	this->hero.MoveNoInput();

	this->draw.GameDraw(hero);
}

