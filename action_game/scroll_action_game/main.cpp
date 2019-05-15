#include "main.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) return -1;

	//���̕ӂ�Ascene�N���X�ŊǗ�����K�v�o�Ă���B
	Draw draw;
	Input input;
	Hero hero;

	while (true) {
		input.CheckInput();
		hero.MovePositionByInput(input);
		draw.GameDraw(hero);//�I�u�W�F�N�g���ǂ��n���̂����B�Ƃ肠�����e�X�g����Ȃ̂ō���͂��̂܂�
		if (input.IsInputEscape()) break;
	}

	DxLib_End();

	return 0;
}