#include "CollisionService.h"

//��ŁA���̕ӂ̓x�N�g�����g��������ɕς������B

bool CollisionService::checkCollisionByRectAndRect(RectCollision basis_rect_collision, RectCollision target_rect_collision)
{
	if ((basis_rect_collision.getCurrentXLeft() < target_rect_collision.getCurrentXRight()) &&
		(basis_rect_collision.getCurrentXRight() > target_rect_collision.getCurrentXLeft()) &&
		(basis_rect_collision.getCurrentYTop() > target_rect_collision.getCurrentYBottom()) &&
		(basis_rect_collision.getCurrentYBottom() < target_rect_collision.getCurrentYTop())
		) return true;

	return false;
}


bool CollisionService::checkCollisionLeftAndRightByRectandRect(RectCollision basis_rect_collision, RectCollision target_rect_collision)
{
	if ((basis_rect_collision.getCurrentXLeft() < target_rect_collision.getCurrentXRight()) &&
		(basis_rect_collision.getCurrentXRight() > target_rect_collision.getCurrentXLeft())
		) return true;

	return false;
}


bool CollisionService::checkCollisionUpAndDownByRectandRect(RectCollision basis_rect_collision, RectCollision target_rect_collision)
{
	if ((basis_rect_collision.getCurrentYTop() > target_rect_collision.getCurrentYBottom()) &&
		(basis_rect_collision.getCurrentYBottom() < target_rect_collision.getCurrentYTop())
		) {
		return true;
	}
	return false;
}

// �p�^�[�����֐��������邱�ƂɂȂ�͔̂@���Ȃ��̂��E�E�Ƃ͌����A�l�𓊂���ƃI�u�W�F�N�g�w���ł͂Ȃ����B
bool CollisionService::checkShiftedToLeftByRectandRect(RectCollision basis_rect_collision, RectCollision target_rect_collision)
{
	//A�̉E��B�̍��̍�����A�̍���B�̉E�̍������r���O�҂��傫����΁A���ɃY���Ă�
	if ((basis_rect_collision.getCurrentXRight() - target_rect_collision.getCurrentXLeft()) > 
		(target_rect_collision.getCurrentXRight() - basis_rect_collision.getCurrentXLeft())
	   ) return true;

	//A�̉E��B�̍��̍�����A�̍���B�̉E�̍������r�����l�ł���΁A
	//A�̉E��B�̉E�A��������A�̍���B�̍����ׂđO�҂��傫����΁A
	//���ɂ���Ă���
	if ((basis_rect_collision.getCurrentXRight() - target_rect_collision.getCurrentXLeft()) ==
		(target_rect_collision.getCurrentXRight() - basis_rect_collision.getCurrentXLeft())
		) {
		if (basis_rect_collision.getCurrentXRight() >= target_rect_collision.getCurrentXRight()) return true;
	}

	return false;
}
bool CollisionService::checkShiftedToRightByRectandRect(RectCollision basis_rect_collision, RectCollision target_rect_collision)
{
	//A�̉E��B�̍��̍�����A�̍���B�̉E�̍������r����҂��傫����΁A�E�ɃY���Ă�
	if ((basis_rect_collision.getCurrentXRight() - target_rect_collision.getCurrentXLeft()) < 
		(target_rect_collision.getCurrentXRight() - basis_rect_collision.getCurrentXLeft())
		) return true;
	return false;

	//A�̉E��B�̍��̍�����A�̍���B�̉E�̍������r�����l�ł���΁A
	//A�̉E��B�̉E�A��������A�̍���B�̍����ׂČ�҂��傫����΁A
	//�E�ɂ���Ă���
	if ((basis_rect_collision.getCurrentXRight() - target_rect_collision.getCurrentXLeft()) ==
		(target_rect_collision.getCurrentXRight() - basis_rect_collision.getCurrentXLeft())
		) {
		if (basis_rect_collision.getCurrentXLeft() < target_rect_collision.getCurrentXLeft()) return true;
	}
	
	return false;
}
bool CollisionService::checkShiftedToBottomByRectandRect(RectCollision basis_rect_collision, RectCollision target_rect_collision)
{
	//A�̏��B�̉��̍�����A�̉���B�̏�̍������r���O�҂��傫����΁A���ɂ���Ă�
	if ((basis_rect_collision.getCurrentYTop() - target_rect_collision.getCurrentYBottom()) >
		(target_rect_collision.getCurrentYTop() - basis_rect_collision.getCurrentYBottom())
		) return true;

	//A�̏��B�̉��̍�����A�̉���B�̏�̍������r�����l�ł���΁A
	//A�̏��B�̏�A��������A�̉���B�̉����ׂđO�҂��傫����΁A
	//���ɂ���Ă���
	if ((basis_rect_collision.getCurrentYTop() - target_rect_collision.getCurrentYBottom()) ==
		(target_rect_collision.getCurrentYTop() - basis_rect_collision.getCurrentYBottom())
		) {
		if (basis_rect_collision.getCurrentYTop() >= target_rect_collision.getCurrentYTop()) return true;
		
	}

	return false;
}

