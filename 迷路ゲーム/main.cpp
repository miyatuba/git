#include "main.h"

//グローバル変数
//時間計測用変数
int g_lasttime = 0; //直前の計測時間
float g_frametime = 0; //1ループにかかる時間
int g_timerstart; //タイマー用変数


GameState g_gamestate = GAME_TITLE;
int g_gametitleimg;	//タイトル画像
int g_heroimg; //画像
float g_hx = 0, g_hy = 0;//座標

//ボタン
BOOL g_akey_prev; //直前Aボタン
//フォント
int g_middlefont; //中サイズフォント
int g_largefont; //大サイズフォント

int WINAPI WinMain(HINSTANCE h1, HINSTANCE hp, LPSTR lpC, int nC){
	//ウインドウモードにする
	ChangeWindowMode(TRUE);
	//ウインドウサイズを変更
	SetGraphMode(800, 600, 32);
	//DXライブラリ初期化
	if (DxLib_Init() == -1) return -1;

	//画像読み込み
	if (LoadGameImage() == FALSE) return -1;
	g_gametitleimg = LoadGraph("media\\smp1_title.png");
	g_heroimg = LoadGraph("media\\smp1_chara01.png");
	g_middlefont = CreateFontToHandle("メイリオ", 42, -1, DX_FONTTYPE_ANTIALIASING);
	g_largefont = CreateFontToHandle("メイリオ", 90, -1, DX_FONTTYPE_ANTIALIASING);

	SetDrawScreen(DX_SCREEN_BACK);
	g_lasttime = GetNowCount();
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0){
		//1ループにかかる時間
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

	//待機
	WaitKey();
	//DXライブラリの終了処理
	DxLib_End();
	return 0;
}

//タイトル画面
void DrawGameTitle(){
	DrawBox( 0, 0, 800, 600, GetColor(255, 255, 255), TRUE);
	DrawGraph(0, 0, g_gametitleimg, TRUE);
	//テキスト表示
	DrawStringToHandle(100, 400, "Zキーでゲームスタート",
		GetColor(0, 255, 0),g_middlefont);
	DrawStringToHandle(100, 460, "カーソルキーで上下左右に移動", 
		GetColor(0, 0, 0), g_middlefont);
	//キーチェックして画面を切り替え
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (IsAKeyTrigger(key) == TRUE) {
		g_gamestate = GAME_MAIN;
		InitStage();
		PlaySoundMem(g_sndhandles.bgm, DX_PLAYTYPE_LOOP);
	}
	//
}

//ゲーム本編
void DrawGameMain(){

	

	GameMain();
	/*ScreenFlip();*/


}

//ゲームクリア
void DrawGameClear(){
	DrawBox(0, 0, 800, 600, GetColor(255, 255, 255), TRUE);
	//テキスト表示
	DrawStringToHandle(100, 200, "ゲームクリア", GetColor(80, 128, 255), g_largefont);
	//5秒後戻る
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

//ゲームオーバー
void DrawGameOver(){
	StopSoundMem(g_sndhandles.bgm);
	//テキスト表示
	DrawStringToHandle(100, 200, "ゲームオーバー", GetColor(255, 0, 0), g_largefont);
	//5秒後にタイトル画面へ
	if (g_lasttime - g_timerstart > 5000) g_gamestate = GAME_TITLE;
}

//キートリガーの処理
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