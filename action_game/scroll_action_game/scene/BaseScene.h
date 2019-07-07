#pragma once
#include "../input/Input.h"
#include "../view/Draw.h"
#include "../view/Audio.h"

//�C���^�[�t�F�[�X�̕����ǂ��̂��H
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