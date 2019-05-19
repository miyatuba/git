#pragma once

#include "BaseScene.h"
#include "../entity/character/Hero.h"
#include "../entity/stage/DemoStage.h"

class DemoScene : public BaseScene
{
private:
	// 
	const static int STAGE_NUMBER_i = 1;
	Hero hero;
	
	int current_stage_id;

	const static int STAGE_ID_DEMO = 1;
	DemoStage demo_stage;

public:
	DemoScene();
	DemoScene(int);
	virtual void Play();
	void DrawStage();
};
