#pragma once
#include "DemoScene.h"

class SceneService
{
private:
	//scene�̎�ʃ^�C�v
	static const int SCENE_TYPE_DEMO = 1;
	
	int current_scene_type_id;

	DemoScene demo_scene;//�����ƒ��ׂĂ݂����ǁAC++��1�̕ϐ��ɐF��Ȍ^�����邱�Ƃ��s�\�Ȃ��߂ɁA���id�Ō��݂̃V�[���𐧌䂷��d�g�݂����
public:
	SceneService();
	void Play();

	bool isGameEnd();
};
