#include "main.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1) return -1;

	while (true) {
		GameDraw();
	}

	DxLib_End();

	return 0;
}