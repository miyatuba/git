#pragma once
#include "DxLib.h"
#include <string>
#include "../../view/IDraw.h"
#include "../../collision/RectCollision.h" 

class BaseEnemy : virtual public IDraw
{
private:
	virtual int getPositionX() const;
	virtual int getPositionY() const;
	virtual int getImageHandle();
	virtual bool isDirectionRight() const;
	virtual bool isDirectionLeft() const;

protected:
	RectCollision rect_collision;
	int x;
	int y;
public:
};