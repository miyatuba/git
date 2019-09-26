#include "BattleScene.h"

BattleScene::BattleScene()
{
	const Rect rect_test(20, 20, 200, 100);
	this->test = rect_test;
}

void BattleScene::Initialize() 
{
	
}

void BattleScene::Finalize()
{

}

void BattleScene::Update()
{
	if (MouseL.down()) {
		this->SetNextSceneId(eSceneId::e_scene_field_id);//テスト段階なのでとりあえずプロパティに保存せずにセット
	}
	this->Draw();
}

void BattleScene::Draw()
{
	this->test.draw(Palette::Red);
}