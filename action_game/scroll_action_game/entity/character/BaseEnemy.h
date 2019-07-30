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
	

	bool direction; //�����X�^�[�ɂ���Č��������ł͂Ȃ������Ȃ̂ŁA�������Őݒ肷�邱��
	
public:
	virtual void AoutAction();
	virtual bool isDirectionRight();
	virtual bool isDirectionLeft();
	RectCollision getCollision();

	void changeDirectionLeft();
	void changeDirectionRight();
	
};