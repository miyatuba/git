#include "BaseEnemy.h"

int BaseEnemy::getPositionX()
{
	return this->x;
}
int BaseEnemy::getPositionY()
{
	return this->y;
}
int BaseEnemy::getImageHandle()
{
	std::string error_message = "BaseEnemy‚ÌgetImageHandlle‚ªŒÄ‚Î‚ê‚½";
	throw error_message;
	return 1;
}
bool BaseEnemy::isDirectionRight()
{
	return this->direction == BaseEnemy::DIRECTION_RIGHT;
}

bool BaseEnemy::isDirectionLeft()
{
	return this->direction == BaseEnemy::DIRECTION_LEFT;
}

void BaseEnemy::AoutAction()
{
	std::string error_message = "BaseEnemy‚ÌAoutAction‚ªŒÄ‚Î‚ê‚½";
	throw error_message;
}

RectCollision BaseEnemy::getCollision()
{
	return this->rect_collision;
}

void BaseEnemy::changeDirectionLeft()
{
	this->direction = BaseEnemy::DIRECTION_LEFT;
}

void BaseEnemy::changeDirectionRight()
{
	this->direction = BaseEnemy::DIRECTION_RIGHT;
}