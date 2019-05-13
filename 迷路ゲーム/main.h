#ifndef __MAIN_H__
#define __MAIN_H__

#include <DxLib.h>
#include "gamemain.h"
#include "loading.h"

//グローバル変数
//時間計測用変数
extern int g_lasttime; //直前の計測時間
extern float g_frametime; //1ループにかかる時間
extern int g_timerstart; //タイマー用変数

enum GameState{	//ゲーム状態
	GAME_TITLE, GAME_MAIN, 
	GAME_CLEAR, GAME_OVER
};


extern GameState g_gamestate;
extern int g_gametitleimg;	//タイトル画像
extern int g_heroimg; //画像
extern float g_hx, g_hy;//座標

//ボタン
extern BOOL g_akey_prev; //直前Aボタン
//フォント
extern int g_middlefont; //中サイズフォント
extern int g_largefont; //大サイズフォント
extern int g_small; //小サイズフォント

//関数プロト
void DrawGameTitle();
void DrawGameMain();
void DrawGameClear();
void DrawGameOver();
BOOL IsAKeyTrigger(int key);

#endif