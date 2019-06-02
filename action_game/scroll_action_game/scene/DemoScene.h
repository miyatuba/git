#pragma once
#include <string.h>
#include "BaseScene.h"
#include "../entity/character/Hero.h"
#include "../entity/stage/DemoStage.h"
#include "../collision/CollisionService.h"
#include "../debug_mode/DebugMode.h"

class DemoScene : public BaseScene
{
private:
	// 
	const static int STAGE_NUMBER_i = 1;
	Hero hero;
	
	int current_stage_id = 0;

	const static int STAGE_ID_DEMO = 1;
	DemoStage demo_stage;
	void ProcessStage();
	void checkCollisionByHeroAndMapTip(Hero&, MapTip);
	void initLoopDemoScene();

	bool is_checked_scaffold_for_hero = false;

public:
	DemoScene();
	DemoScene(int);
	virtual void Play();

};
