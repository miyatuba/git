#include "main.h"
#include <fstream>
#include <string>

bool is_debug_mode = false;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	ChangeWindowMode(TRUE);
	//SetKeyboardNotDirectInputFlag(TRUE);//デバッグ用

	try {
		GameMain();

	}
	catch (std::string error_message){
		std::ofstream outputfile("error_log/error_log.txt");
		outputfile << error_message;
		outputfile.close();
		DxLib_End();
	}
	

	return 0;
}

void GameMain() 
{
	if (DxLib_Init() == -1)
	{
		std::string error_message = "Exception : DxLib Init false";
		throw error_message;
	}

	//debug
/*	int chip[9];
	LoadDivGraph("./resource/image/test_block.png", 9, 3, 3, 80, 80, chip);*/

	SceneService scene_service;

	while (true) {
		scene_service.Play();

		
		//debug
		/*
		ClearDrawScreen();
		int* p_map_tip_list = chip;
		DrawGraph(0 * 80, 0 * 80, (*(p_map_tip_list + 0) + 0), FALSE);
		DrawGraph(1 * 80, 1 * 80, chip[1], FALSE);
		DrawGraph(2 * 80, 2 * 80, chip[2], FALSE);
		DrawGraph(3 * 80, 3 * 80, chip[3], FALSE); ScreenFlip();*/

		if (scene_service.isGameEnd()) break;

	}

	DxLib_End();
}


