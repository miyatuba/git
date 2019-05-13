#include "gamemain.h"

char g_mapdata[MAP_HEIGHT][MAP_WIDTH + 1];
StageData g_stagedata;


//�X�e�[�W������
void InitStage(){
	char buf[256];
	sprintf_s(buf, 256, "media\\stage%d.txt", g_stagedata.stagenum + 1);
	int fh = FileRead_open(buf);
	for (int y = 0; y < MAP_HEIGHT; y++){
		FileRead_gets(g_mapdata[y], 256, fh);
	}
	FileRead_close(fh);
	g_stagedata.mapwidth = (int)strlen(g_mapdata[0]);

	g_stagedata.hero.x = 2 * IMG_CHIPSIZE;
	g_stagedata.hero.y = 10 * IMG_CHIPSIZE;
	g_stagedata.hero.turn = FALSE;

	ZeroMemory(g_stagedata.enemies, sizeof(g_stagedata.enemies));
	ZeroMemory(g_stagedata.knives, sizeof(g_stagedata.knives));
	g_stagedata.scrollx = 0;
}


void GameMain(){
	//�A�j���[�V�����J�E���^
	g_stagedata.animcounter++;
	g_stagedata.animcounter &= MAXINT;
	int ac = g_stagedata.animcounter / ANIM_RATE;

	DrawMap();
	DrawHero(ac);
	DrawEnemy(ac);

	//�Q�[���N���A����
	if (g_stagedata.hero.x >= (g_stagedata.mapwidth - 1) * IMG_CHIPSIZE){
		g_gamestate = GAME_CLEAR;
		g_timerstart = g_lasttime;	//�^�C�}�[�Z�b�g
	}
}

void DrawHero(int ac){
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	DrawKnife(key);
	float mv = 200.0f * g_frametime; //�ړ��ʌv�Z
	float hx = g_stagedata.hero.x;
	float hy = g_stagedata.hero.y;

	//�W�����v����
	if (g_stagedata.hero.jumping == TRUE){
		//	mv = 0;	//�W�����v���͎��͂ňړ������Ȃ�
		g_stagedata.hero.jumppower -= GRAVITY;

		if (key & PAD_INPUT_LEFT)	{
		hx -= mv;
		g_stagedata.hero.turn = TRUE;
		}
		if (key & PAD_INPUT_RIGHT)	{
		hx += mv;
		g_stagedata.hero.turn = FALSE;
		}//�W�����v���̕����]��

		hy -= (g_stagedata.hero.jumppower * g_frametime);
		hx += (g_stagedata.hero.jumpforward * g_frametime);

	}
	else{
		if (key & PAD_INPUT_LEFT)	{
			hx -= mv;
			g_stagedata.hero.turn = TRUE;
		}
		if (key & PAD_INPUT_RIGHT)	{
			hx += mv;
			g_stagedata.hero.turn = FALSE;
		}
	}
	//�}�b�v�����蔻��
	AtariInfo atari = CheckBlock(hx, hy, g_stagedata.hero.x);
	if (g_stagedata.hero.turn == FALSE){
		if (atari.DR == TRUE || atari.UR == TRUE){
			hx = g_stagedata.hero.x;
		}
	}
	else {
		if (atari.DL == TRUE || atari.UL == TRUE){
			hx = g_stagedata.hero.x;
		}
	}
	//�ڒn�`�F�b�N
	if (atari.GL == TRUE || atari.GR == TRUE) {
		g_stagedata.hero.noground = FALSE;
		g_stagedata.hero.jumping = FALSE;
		g_stagedata.hero.jumppower = 0;
		g_stagedata.hero.jumpforward = 0;
		//�W�����v��ɒn�ʂɖ��܂�Ȃ��悤�␳
		hy = (float)((int)(hy / IMG_CHIPSIZE) * IMG_CHIPSIZE);
	}
	else {
		g_stagedata.hero.noground = TRUE;
		//�d�͂ŗ���
		g_stagedata.hero.jumping = TRUE;
	}
	//�V��`�F�b�N
	if (g_stagedata.hero.jumping == TRUE){
		if (atari.UL == TRUE || atari.UR == TRUE){
			g_stagedata.hero.jumppower = 0;
			g_stagedata.hero.jumpforward = 0;
		}
	}
	//�W�����v��������2
	if (g_stagedata.hero.jumping == FALSE){
		if (IsAKeyTrigger(key) == TRUE && g_stagedata.hero.noground == FALSE)
		{
			g_stagedata.hero.jumping = TRUE;
			g_stagedata.hero.jumppower = JUMP_POWER;
			if (key & PAD_INPUT_LEFT)	{
				g_stagedata.hero.jumpforward = -JUMP_FORWARD;
			}
			if (key & PAD_INPUT_RIGHT)	{
				g_stagedata.hero.jumpforward = JUMP_FORWARD;
			}
		}
	}

	//�X�N���[���␳
	if (hx - g_stagedata.scrollx > SCROLL_STAPOS){
		g_stagedata.scrollx += (hx - g_stagedata.hero.x);
	}
	if (hx < g_stagedata.scrollx) hx = g_stagedata.hero.x;
	g_stagedata.hero.x = hx;
	g_stagedata.hero.y = hy;


	DrawRotaGraph2((int)(g_stagedata.hero.x - g_stagedata.scrollx), 
		(int)g_stagedata.hero.y, 0, 0, 1, 0,
		g_imghandles.hero[ac % ANIMFRAME], TRUE, g_stagedata.hero.turn);
}

