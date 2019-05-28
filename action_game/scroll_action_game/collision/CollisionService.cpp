#include "CollisionService.h"

//��ŁA���̕ӂ̓x�N�g�����g��������ɕς������B

//�����ǂǂ̕������ǂꂾ���߂荞��ł�̂��o���Ȃ��Ƃ����Ȃ�����A�e�����ɕ���
bool CollisionService::checkCollisionByRectandRect(RectCollision rectCollision1, RectCollision rectCollision2)//���̃��\�b�h�͂���Ȃ��Ȃ肻���A���������ԈႦ�Ă�
{
	if ((rectCollision1.getCurrentXLeft() < rectCollision2.getCurrentXRight()) &&
			(rectCollision1.getCurrentYTop() > rectCollision2.getCurrentYBottom()) &&
			(rectCollision1.getCurrentXRight() > rectCollision2.getCurrentXLeft()) &&
			(rectCollision1.getCurrentYBottom() < rectCollision2.getCurrentYTop())
			) return true;

	return false;

}


//���؂������ʁA�ʂ���K�v�Ȃ��������߂ɁA���炭���L4�͑S���v��Ȃ�
bool CollisionService::checkCollisionFromRightByRectandRect(RectCollision rectCollision1, RectCollision rectCollision2)
{
	if (! (rectCollision1.getCurrentXRight() > rectCollision2.getCurrentXLeft()) ) {
		return false;
	}
	if (!(rectCollision1.getCurrentXLeft() < rectCollision2.getCurrentXRight())) {
		return false;
	}

	if ((rectCollision1.getCurrentYTop() > rectCollision2.getCurrentYBottom()) && (rectCollision1.getCurrentYBottom() < rectCollision2.getCurrentYTop())) {
		return true;
	}

	return false;
}

bool CollisionService::checkCollisionFromLeftByRectandRect(RectCollision rectCollision1, RectCollision rectCollision2)
{
	if (! (rectCollision1.getCurrentXLeft() < rectCollision2.getCurrentXRight()) ) {
		return false;
	}
	if (!(rectCollision1.getCurrentXRight() > rectCollision2.getCurrentXLeft())) {
		return false;
	}

	if ((rectCollision1.getCurrentYTop() > rectCollision2.getCurrentYBottom()) && (rectCollision1.getCurrentYBottom() < rectCollision2.getCurrentYTop())) {
		return true;
	}
	return false;
}

bool CollisionService::checkCollisionFromUpByRectandRect(RectCollision rectCollision1, RectCollision rectCollision2)
{
	if (! (rectCollision1.getCurrentYTop() > rectCollision2.getCurrentYBottom()) ) {
		return false;
	}

	if ((rectCollision1.getCurrentXRight() > rectCollision2.getCurrentXLeft()) || (rectCollision1.getCurrentXLeft() < rectCollision2.getCurrentXRight())) {
		return true;
	}
	return false;
}

bool CollisionService::checkCollisionFromDownByRectandRect(RectCollision rectCollision1, RectCollision rectCollision2)
{
	if (! (rectCollision1.getCurrentYBottom() < rectCollision2.getCurrentYTop()) ) {
		return false;
	}

	if ((rectCollision1.getCurrentXRight() > rectCollision2.getCurrentXLeft()) || (rectCollision1.getCurrentXLeft() < rectCollision2.getCurrentXRight())) {
		return true;
	}
	return false;
}



//�}�C�i�X���l����Ƃ킯�킩���̂Ő�Βl�ŏo���B
float CollisionService::differenceXLeftByRectandRect(RectCollision rectCollision1, RectCollision rectCollision2)
{
	float difference = rectCollision1.getCurrentXLeft() - rectCollision2.getCurrentXRight();
	return fabsf(difference);
}

float CollisionService::differenceXRightByRectandRect(RectCollision rectCollision1, RectCollision rectCollision2)
{
	float difference = rectCollision1.getCurrentXRight() - rectCollision2.getCurrentXLeft();
	return fabsf(difference);
}

float CollisionService::differenceYTopByRectandRect(RectCollision rectCollision1, RectCollision rectCollision2)
{
	float difference = rectCollision1.getCurrentYTop() - rectCollision2.getCurrentYBottom();
	return fabsf(difference);
}

float CollisionService::differenceYBottomByRectandRect(RectCollision rectCollision1, RectCollision rectCollision2)
{
	float difference = rectCollision1.getCurrentYBottom() - rectCollision2.getCurrentYTop();
	return fabsf(difference);
}


//debug�p
void CollisionService::drawCollisionByRect(RectCollision rectCollision, int r, int g, int b)
{
	DrawBox(
		(int) rectCollision.getCurrentXLeft(),
		-(int) rectCollision.getCurrentYTop(),
		(int) rectCollision.getCurrentXRight(),
		-(int) rectCollision.getCurrentYBottom(),
		GetColor(r, g, b),
		false
	);

}