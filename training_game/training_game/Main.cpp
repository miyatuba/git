
# include <Siv3D.hpp> // OpenSiv3D v0.4.0
# include "App/Source/Service/Scene/SceneService.h"

void Main()
{
	SceneService scene_service;
	while (System::Update()) {
		//System::Exit()をコールするとループを抜ける用だ
		scene_service.Update();
	}
	scene_service.Finalize();


}