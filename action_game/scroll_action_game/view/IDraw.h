#pragma once
#include <string>

class IDraw 
{
private:
public:
	virtual int getPositionX() const = 0;
	virtual int getPositionY() const = 0;
	virtual std::string getImagePath() const = 0;
};