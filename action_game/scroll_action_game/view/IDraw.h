#pragma once
#include <string>

class IDraw 
{
private:
public:
	virtual int getPositionX() const = 0;
	virtual int getPositionY() const = 0;
	virtual int getImageHandle() = 0;
	virtual bool isDirectionRight() const = 0;
	virtual bool isDirectionLeft() const = 0;
};