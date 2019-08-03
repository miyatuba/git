#include "EnemyTest1.h"

EnemyTest1::EnemyTest1()
{
	this->x = 270;
	this->y = -250;

	RectCollision rect_collision(
		(float)this->x,
		(float)(this->x + EnemyTest1::X_SIZE),
		(float)this->y,
		(float)(this->y - EnemyTest1::Y_SIZE)
	);
	this->rect_collision = rect_collision;

	this->stand_image_handle = LoadGraph(this->IMAGE_PATH.c_str());
	this->direction = BaseEnemy::DIRECTION_LEFT;
}

//これはベースにも記述するべき？
void EnemyTest1::initForLoop()
{
	this->is_checked_scaffold = false;
}

int EnemyTest1::getImageHandle()
{
	return this->stand_image_handle;
}

void EnemyTest1::AoutAction()
{
	//状態に応じて変更することになるが、まずは左に移動するだけのAI
	if (this->isDirectionLeft()) {
		this->MoveLeft(1);
	}
	else if (this->isDirectionRight()) {
		this->MoveRight(1);
	}

	if (this->isFall()) {
		this->MoveDown(1);
	}
}

void EnemyTest1::MoveLeft(int x)
{
	this->x -= x;
	this->rect_collision.moveCollisionX(-x);
}

void EnemyTest1::MoveRight(int x)
{
	this->x += x;
	this->rect_collision.moveCollisionX(x);
}

void EnemyTest1::MoveDown(int y)
{
	this->y -= y;
	this->rect_collision.moveCollisionY(-y);
}

void EnemyTest1::MoveUp(int y)
{
	this->y += y;
	this->rect_collision.moveCollisionY(y);
}

bool EnemyTest1::isFall()
{
	return this->is_fall;
}

void EnemyTest1::OnFallStatus()
{
	this->is_fall = true;
}

void EnemyTest1::OffFallStatus()
{
	this->is_fall = false;
}

void EnemyTest1::checkHeroAndMapForLeftRight(MapTip map_tip)
{
	if (CollisionService::checkCollisionByRectAndRect(this->getCollision(), map_tip.getCollision())) {

		if (this->isDirectionLeft()) {
			float dfference = CollisionService::differenceXLeftByRectAndRect(this->getCollision(), map_tip.getCollision());
			this->MoveRight((int) dfference);
			//AI系になるから、EnemyEntityに記述したい感がある。
			this->changeDirectionRight();
		}
		else if (this->isDirectionRight()) {
			float dfference = CollisionService::differenceXRightByRectAndRect(this->getCollision(), map_tip.getCollision());
			this->MoveLeft((int) dfference);
			this->changeDirectionLeft();
		}

	}
}

void EnemyTest1::checkHeroAndMapForTopBottom(MapTip map_tip)
{
	if (CollisionService::checkCollisionByRectAndRect(this->getCollision(), map_tip.getCollision())) {

		if (this->isFall()) {
			float dfference = CollisionService::differenceYBottomByRectAndRect(this->getCollision(), map_tip.getCollision());
			this->MoveUp((int) dfference);

		}
		if (false) {//敵の上へ移動する条件次第
			float dfference = CollisionService::differenceYTopByRectAndRect(this->getCollision(), map_tip.getCollision());
			this->MoveDown((int) dfference);
		}

	}

	//下が足場かどうか確認
	if (! this->is_checked_scaffold) {
		RectCollision expected_rect_collision = this->getCollision();
		expected_rect_collision.moveCollisionY(-1);
		if (! CollisionService::checkCollisionByRectAndRect(expected_rect_collision, map_tip.getCollision())) {
			this->OnFallStatus();
		}
		else {
			this->OffFallStatus();
			this->is_checked_scaffold = true;
		}
		expected_rect_collision.moveCollisionY(1);

	}
}