#include "main.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) return -1;

	//この辺り、sceneクラスで管理する必要出てくる。
	
	SceneService scene_service;


	while (true) {
		scene_service.Play();

		if (scene_service.isGameEnd()) break;
	}

	DxLib_End();

	return 0;
}