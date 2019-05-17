#include "main.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) return -1;

	//���̕ӂ�Ascene�N���X�ŊǗ�����K�v�o�Ă���B
	
	SceneService scene_service;


	while (true) {
		scene_service.Play();

		if (scene_service.isGameEnd()) break;
	}

	DxLib_End();

	return 0;
}