bool CollisionService::checkShiftedToTopByRectandRect(RectCollision basis_rect_collision, RectCollision target_rect_collision)
{
	//A�̏��B�̉��̍�����A�̉���B�̏�̍������r����҂��傫����΁A��ɂ���Ă���
	if ((basis_rect_collision.getCurrentYTop() - target_rect_collision.getCurrentYBottom()) <
		(target_rect_collision.getCurrentYTop() - basis_rect_collision.getCurrentYBottom())
		) return true;

	//A�̏��B�̉��̍�����A�̉���B�̏�̍������r�����l�ł���΁A
	//A�̏��B�̏�A��������A�̉���B�̉����ׂČ�҂��傫����΁A
	//��ɂ���Ă���
	if ((basis_rect_collision.getCurrentYTop() - target_rect_collision.getCurrentYBottom()) ==
		(target_rect_collision.getCurrentYTop() - basis_rect_collision.getCurrentYBottom())
		) {
		if (basis_rect_collision.getCurrentYBottom() < target_rect_collision.getCurrentYBottom()) return true;
	}

	return false;
}

//�}�C�i�X���l����Ƃ킯�킩���̂Ő�Βl�ŏo���B
float CollisionService::differenceXLeftByRectandRect(RectCollision basis_rect_collision, RectCollision target_rect_collision)
{
	float difference = basis_rect_collision.getCurrentXLeft() - target_rect_collision.getCurrentXRight();
	return fabsf(difference);
}

float CollisionService::differenceXRightByRectandRect(RectCollision basis_rect_collision, RectCollision target_rect_collision)
{
	float difference = basis_rect_collision.getCurrentXRight() - target_rect_collision.getCurrentXLeft();
	return fabsf(difference);
}

float CollisionService::differenceYTopByRectandRect(RectCollision basis_rect_collision, RectCollision target_rect_collision)
{
	float difference = basis_rect_collision.getCurrentYTop() - target_rect_collision.getCurrentYBottom();
	return fabsf(difference);
}

float CollisionService::differenceYBottomByRectandRect(RectCollision basis_rect_collision, RectCollision target_rect_collision)
{
	float difference = basis_rect_collision.getCurrentYBottom() - target_rect_collision.getCurrentYTop();
	return fabsf(difference);
}


//debug�p
void CollisionService::drawCollisionByRect(RectCollision rect_collision, int r, int g, int b, MainCamera main_camera)
{
	DrawBox(
		(int) rect_collision.getCurrentXLeft() - main_camera.MovingDistanceX(),
		-(int) (rect_collision.getCurrentYTop() - main_camera.MovingDistanceY()),
		(int) rect_collision.getCurrentXRight() - main_camera.MovingDistanceX(),
		-(int) (rect_collision.getCurrentYBottom() - main_camera.MovingDistanceY()),
		GetColor(r, g, b),
		false
	);

}