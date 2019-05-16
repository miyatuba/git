#include "main.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) return -1;

	//この辺り、sceneクラスで管理する必要出てくる。
	Draw draw;
	Input input;
	Hero hero;

	while (true) {
		input.CheckInput();
		hero.MovePositionByInput(input);
		draw.GameDraw(hero);
		if (input.IsInputEscape()) break;
	}

	DxLib_End();

	return 0;
}