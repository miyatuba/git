#ifndef __LOADING_H__
#define __LOADING_H__

#include <DxLib.h>

#define ANIMFRAME 2

struct ImageHandles{
	int hero[ANIMFRAME];
	int monster[2][ANIMFRAME];
	int block, knife, bullet;
	int title;
};
extern ImageHandles g_imghandles;

BOOL LoadGameImage();

#endif