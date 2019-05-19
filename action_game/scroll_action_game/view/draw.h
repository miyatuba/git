#pragma once
#include "DxLib.h"

#include <string>
#include "IDraw.h"
#include "../entity/stage/BaseStage.h"


class Draw
{
private:
public:
	void DrawGame(const IDraw&);
	void StageDraw(BaseStage&, int, int);
	void CallScreenFlip();
	void CallClearDrawScreen();
};

