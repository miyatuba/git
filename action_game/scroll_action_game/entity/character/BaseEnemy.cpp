#include "BaseEnemy.h"

int BaseEnemy::getPositionX()
{
	return 1;
}
int BaseEnemy::getPositionY()
{
	return 1;
}
int BaseEnemy::getImageHandle()
{
	std::string error_message = "BaseEnemyのgetImageHandlleが呼ばれた";
	throw error_message;
	return 1;
}
bool BaseEnemy::isDirectionRight()
{
	return true;
}
bool BaseEnemy::isDirectionLeft()
{
	return true;
}
