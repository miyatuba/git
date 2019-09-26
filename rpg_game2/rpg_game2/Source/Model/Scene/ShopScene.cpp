#include "ShopScene.h"

ShopScene::ShopScene()
{
	Rect rect(20, 20, 200, 100);
	this->test = rect;
}

void ShopScene::Initialize()
{

}

void ShopScene::Finalize()
{

}

void ShopScene::Update()
{
	if (MouseL.down()) {
		this->SetNextSceneId(eSceneId::e_scene_battle_id);//テスト段階なのでとりあえずプロパティに保存せずにセット
	}
	this->Draw();
}

void ShopScene::Draw()
{
	this->test.draw(Palette::Green);
}
