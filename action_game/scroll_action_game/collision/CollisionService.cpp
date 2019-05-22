#include "CollisionService.h"

//��ŁA���̕ӂ̓x�N�g�����g��������ɕς������B
bool CollisionService::checkCliisionByRectandRect(RectCollision rectCollision1, RectCollision rectCollision2)
{
	if (rectCollision1.getCurrentXLeft() < rectCollision2.getCurrentXRight() &&
		rectCollision1.getCurrentYTop() < rectCollision2.getCurrentYBottom() &&
		rectCollision1.getCurrentXRight() > rectCollision2.getCurrentXLeft &&
		rectCollision1.getCurrentYBottom() > rectCollision2.getCurrentYTop()
		) return true;

	return false;
}
