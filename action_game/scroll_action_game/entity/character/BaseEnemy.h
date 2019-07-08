#pragma once
#include "DxLib.h"
#include <string>
#include "../../view/IDraw.h"
#include "../../collision/RectCollision.h" 

class BaseEnemy : virtual public IDraw
{
private:

protected:
	RectCollision rect_collision;
	int x;
	int y;

	virtual int getPositionX();
	virtual int getPositionY();
	virtual int getImageHandle();
	virtual bool isDirectionRight();
	virtual bool isDirectionLeft();
public:
};