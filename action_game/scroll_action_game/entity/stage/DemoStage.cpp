#include "DemoStage.h"

DemoStage::DemoStage()
{
	LoadDivGraph(
		this->MAP_TIP_IMAGE_PATH.c_str(), 
		DemoStage::DIVIDED_MAP_TIP_X_NUMBER * DemoStage::DIVIDED_MAP_TIP_Y_NUMBER,
		DemoStage::DIVIDED_MAP_TIP_X_NUMBER,
		DemoStage::DIVIDED_MAP_TIP_Y_NUMBER,
		BaseStage::DIVIDED_MAP_TIP_X_SIZE,
		BaseStage::DIVIDED_MAP_TIP_Y_SIZE,
		this->map_tip_list);
}

//–ß‚è’l‚ğMapƒNƒ‰ƒX‚É•Ï‚¦‚é‚×‚«
int DemoStage::getMapTopHandol(int x, int y)
{
	int tip_id = this->map[y][x];
	return this->map_tip_list[tip_id];
}