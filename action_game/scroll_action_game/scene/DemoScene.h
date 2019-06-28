#pragma once
#include <string.h>
#include "BaseScene.h"
#include "../entity/character/Hero.h"
#include "../entity/stage/DemoStage.h"
#include "../collision/CollisionService.h"
#include "../debug_mode/DebugMode.h"
#include "../camera/MainCamera.h"

class DemoScene : public BaseScene
{
private:
	const static int STAGE_NUMBER_i = 1;
	Hero hero;
	MainCamera main_camera;
	int current_stage_id = 0;

	const static int STAGE_ID_DEMO = 1;
	DemoStage demo_stage;
	void ProcessStage();
	void initLoopDemoScene();

	bool is_checked_scaffold_for_hero = false;
	void checkPlayerAndMapForLeftRight();
	void checkPlayerAndMapForTopBottom();
	void checkCameraAndMapForLeftRight();
	void checkCameraAndMapForTopBottom();

	void DrawCharacter(const IDraw&);
public:
	DemoScene();
	DemoScene(int);
	virtual void Play();

};
