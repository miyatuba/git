#include "BaseEnemy.h"

int BaseEnemy::getPositionX()
{
	return this->x;
}
int BaseEnemy::getPositionY()
{
	return this->y;
}
/*int BaseEnemy::getImageHandle()
{
	std::string error_message = "BaseEnemyのgetImageHandlleが呼ばれた";
	throw error_message;
	return 1;
}*/
bool BaseEnemy::isDirectionRight()
{
	return true;
}
bool BaseEnemy::isDirectionLeft()
{
	return true;
}

void BaseEnemy::AoutAction()
{
	std::string error_message = "BaseEnemyのAoutActionが呼ばれた";
	throw error_message;
}
