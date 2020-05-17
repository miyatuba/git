#pragma once
#include "StageScene.h"

class SceneService
{
private:
	//sceneの種別タイプ
	static const int SCENE_TYPE_STAGE = 1;//ゲーム本編
	//恐らく、タイトル、ボスバトル（stageと分けるべきか微妙）、ステージセレクト、コンフィグ（これは別のプログラムで起動して設定するでもいいかも

	int current_scene_type_id;

	StageScene demo_scene;//ざっと調べてみたけど、C++に1つの変数に色んな型を入れることが不可能なために、後でidで現在のシーンを制御する仕組みを作る
	//→型をポインタで扱えば行けるっぽい、https://qiita.com/ydyd0320/items/7aacaeec6396f46d2289　https://dixq.net/g/sp_06.html

	BaseScene* p_current_scene;
public:
	SceneService();
	void Play();

	bool isGameEnd();
};
