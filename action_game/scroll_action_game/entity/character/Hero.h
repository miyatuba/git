#pragma once
#include "DxLib.h"
#include <string>
#include "../../input/Input.h"
#include "../../view/IDraw.h"
#include "../../collision/ICollision.h"
#include "../../collision/RectCollision.h"
#include "../map/MapTip.h"
#include "../../collision/CollisionService.h"
#include "BaseEnemy.h"

class Hero : virtual public IDraw, ICollision
{
private:
	const static int JUMP_FORCE_POINT = 32;
	const static int JUMP_FRAME_TIME = 10;
	const static int FALL_SPEED = 16;
	const static int MOVE_FORCE_POINT = 8;

	const static int X_SIZE = 64;
	const static int Y_SIZE = 64;

	const static bool DIRECTION_LEFT = false;
	const static bool DIRECTION_RIGHT = true;
	bool direction = Hero::DIRECTION_RIGHT;
	
	std::string IMAGE_PATH_STAND = "./resource/image/hero/stand.jpg";
	std::string IMAGE_PATH_JUMP = "./resource/image/hero/jump.png";
	int stand_image_handle;
	int jump_image_handle;

	RectCollision rect_collision;
	RectCollision before_moving_rect_collision;
	const static float X_LEFT_RECT_COLLISION;
	const static float X_RIGHT_RECT_COLLISION;
	const static float Y_TOP_RECT_COLLISION;
	const static float Y_BOTTOM_RECT_COLLISION;

	int x = 170;//初期ポジションを入れておく（普通コンストラクターで設定する気が
	int y = -250;//初期ポジションを入れておく（普通コンストラクターで設定する気が

	bool is_fall = true;
	bool is_jump = false;
	bool is_run = false;//歩くを実装するかまだ未定
	bool is_dash = false;
	bool is_hover = false;
	bool is_checked_scaffold_for_hero = false;

	int jump_frame_elapsed_time = this->JUMP_FRAME_TIME;

public:
	Hero();

	void initForLoop();

	void MoveLeft(int);
	void MoveRight(int);
	void MoveUp(int);
	void MoveDown(int);

	void MovePositionByInput(Input);
	void MoveNoInput();

	void UpdateBeforeMovingRectCollision();

	void CheckJumpStatus();
	void ChangeJumpStatus();

	void OffFallStatus();
	void OnFallStatus();

	bool isFall();
	bool isJump();

	int getPositionX();
	int getPositionY();
	int getImageHandle();
	virtual RectCollision getCollision();

	virtual bool isDirectionRight();
	virtual bool isDirectionLeft();

	RectCollision getBeforeMovingRectCollision();

	int getSizeY();
	int getSizeX();

	void changeDirectionRight();
	void changeDirectionLeft();

	void checkCollisionHeroAndMapForLeftRight(MapTip, Input);
	void checkCollisionHeroAndMapForTopBottom(MapTip);
	void checkCollisionHeroAndEnemy(BaseEnemy);
};
