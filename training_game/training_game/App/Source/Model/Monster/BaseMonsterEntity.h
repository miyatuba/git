#pragma once
#include <Siv3D.hpp>
#include <string.h>
#include <initializer_list>

class BaseMonsterEntity
{
private:

protected:
	int grid_position_x;
	int grid_position_y;
	//int 
	std::vector<Texture> battle_wait_image_vector;
public:
	BaseMonsterEntity();
	void setBattleWaitImages(std::vector<std::string> wait_battle_image_vector);
	Texture getBattleWaitImage(int motion_number);
};
