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


MapTip DemoStage::getMapTip(int x, int y)
{
	int tip_id = this->map_tip_type_id_list[y][x];

	int map_tip_handle = 0;

	if (tip_id != DemoStage::NO_MAP_TIP) {
		map_tip_handle = this->map_tip_list[tip_id];
	} 

	MapTip map(map_tip_handle, this->map_tip_collision_type_list[tip_id], x, y);
	return map;
}