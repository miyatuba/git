#pragma once
#include "StageScene.h"

class SceneService
{
private:
	//scene�̎�ʃ^�C�v
	static const int SCENE_TYPE_STAGE = 1;//�Q�[���{��
	//���炭�A�^�C�g���A�{�X�o�g���istage�ƕ�����ׂ��������j�A�X�e�[�W�Z���N�g�A�R���t�B�O�i����͕ʂ̃v���O�����ŋN�����Đݒ肷��ł���������

	int current_scene_type_id;

	StageScene demo_scene;//�����ƒ��ׂĂ݂����ǁAC++��1�̕ϐ��ɐF��Ȍ^�����邱�Ƃ��s�\�Ȃ��߂ɁA���id�Ō��݂̃V�[���𐧌䂷��d�g�݂����
	//���^���|�C���^�ň����΍s������ۂ��Ahttps://qiita.com/ydyd0320/items/7aacaeec6396f46d2289�@https://dixq.net/g/sp_06.html

	BaseScene* p_current_scene;
public:
	SceneService();
	void Play();

	bool isGameEnd();
};
