#include "BaseStage.h"


MapTip BaseStage::getMapTopHandol(int x, int y)
{
	std::string error_message = "BaseStage��getMapTopHandol���Ă΂ꂽ";
	throw error_message;
	MapTip map(0, 0, false, x, y);
	return map;
}