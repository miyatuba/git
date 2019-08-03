#pragma once
#include "BaseEnemy.h"


class EnemyTest1: public BaseEnemy 
{
private:
	int stand_image_handle;
	std::string IMAGE_PATH = "./resource/image/enemy/test1.jpg";

	const static int X_SIZE = 64;
	const static int Y_SIZE = 64;

	// base�ɋL�q���邩���������ǁB�e�����X�^�[���ňႤ���ƍl�����̂ŁA�ʂɋL�q���Ă݂�
	bool is_fall = true;
	bool is_checked_scaffold = false;

public:
	EnemyTest1();
	int getImageHandle();
	void AoutAction();
	void MoveLeft(int);
	void MoveRight(int);
	void MoveDown(int);
	void MoveUp(int);
	bool isFall();

	void OnFallStatus();
	void OffFallStatus();
	void checkHeroAndMapForLeftRight(MapTip map_tip);
	void checkHeroAndMapForTopBottom(MapTip map_tip);

	void initForLoop();

};