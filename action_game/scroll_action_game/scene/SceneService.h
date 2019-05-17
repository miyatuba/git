#pragma once
#include "DemoScene.h"

class SceneService
{
private:
	//sceneの種別タイプ
	static const int SCENE_TYPE_DEMO = 1;
	
	int current_scene_type_id;

	DemoScene demo_scene;//ざっと調べてみたけど、C++に1つの変数に色んな型を入れることが不可能なために、後でidで現在のシーンを制御する仕組みを作る
public:
	SceneService();
	void Play();

	bool isGameEnd();
};
