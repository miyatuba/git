#include "FieldScene.h"

FieldScene::FieldScene()
{
	const Rect rect_test(20, 20, 200, 100);
	this->test = rect_test;
}

void FieldScene::Initialize()
{

}

void FieldScene::Finalize()
{

}

void FieldScene::Update()
{
	if (MouseL.down()) {
		this->SetNextSceneId(eSceneId::e_scene_index_id);//テスト段階なのでとりあえずプロパティに保存せずにセット
	}
	this->Draw();
}

void FieldScene::Draw()
{
	this->test.draw(Palette::Yellow);
}