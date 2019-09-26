#include "IndexScene.h"

IndexScene::IndexScene()
{
	const Rect rect_test(20, 20, 200, 100);
	this->test = rect_test;
}

void IndexScene::Initialize()
{

}

void IndexScene::Finalize()
{

}

void IndexScene::Update()
{
	if (MouseL.down()) {
		this->SetNextSceneId(eSceneId::e_scene_menu_id);//テスト段階なのでとりあえずプロパティに保存せずにセット
	}

	this->Draw();
}

void IndexScene::Draw()
{
	this->test.draw(Palette::Blue);
}