#ifndef __GAMEMAIN_H__ 
#define __GAMEMAIN_H__

#include <DxLib.h>
#include "main.h"
#include "enemy.h"

#define IMG_CHIPSIZE 50
#define MAP_WIDTH 511
#define MAP_HEIGHT 12
#define MAXSTAGE 1
#define SCR_WIDTH 16
#define ANIM_RATE 4
#define SCROLL_STAPOS 500
#define JUMP_POWER 750.0f
#define GRAVITY 30.0f
#define JUMP_FORWARD 200.0f
#define MAX_ENEMY 25
#define MAX_KNIFE 6

extern char g_mapdata[MAP_HEIGHT][MAP_WIDTH+1];

enum EnemyType{
	ET_CRAB = 2,
	ET_OCT = 3,
	ET_BULLET = 4
};

struct CharaData{
	float x, y;
	BOOL turn;
	BOOL noground;
	BOOL jumping;
	float jumppower, jumpforward;
	BOOL living;
	EnemyType type;
	int life;
};

struct StageData{
	int stagenum;
	int mapwidth;
	int animcounter;
	CharaData hero;
	float scrollx;
	CharaData enemies[MAX_ENEMY];
	CharaData knives[MAX_KNIFE];
	BOOL g_bkey_prev;
};
extern StageData g_stagedata;

struct AtariInfo{
	BOOL UL, UR, DL, DR, GL, GR;
};

void GameMain();
void InitStage();
void DrawHero(int ac);
void DrawMap();
AtariInfo CheckBlock(float x, float y, float rx);
void DrawKnife(int key);
BOOL IsBKeyTrigger(int key);

#endif