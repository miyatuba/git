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
		this->SetNextSceneId(eSceneId::e_scene_field_id);//�e�X�g�i�K�Ȃ̂łƂ肠�����v���p�e�B�ɕۑ������ɃZ�b�g
	}
	this->Draw();
}

void BattleScene::Draw()
{
	this->test.draw(Palette::Red);
}