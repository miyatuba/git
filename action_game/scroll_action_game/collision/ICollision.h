#pragma once
#include "BaseCollision.h"
//����A�@�\���ĂȂ��d
class ICollision 
{
private:
public:
	virtual int getPositionX() const = 0;
	virtual int getPositionY() const = 0;
	//virtual BaseCollision getCollision() const = 0;//������p���������̂�Ԃ����肾���ABaseCollision�ɃL���X�g���ꂻ���ȗ\��
};