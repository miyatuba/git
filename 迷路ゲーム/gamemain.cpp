#include "gamemain.h"

int g_mapdata[MAP_HEIGHT][MAP_WIDTH] = {
//0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, //0
{ 1, 7, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 4 }, //1
{ 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 9 }, //2
{ 1, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1 }, //3
{ 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 3, 1, 0, 0, 0, 1 }, //4
{ 1, 0, 1, 0, 0, 1, 0, 8, 1, 0, 0, 1, 0, 1, 0, 1 }, //5
{ 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1 }, //6
{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 }, //7
{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 }, //8
{ 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1 }, //9
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1 }, //10
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }  //11
};

StageData g_stagedata; //ゲーム本編のデータ

//ステージ初期化
void InitStage(){
	ZeroMemory(g_stagedata.enemies, sizeof(g_stagedata.enemies));
	char buf[256];
	sprintf_s(buf, 256, "media\\stage%d.txt", g_stagedata.stagenum + 1);
	int fh = FileRead_open(buf);
	for (int y = 0; y < MAP_HEIGHT; y++){
		FileRead_gets(buf, 256, fh);
		for (int x = 0; x < MAP_WIDTH; x++){
			g_mapdata[y][x] = (int)(buf[x] - '0');
		}
	}
			FileRead_close(fh);
	 
	int enemy = 0;
	for (int y = 0; y < MAP_HEIGHT; y++){
		for (int x = 0; x < MAP_WIDTH; x++){
			int c = g_mapdata[y][x];
			switch(c){
				case MPITEM_HEROPOS:
				g_stagedata.herox = x;
				g_stagedata.heroy = y;
				g_mapdata[y][x] = 0;
				break;
				case MPITEM_HMONSTER:
				case MPITEM_VMONSTER:
				case MPITEM_DRAGON:
					g_stagedata.enemies[enemy].x = x;
					g_stagedata.enemies[enemy].y = y;
					g_stagedata.enemies[enemy].type = (MonsterType)c;					
					g_stagedata.enemies[enemy].living = TRUE;
					g_stagedata.enemies[enemy].direction = -1;
					g_mapdata[y][x] = 0;
					enemy++;
					break;
				default:
					break;
			}
		}
	
	}
	//ドラゴンの炎の予 約
	for (int i = 0; i < MAXENEMY; i++){
		//ドラゴンを探す
		if (g_stagedata.enemies[i].type == MT_DRAGON){
			g_stagedata.enemies[i].fireidx = enemy;
			g_stagedata.enemies[i].firetimer = 0;
			enemy += FIREEXPAND;
		}
	}
}

void GameMain(){
	//移動制限
	g_stagedata.movecounter++;
	g_stagedata.movecounter %= MOVERATE;

	DrawMap();
	DrawEnemy();
	//自キャラ移動
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (g_stagedata.movecounter == 0){
		/*float mv = 80.0f* g_frametime; //移動量*/
		int hx = g_stagedata.herox;
		int hy = g_stagedata.heroy;
		if (key & PAD_INPUT_UP)		hy -= 1;

		if (key & PAD_INPUT_DOWN)	hy += 1;
		
		if (key & PAD_INPUT_LEFT)	hx -= 1;
		
		if (key & PAD_INPUT_RIGHT)	hx += 1;
		
		//障害物
		if (g_mapdata[hy][hx] == MPITEM_NO){
			g_stagedata.herox = hx;
			g_stagedata.heroy = hy;
		}
		
		//鍵チェック
		if (g_mapdata[hy][hx] == MPITEM_KEY){
			g_mapdata[hy][hx] = MPITEM_NO;
			g_stagedata.getkey = TRUE;
			g_stagedata.herox = hx;
			g_stagedata.heroy = hy;
		}
		
		//ゴールチェック
		if (g_mapdata[hy][hx] == MPITEM_GOAL){
			if (g_stagedata.getkey == TRUE){
				g_gamestate = GAME_CLEAR;
				g_timerstart = g_lasttime; //タイマーセット
			}
		}
	}
	DrawGraph(g_stagedata.herox * IMG_CHIPSIZE,
			g_stagedata.heroy * IMG_CHIPSIZE,
			g_imghandles.mapitems[MPITEM_HEROPOS], TRUE);
	
	//Zキーチェック、画面切り替え
	if (IsAKeyTrigger(key) == TRUE){
		g_gamestate = GAME_OVER;
		g_timerstart = g_lasttime; //タイマーセット

	}
}

