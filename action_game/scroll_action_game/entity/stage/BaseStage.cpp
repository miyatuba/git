#include "BaseStage.h"

//戻り値をMapクラスに変えるべき
MapTip BaseStage::getMapTopHandol(int x, int y)
{
	std::string error_message = "BaseStageのgetMapTopHandolが呼ばれた";
	throw error_message;
	MapTip map(0);
	return map;
}