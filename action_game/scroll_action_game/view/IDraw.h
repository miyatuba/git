#pragma once
#include <string>

class IDraw 
{
private:
public:
	virtual int getPositionX() = 0;
	virtual int getPositionY() = 0;
	virtual int getImageHandle() = 0;
	virtual bool isDirectionRight() = 0;
	virtual bool isDirectionLeft() = 0;
};