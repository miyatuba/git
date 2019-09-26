#include "MenuScene.h"

MenuScene::MenuScene()
{
	Rect rect(20, 20, 200, 100);
	this->test = rect;
}

void MenuScene::Initialize()
{

}

void MenuScene::Finalize()
{

}

void MenuScene::Update()
{
	if (MouseL.down()) {
		this->SetNextSceneId(eSceneId::e_scene_shop_id);//テスト段階なのでとりあえずプロパティに保存せずにセット
	}

	this->Draw();
}

void MenuScene::Draw()
{
	this->test.draw(Palette::Purple);
}