#ifndef __GAMEMAIN_H__
#define __GAMEMAIN_H__

#include <DxLib.h>
#include "main.h"

#define IMG_CHIPSIZE 50
#define MAP_WIDTH 16
#define MAP_HEIGHT 12
#define MOVERATE 13
#define MAXENEMY 20
#define FIREEXPAND 3
#define FIRESHRINK 6
#define FIRESTOP 12
#define MAXSTAGE 2


extern int g_mapdate[MAP_HEIGHT][MAP_WIDTH];

enum MapItem{
	MPITEM_NO, MPITEM_ROCK, MPITEM_HMONSTER, MPITEM_VMONSTER, MPITEM_DRAGON,
	MPITEM_HEROPOS =7, MPITEM_KEY, MPITEM_GOAL
};

enum MonsterType{
	MT_HOLI = 2, MT_VERT, MT_DRAGON, MT_FIRE
};
struct CharaData{
	int x, y;
	BOOL living;
	MonsterType type;
	int direction;
	int fireidx;
	int firetimer;
};

struct StageData{
	int herox, heroy;
	int movecounter;
	CharaData enemies[MAXENEMY];
	BOOL getkey;
	int stagenum;
};

extern StageData g_stagedata;

void GameMain();
void DrawMap();
void InitStage(); 
void DrawEnemy();
void DrawDragonFire(int idx);


#endif