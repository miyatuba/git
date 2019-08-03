#include "Hero.h"

const float Hero::X_LEFT_RECT_COLLISION = 0.0f;
const float Hero::X_RIGHT_RECT_COLLISION = 64.0f;
const float Hero::Y_TOP_RECT_COLLISION = 0.0f;
const float Hero::Y_BOTTOM_RECT_COLLISION = 64.0f;

Hero::Hero() 
{
	RectCollision rect_collision((float) this->x,
								 (float) (this->x + Hero::X_SIZE),
								 (float) this->y,
								 (float) (this->y - Hero::Y_SIZE)
	);

	this->stand_image_handle = LoadGraph(this->IMAGE_PATH_STAND.c_str());
	this->jump_image_handle = LoadGraph(this->IMAGE_PATH_JUMP.c_str());
	this->rect_collision = rect_collision;
}

void Hero::initForLoop()
{
	this->UpdateBeforeMovingRectCollision();
	this->is_checked_scaffold_for_hero = false;
}

//���̕ӂ�Aint�ň����čŏI�I��float�ɕϊ����邩�A�������͂��̋t���A�͂����肳���Ȃ��Ɗ�Ȃ�
void Hero::MoveLeft(int x)
{
	this->x -= x;
	this->rect_collision.moveCollisionX(-x);//�낳�N������
}

void Hero::MoveRight(int x)
{
	this->x += x;
	this->rect_collision.moveCollisionX(x);//�낳�N������
}

void Hero::MoveUp(int y)
{
	this->y += y;
	this->rect_collision.moveCollisionY(y);//�낳�N������
}

void Hero::MoveDown(int y)
{
	this->y -= y;
	this->rect_collision.moveCollisionY(-y);//�낳�N������
}

void Hero::MovePositionByInput(Input input)
{
	if (input.isInputLeft()) {
		this->MoveLeft(Hero::MOVE_FORCE_POINT);
		this->changeDirectionLeft();
	}
	if (input.isInputRight()) {
		this->MoveRight(Hero::MOVE_FORCE_POINT);
		this->changeDirectionRight();
	}
	if (input.isInputUp()) {
		//this->MoveUp(Hero::MOVE_FORCE_POINT);
	}
	if (input.isInputDown()) {
		//this->MoveDown(Hero::MOVE_FORCE_POINT);
	}


	if (input.isInputA()) {
		//�󂪔�ׂ�O��Ȃ̂ŁA������Ԃ͌��Ȃ�
		this->ChangeJumpStatus();
		this->jump_frame_elapsed_time = Hero::JUMP_FRAME_TIME;
	}
}

void Hero::MoveNoInput()
{
	//this->CheckFallStatus();
	if (this->is_fall) {
		this->MoveDown(Hero::FALL_SPEED);//�d�͉����x�́A�����x�ɍő�l��t���Ď����\��
	}

	this->CheckJumpStatus();
	if (this->is_jump) {
		this->MoveUp(Hero::JUMP_FORCE_POINT);
		this->jump_frame_elapsed_time -= 1;
	}
	
}

void Hero::ChangeJumpStatus()
{
	this->is_fall = false;
	this->is_jump = true;
}

void Hero::CheckJumpStatus()
{
	if (this->is_jump) {
		if (this->jump_frame_elapsed_time == 0)
		{
			this->is_jump = false;
			this->is_fall = true;
		}
	}
}


void Hero::OffFallStatus()
{
	//CheckFallStatus�ɏW�񂷂邱�ƂɂȂ�Ǝv��
	this->is_fall = false;
}

void Hero::OnFallStatus()
{
	//CheckFallStatus�ɏW�񂷂邱�ƂɂȂ�Ǝv��
	this->is_fall = true;
}

int Hero::getPositionX()
{
	return this->x;
}

int Hero::getPositionY()
{
	return this->y;
}

int Hero::getImageHandle()
{
	//�A�j���[�V�����������ɁA�X�̕Ԃ��͐؂�ւ��ɂ���
	if (this->is_jump) {
		return this->jump_image_handle;
	}
	if (this->is_fall) {
		return this->jump_image_handle;
	}
	return this->stand_image_handle;
}

RectCollision Hero::getCollision()
{
	return this->rect_collision;
}

bool Hero::isFall()
{
	return this->is_fall;
}

bool Hero::isJump()
{
	return this->is_jump;
}

//����g���Ă�H
void Hero::UpdateBeforeMovingRectCollision()
{
	RectCollision current_rect_collision = this->rect_collision;
	RectCollision before_moving_rect_collision(
		current_rect_collision.getCurrentXLeft(),
		current_rect_collision.getCurrentXRight(),
		current_rect_collision.getCurrentYTop(),
		current_rect_collision.getCurrentYBottom()
	);
	this->before_moving_rect_collision = before_moving_rect_collision;
}

RectCollision Hero::getBeforeMovingRectCollision()
{
	return this->before_moving_rect_collision;
}

int Hero::getSizeY()
{
	return Hero::Y_SIZE;
}

int Hero::getSizeX()
{
	return Hero::X_SIZE;
}

bool Hero::isDirectionRight()
{
	return this->direction == Hero::DIRECTION_RIGHT;
}

bool Hero::isDirectionLeft()
{
	return this->direction == Hero::DIRECTION_LEFT;
}

void Hero::changeDirectionRight()
{
	this->direction = Hero::DIRECTION_RIGHT;
}

void Hero::changeDirectionLeft()
{
	this->direction = Hero::DIRECTION_LEFT;
}

void Hero::checkHeroAndMapForLeftRight(MapTip map_tip, Input input)
{
	if (CollisionService::checkCollisionByRectAndRect(this->getCollision(), map_tip.getCollision())) {
		if (input.isInputLeft()) {
			float difference = CollisionService::differenceXLeftByRectAndRect(this->getCollision(), map_tip.getCollision());
			this->MoveRight((int) difference);
		}

		if (input.isInputRight()) {
			float difference = CollisionService::differenceXRightByRectAndRect(this->getCollision(), map_tip.getCollision());
			this->MoveLeft((int) difference);
		}
	}
}

void Hero::checkHeroAndMapForTopBottom(MapTip map_tip)
{
	if (CollisionService::checkCollisionByRectAndRect(this->getCollision(), map_tip.getCollision())) {
		if (this->isFall()) {
			float difference = CollisionService::differenceYBottomByRectAndRect(this->getCollision(), map_tip.getCollision());
			this->MoveUp((int) difference);
			this->OffFallStatus();
		}
		if (this->isJump()) {//�W�����v�����Ō��Ă��邪�A���炭�z�o�����O���Ώ�
			float difference = CollisionService::differenceYTopByRectAndRect(this->getCollision(), map_tip.getCollision());
			this->MoveDown((int) difference);
		}
	}

	if (! this->is_checked_scaffold_for_hero) {
		RectCollision expected_rect_collision = this->getCollision();
		expected_rect_collision.moveCollisionY(-1);
		if (! CollisionService::checkCollisionByRectAndRect(expected_rect_collision, map_tip.getCollision())) {
			this->OnFallStatus();
		}
		else {
			this->OffFallStatus();
			this->is_checked_scaffold_for_hero = true;
		}
		expected_rect_collision.moveCollisionY(1);
	}

}