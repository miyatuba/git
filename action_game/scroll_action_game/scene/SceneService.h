#pragma once
#include "DemoScene.h"

class SceneService
{
private:
	BaseScene current_scene;//���炭�����̓X�[�p�[�N���X�ɒ����Ȃ��Ƃ����Ȃ�
public:
	SceneService();
	void Play();

	bool isGameEnd();
};
