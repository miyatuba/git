#include "main.h"


bool is_debug_mode = true;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	ChangeWindowMode(TRUE);


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
	if (DxLib_Init() == -1) {
		std::string error_message = "Exception : DxLib Init false";
		throw error_message;
	}

	if (is_debug_mode == true) {
		DebugMode::OnDebugMode();
	}

	SceneService scene_service;

	while (true) {
		scene_service.Play();

	
		WaitTimer(20);

		if (scene_service.isGameEnd()) break;

	}

	DxLib_End();
}


