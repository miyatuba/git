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
	std::string error_message = "BaseEnemy��getImageHandlle���Ă΂ꂽ";
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
