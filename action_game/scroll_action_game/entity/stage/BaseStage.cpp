#include "BaseStage.h"


MapTip BaseStage::getMapTip(int x, int y)
{
	std::string error_message = "BaseStageのgetMapTopHandolが呼ばれた";
	throw error_message;
	MapTip map(0, 0, false, x, y);
	return map;
}