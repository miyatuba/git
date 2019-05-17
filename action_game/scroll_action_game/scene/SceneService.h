#pragma once
#include "DemoScene.h"

class SceneService
{
private:
	DemoScene current_scene;//ざっと調べてみたけど、C++に1つの変数に色んな型を入れることが不可能なために、後でidで現在のシーンを制御する仕組みを作る
public:
	SceneService();
	void Play();

	bool isGameEnd();
};
