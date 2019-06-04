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
	void DrawGame(const IDraw&, MainCamera);
	void StageDraw(MapTip&, int, int, MainCamera);
	void CallScreenFlip();
	void CallClearDrawScreen();
};

