#pragma once
#include "BaseStage.h"
#include <string>
#include "DxLib.h"


class DemoStage : public BaseStage
{
public:
	const static int X_SQUARES_NUMBER = 20;
	const static int Y_SQUARES_NUMBER = 15;
private:
	const static int DIVIDED_MAP_TIP_X_NUMBER = 3;
	const static int DIVIDED_MAP_TIP_Y_NUMBER = 3;

	std::string MAP_TIP_IMAGE_PATH = "./resource/image/test_block.png";
	const static int DIVIDED_MAP_TIP_TOTAL_NUMBER = 9;

	/*
	0:‰½‚à‚È‚µ
	1:•Ç
	*/
	int map[DemoStage::Y_SQUARES_NUMBER][DemoStage::X_SQUARES_NUMBER] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1 },
		{ 1,0,0,1,1,0,0,1,1,0,0,0,0,0,1,0,0,0,0,1 },
		{ 1,1,1,0,1,0,1,1,1,0,1,1,1,0,0,0,0,1,1,1 },
		{ 1,1,1,0,1,0,1,1,1,0,1,1,1,0,0,0,0,1,1,1 },
		{ 1,1,1,0,0,0,1,1,1,0,1,1,1,0,0,0,0,1,1,1 },
		{ 1,1,1,0,0,0,1,1,1,0,1,1,1,1,0,0,0,1,1,1 },
		{ 1,1,1,0,0,0,1,1,1,0,1,1,1,0,0,0,0,1,1,1 },
		{ 1,1,1,0,0,0,1,1,1,0,1,1,1,0,1,0,0,1,1,1 },
		{ 1,1,1,0,0,0,0,1,1,0,1,1,1,0,1,0,0,1,1,1 },
		{ 1,0,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,1,1,1 },
		{ 1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	};
	
	//“–‚½‚è”»’è‚Ì—L–³‚Ì‰½‚©‚ª•K—v


	int map_tip_list[DemoStage::DIVIDED_MAP_TIP_X_NUMBER * DemoStage::DIVIDED_MAP_TIP_Y_NUMBER];

public:
	DemoStage();
	MapTip getMapTip(int, int);
};