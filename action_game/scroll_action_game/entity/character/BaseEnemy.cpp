#include "BaseEnemy.h"

int BaseEnemy::getPositionX() const
{
	return 1;
}
int BaseEnemy::getPositionY() const
{
	return 1;
}
int BaseEnemy::getImageHandle()
{
	std::string error_message = "BaseEnemy��getImageHandlle���Ă΂ꂽ";
	throw error_message;
	return 1;
}
bool BaseEnemy::isDirectionRight() const
{
	return true;
}
bool BaseEnemy::isDirectionLeft() const
{
	return true;
}