//�u���b�N�Ƃ̓����蔻��
BOOL _CheckBlockSub(float x, float y){
	int mx = (int)(x / IMG_CHIPSIZE);
	int my = (int)(y / IMG_CHIPSIZE);
	//�}�b�v�͈̔͊O�Ȃ�FALSE
	if ((mx < 0) || (mx >= g_stagedata.mapwidth) || (my >= MAP_HEIGHT) || (my < 0)){
		return FALSE;
	}
	if (g_mapdata[my][mx] != '0') return TRUE;
	return FALSE;
}
AtariInfo CheckBlock(float x, float y, float rx){
	AtariInfo result;
	result.UL = _CheckBlockSub(x, y);
	result.UR = _CheckBlockSub(x + IMG_CHIPSIZE - 1, y);
	result.DL = _CheckBlockSub(x, y + IMG_CHIPSIZE -1);
	result.DR = _CheckBlockSub(x + IMG_CHIPSIZE - 1, y + IMG_CHIPSIZE -1);
	result.GL = _CheckBlockSub(rx, y + IMG_CHIPSIZE);
	result.GR = _CheckBlockSub(rx + IMG_CHIPSIZE - 1, y + IMG_CHIPSIZE);
	return result;
}


void DrawMap(){
	int sc = (int)(g_stagedata.scrollx / IMG_CHIPSIZE);
	int shiftx = (int)g_stagedata.scrollx % IMG_CHIPSIZE;
	for (int y = 0; y < MAP_HEIGHT; y++){
		for (int x = 0; x < SCR_WIDTH + 1; x++){
			if (x + sc >= g_stagedata.mapwidth) break;
			if (g_mapdata[y][x + sc] == '1'){
				DrawGraph(x * IMG_CHIPSIZE - shiftx, y * IMG_CHIPSIZE, 
					g_imghandles.block, TRUE);
			}
			//�����X�^�[���o
			if (g_mapdata[y][x + sc] > '1') SetEnemy(x + sc, y);
		}
	}
}




void DrawKnife(int key){
	//���ˏ���
	if (IsBKeyTrigger(key) == TRUE && g_stagedata.hero.turn == FALSE){
		//�󂫂�T��
		int i;
		for (i = 0; i < MAX_KNIFE; i++){
			if (g_stagedata.knives[i].living == FALSE) break;
		}
		if (i < MAX_KNIFE){
			g_stagedata.knives[i].living = TRUE;
			g_stagedata.knives[i].x = g_stagedata.hero.x + IMG_CHIPSIZE;
			g_stagedata.knives[i].y = g_stagedata.hero.y;
		}
	}
	//�i�C�t�̕`��ƈړ�
	/*if (g_stagedata.hero.turn)*/
	float mv = 350.0f * g_frametime; //�ړ��ʌv�Z
	for (int i = 0; i < MAX_KNIFE; i++){
		if (g_stagedata.knives[i].living == FALSE) continue;
		g_stagedata.knives[i].x += mv;
		//�}�b�v�����蔻��
		AtariInfo atari = CheckBlock(g_stagedata.knives[i].x, g_stagedata.knives[i].y,
			g_stagedata.knives[i].x);
		if (atari.DR == TRUE || atari.UR == TRUE) g_stagedata.knives[i].living = FALSE;
		//��ʊO�ɏo�Ă�����
		if (g_stagedata.knives[i].x > g_stagedata.scrollx + 1000){
			g_stagedata.knives[i].living = FALSE;
		}

		DrawGraph((int)(g_stagedata.knives[i].x - g_stagedata.scrollx),
			(int)g_stagedata.knives[i].y,
			g_imghandles.knife, TRUE);
	}
}


//�L�[�g���K�[����
BOOL IsBKeyTrigger(int key){
	if (key & PAD_INPUT_B){
		if (g_stagedata.g_bkey_prev == FALSE){
			g_stagedata.g_bkey_prev = TRUE;
			return TRUE;
		}
	}
	else {
		g_stagedata.g_bkey_prev = FALSE;
	}
	return FALSE;
}