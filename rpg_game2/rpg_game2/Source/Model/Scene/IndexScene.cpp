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
		this->SetNextSceneId(eSceneId::e_scene_menu_id);//�e�X�g�i�K�Ȃ̂łƂ肠�����v���p�e�B�ɕۑ������ɃZ�b�g
	}

	this->Draw();
}

void IndexScene::Draw()
{
	this->test.draw(Palette::Blue);
}