#ifndef __LOSDING_H__
#define __LOSDING_H__

#include <DxLib.h>

struct ImageHandles{
	int field;			//�w�i�̑�
	int mapitems[10];	//�}�b�v��̃A�C�e��
};
extern ImageHandles g_imghandles;

struct SoundHandles{
	int fire;
	int bgm;
	int gameover;
	int walk;
};

extern SoundHandles g_sndhandles;

BOOL LoadGameImage();

#endif;