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
		this->SetNextSceneId(eSceneId::e_scene_shop_id);//�e�X�g�i�K�Ȃ̂łƂ肠�����v���p�e�B�ɕۑ������ɃZ�b�g
	}

	this->Draw();
}

void MenuScene::Draw()
{
	this->test.draw(Palette::Purple);
}