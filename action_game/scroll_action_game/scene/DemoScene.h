#pragma once
#include <string.h>
#include "BaseScene.h"
#include "../entity/character/Hero.h"
#include "../entity/character/EnemyTest1.h"
#include "../entity/stage/DemoStage.h"
#include "../collision/CollisionService.h"
#include "../debug_mode/DebugMode.h"
#include "../camera/MainCamera.h"

class DemoScene : public BaseScene
{
private:
	const static int STAGE_NUMBER_i = 1;
	
	Hero hero;
	EnemyTest1 enemy_test1;

	MainCamera main_camera;
	int current_stage_id = 0;

	const static int STAGE_ID_DEMO = 1;
	DemoStage demo_stage;
	void ProcessStage();
	void initLoopDemoScene();

	void checkCharacterAndMapForLeftRight();
	void checkCharacterAndMapForTopBottom();
	void checkCameraAndMapForLeftRight();
	void checkCameraAndMapForTopBottom();


	std::string BGM_STAGE_TEST1 = "./resource/sound/bgm/test_sample_bgm1.mp3";


	void DrawCharacter(IDraw&);
public:
	DemoScene();
	DemoScene(int);
	virtual void Play();

};
