#pragma once
#include "../input/Input.h"
#include "../view/Draw.h"

//�C���^�[�t�F�[�X�̕����ǂ��̂��H
class BaseScene 
{
private:
	
	
protected:
	Input input;
	Draw draw;
public:
	BaseScene();
	virtual void Play();
	bool isGameEnd();

};