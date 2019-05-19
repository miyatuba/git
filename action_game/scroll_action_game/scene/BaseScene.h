#pragma once
#include "../input/Input.h"
#include "../view/Draw.h"

//インターフェースの方が良いのか？
class BaseScene 
{
private:
protected:
	Input input;
	Draw draw;
public:
	BaseScene();
	BaseScene(int);
	virtual void Play();
	bool isGameEnd();

};