void DrawMap(){
	for (int y = 0; y < MAP_HEIGHT; y++){
		for (int x = 0; x < MAP_WIDTH; x++){
			DrawGraph(x*IMG_CHIPSIZE, y*IMG_CHIPSIZE, g_imghandles.field, FALSE);
			//アップアイテム画面
			int c = g_mapdata[y][x];
			if (c>0){
				DrawGraph(x * IMG_CHIPSIZE, y * IMG_CHIPSIZE,
					g_imghandles.mapitems[c], TRUE);
			}
		}
	}
}

void DrawEnemy(){
	for (int i = 0; i < MAXENEMY; i++){
		if (g_stagedata.enemies[i].living == FALSE) continue;
		MonsterType c = g_stagedata.enemies[i].type;
		if (g_stagedata.movecounter == 0){
			int ex = g_stagedata.enemies[i].x;
			int ey = g_stagedata.enemies[i].y;
			//移動処理
			if (c == MT_HOLI) ex += g_stagedata.enemies[i].direction;
			if (c == MT_VERT) ey += g_stagedata.enemies[i].direction;
			if (c == MT_DRAGON) DrawDragonFire(i);
			if (g_mapdata[ey][ex] == MPITEM_NO){
				g_stagedata.enemies[i].x = ex;
				g_stagedata.enemies[i].y = ey;
			}
			else{
				//方向転換
				g_stagedata.enemies[i].direction *= -1;
			}
			//あたり判定
			if ((g_stagedata.enemies[i].x == g_stagedata.herox) &&
				(g_stagedata.enemies[i].y == g_stagedata.heroy)){
				PlaySoundMem(g_sndhandles.gameover, DX_PLAYTYPE_BACK);
				g_gamestate = GAME_OVER;
				g_timerstart = g_lasttime; //タイマーセット

			}


		}
		DrawGraph(g_stagedata.enemies[i].x * IMG_CHIPSIZE,
			g_stagedata.enemies[i].y * IMG_CHIPSIZE,
			g_imghandles.mapitems[(int)c], TRUE);
	}

}

void DrawDragonFire(int idx){
	int t = g_stagedata.enemies[idx].firetimer;
	int f = g_stagedata.enemies[idx].fireidx;
	if (t < FIREEXPAND){
	//炎を伸ばす
		for (int i = 0; i < FIREEXPAND; i++){
			if (i <= t){
				g_stagedata.enemies[f + i].living = TRUE;
				g_stagedata.enemies[f + i].type = MT_FIRE;
				g_stagedata.enemies[f + i].x = g_stagedata.enemies[idx].x - i - 1;
				g_stagedata.enemies[f + i].y = g_stagedata.enemies[idx].y;
				PlaySoundMem(g_sndhandles.fire, DX_PLAYTYPE_BACK);
			}else{
				g_stagedata.enemies[f + i].living = FALSE;
			}
		}
	}else if (t < FIRESHRINK){
		//炎を縮める
		for (int i = 0; i < FIREEXPAND; i++){
			if (i <= (FIRESHRINK - t - 1)){
				g_stagedata.enemies[f + i].living = TRUE;
				g_stagedata.enemies[f + i].type = MT_FIRE;
				g_stagedata.enemies[f + i].x = g_stagedata.enemies[idx].x - i - 1;
				g_stagedata.enemies[f + i].y = g_stagedata.enemies[idx].y;
				PlaySoundMem(g_sndhandles.fire, DX_PLAYTYPE_BACK);
			}else{
				g_stagedata.enemies[f + i].living = FALSE;
			}
		}
	}else{
		for (int i = 0; i < FIREEXPAND; i++){
			g_stagedata.enemies[f + i].living = FALSE;
		}
	}
	g_stagedata.enemies[idx].firetimer++;
	g_stagedata.enemies[idx].firetimer %= FIRESTOP;
}

