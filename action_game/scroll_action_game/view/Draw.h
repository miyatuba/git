#pragma once
#include "DxLib.h"

#include <string>
#include "IDraw.h"
#include "../entity/stage/BaseStage.h"
#include "../camera/MainCamera.h"


class Draw
{
private:
public:
	void DrawCharacter(const IDraw&, MainCamera);
	void DrawTurnCharacter(const IDraw&, MainCamera);
	void StageDraw(MapTip&, int, int, MainCamera);
	void CallScreenFlip();
	void CallClearDrawScreen();
};

