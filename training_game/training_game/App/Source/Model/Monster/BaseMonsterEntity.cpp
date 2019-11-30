#include "BaseMonsterEntity.h"

BaseMonsterEntity::BaseMonsterEntity()
{
	
}

void BaseMonsterEntity::setBattleWaitImages(std::vector<std::string> wait_battle_image_vector)
{
	//String test = Unicode::Widen(wait_battle_image_vector[1]);
	for (int i = 0; wait_battle_image_vector.size() > i; i++) {
		this->battle_wait_image_vector.push_back(Texture(Resource(Unicode::Widen(wait_battle_image_vector[i]))));
	}
}

Texture BaseMonsterEntity::getBattleWaitImage(int motion_number)
{
	return this->battle_wait_image_vector[motion_number];
}