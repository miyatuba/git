#pragma once
#include "../input/Input.h"
#include "../view/Draw.h"
#include "../view/Audio.h"

//インターフェースの方が良いのか？
class BaseScene 
{
private:
protected:
	Input input;
	Draw draw;
	int current_bgm_handle;
	Audio audio;
public:
	BaseScene();
	BaseScene(int);
	virtual void Play();
	bool isGameEnd();

};