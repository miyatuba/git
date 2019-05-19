#pragma once
#include <vector>
#include <string>

class BaseStage
{
private:
protected:


public:
	const static int DIVIDED_MAP_TIP_X_SIZE = 80;
	const static int DIVIDED_MAP_TIP_Y_SIZE = 80;
	virtual int getMapTopHandol(int x, int y);
};