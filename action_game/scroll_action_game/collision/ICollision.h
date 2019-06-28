#pragma once
#include "BaseCollision.h"
//これ、機能してない‥
class ICollision 
{
private:
public:
	virtual int getPositionX() const = 0;
	virtual int getPositionY() const = 0;
	//virtual BaseCollision getCollision() const = 0;//これを継承したものを返すつもりだが、BaseCollisionにキャストされそうな予感
};