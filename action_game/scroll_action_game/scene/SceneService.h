#pragma once
#include "DemoScene.h"

class SceneService
{
private:
	BaseScene current_scene;//恐らくここはスーパークラスに直さないといけない
public:
	SceneService();
	void Play();

	bool isGameEnd();
};
