#pragma once
#include "DemoScene.h"

class SceneService
{
private:
	DemoScene current_scene;//�����ƒ��ׂĂ݂����ǁAC++��1�̕ϐ��ɐF��Ȍ^�����邱�Ƃ��s�\�Ȃ��߂ɁA���id�Ō��݂̃V�[���𐧌䂷��d�g�݂����
public:
	SceneService();
	void Play();

	bool isGameEnd();
};
