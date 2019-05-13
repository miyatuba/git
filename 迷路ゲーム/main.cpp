#include "main.h"

//�O���[�o���ϐ�
//���Ԍv���p�ϐ�
int g_lasttime = 0; //���O�̌v������
float g_frametime = 0; //1���[�v�ɂ����鎞��
int g_timerstart; //�^�C�}�[�p�ϐ�


GameState g_gamestate = GAME_TITLE;
int g_gametitleimg;	//�^�C�g���摜
int g_heroimg; //�摜
float g_hx = 0, g_hy = 0;//���W

//�{�^��
BOOL g_akey_prev; //���OA�{�^��
//�t�H���g
int g_middlefont; //���T�C�Y�t�H���g
int g_largefont; //��T�C�Y�t�H���g

int WINAPI WinMain(HINSTANCE h1, HINSTANCE hp, LPSTR lpC, int nC){
	//�E�C���h�E���[�h�ɂ���
	ChangeWindowMode(TRUE);
	//�E�C���h�E�T�C�Y��ύX
	SetGraphMode(800, 600, 32);
	//DX���C�u����������
	if (DxLib_Init() == -1) return -1;

	//�摜�ǂݍ���
	if (LoadGameImage() == FALSE) return -1;
	g_gametitleimg = LoadGraph("media\\smp1_title.png");
	g_heroimg = LoadGraph("media\\smp1_chara01.png");
	g_middlefont = CreateFontToHandle("���C���I", 42, -1, DX_FONTTYPE_ANTIALIASING);
	g_largefont = CreateFontToHandle("���C���I", 90, -1, DX_FONTTYPE_ANTIALIASING);

	SetDrawScreen(DX_SCREEN_BACK);
	g_lasttime = GetNowCount();
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0){
		//1���[�v�ɂ����鎞��
		int curtime = GetNowCount();
		g_frametime = (float)(curtime - g_lasttime) / 1000.0f;
		g_lasttime = curtime;

		ClearDrawScreen();
		switch (g_gamestate)
		{
		case GAME_TITLE:
			DrawGameTitle();
			break;

		case GAME_MAIN:
			DrawGameMain();
			break;

		case GAME_CLEAR:
			DrawGameClear();
			break;

		case GAME_OVER:
			DrawGameOver();
			break;

		default:
			break;

		}
		ScreenFlip();
	}

	//�ҋ@
	WaitKey();
	//DX���C�u�����̏I������
	DxLib_End();
	return 0;
}

//�^�C�g�����
void DrawGameTitle(){
	DrawBox( 0, 0, 800, 600, GetColor(255, 255, 255), TRUE);
	DrawGraph(0, 0, g_gametitleimg, TRUE);
	//�e�L�X�g�\��
	DrawStringToHandle(100, 400, "Z�L�[�ŃQ�[���X�^�[�g",
		GetColor(0, 255, 0),g_middlefont);
	DrawStringToHandle(100, 460, "�J�[�\���L�[�ŏ㉺���E�Ɉړ�", 
		GetColor(0, 0, 0), g_middlefont);
	//�L�[�`�F�b�N���ĉ�ʂ�؂�ւ�
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (IsAKeyTrigger(key) == TRUE) {
		g_gamestate = GAME_MAIN;
		InitStage();
		PlaySoundMem(g_sndhandles.bgm, DX_PLAYTYPE_LOOP);
	}
	//
}

//�Q�[���{��
void DrawGameMain(){

	

	GameMain();
	/*ScreenFlip();*/


}

//�Q�[���N���A
void DrawGameClear(){
	DrawBox(0, 0, 800, 600, GetColor(255, 255, 255), TRUE);
	//�e�L�X�g�\��
	DrawStringToHandle(100, 200, "�Q�[���N���A", GetColor(80, 128, 255), g_largefont);
	//5�b��߂�
	if (g_lasttime - g_timerstart > 5000) {
		g_stagedata.stagenum++;
		g_stagedata.stagenum %= MAXSTAGE;
		if (g_stagedata.stagenum == 0){
			g_gamestate = GAME_TITLE;
		}
		else{
			g_gamestate = GAME_MAIN;
			InitStage();
		}
	}
}

//�Q�[���I�[�o�[
void DrawGameOver(){
	StopSoundMem(g_sndhandles.bgm);
	//�e�L�X�g�\��
	DrawStringToHandle(100, 200, "�Q�[���I�[�o�[", GetColor(255, 0, 0), g_largefont);
	//5�b��Ƀ^�C�g����ʂ�
	if (g_lasttime - g_timerstart > 5000) g_gamestate = GAME_TITLE;
}

//�L�[�g���K�[�̏���
BOOL IsAKeyTrigger(int key){
	if (key & PAD_INPUT_A)
	{
		if (g_akey_prev == FALSE){
			g_akey_prev = TRUE;
			return TRUE;
		}

	}
	else{
		g_akey_prev = FALSE;
	}
	return FALSE;
}