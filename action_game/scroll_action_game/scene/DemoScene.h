#pragma once
#include "BaseScene.h"


#include "../entity/character/Hero.h"

class DemoScene : public BaseScene
{
private:
	Hero hero;
public:
	DemoScene();
	virtual void Play();
};
