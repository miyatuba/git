#pragma once
#include "DxLib.h"
#include <string>
#include "../../view/IDraw.h"
#include "../../collision/RectCollision.h" 

class BaseEnemy : virtual public IDraw
{
private:

	

protected:
	const static bool DIRECTION_LEFT = false;
	const static bool DIRECTION_RIGHT = true;

	RectCollision rect_collision;
	int x;
	int y;

	virtual int getPositionX();
	virtual int getPositionY();
	//virtual int getImageHandle();
	

	bool direction; //モンスターによって向きが一定ではないかもなので、初期化で設定すること
	
public:
	virtual void AoutAction();
	virtual bool isDirectionRight();
	virtual bool isDirectionLeft();
	RectCollision getCollision();

	void changeDirectionLeft();
	void changeDirectionRight();
	
};