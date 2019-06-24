#include "DemoScene.h"

DemoScene::DemoScene()
{

}

DemoScene::DemoScene(int stage_number)
{
	MainCamera main_camera(80, -80);
	this->main_camera = main_camera;
	this->current_stage_id = stage_number;
	Hero hero;
}

void DemoScene::initLoopDemoScene()
{	
	this->is_checked_scaffold_for_hero = false;
	this->main_camera.initForLoop();

	this->hero.initForLoop();
	this->hero.UpdateBeforeMovingRectCollision();
}

//マップチップとの確認の計算コストが高すぎる。5×マップチップの数のループ・・要修正
void DemoScene::Play()
{
	this->initLoopDemoScene();
	BaseScene::Play();
	//入力用デバッグ指定したキーのみでブレークしたいときに
	if (DebugMode::isDebugMode()) {
		if ((this->input.IsInputUp()) && (this->input.IsInputRight())) {
			int a = 1;
		}
	}

	//試しにキーで操作できるカメラ操作を入れてみる(デバッグ用に必要になるかも
	/*if (this->input.IsInput1()) {
		this->main_camera.moveLeftX(1);
	}
	if (this->input.IsInput2()) {
		this->main_camera.moveRightX(1);
	}
	if (this->input.IsInput3()) {
		this->main_camera.moveUpY(1);
	}
	if (this->input.IsInput4()) {
		this->main_camera.moveDownY(1);
	}*/

	//プレイヤーの攻撃

	//プレイヤーの移動、左右
	this->hero.MovePositionByInput(this->input);

	//プレイヤーとマップの判定で、プレイヤーの可能な状態を整理、左右移動（後程、画面内のみに変える
	this->checkPlayerAndMapForLeftRight();

	//プレイヤーの移動、上下
	this->hero.MoveNoInput();

	//プレイヤーとマップの判定で、プレイヤーの可能な状態を整理、上下移動（後程、画面内のみに変える
	this->checkPlayerAndMapForTopBottom();

	//敵とマップの判定

	//敵からの攻撃や障害物

	//プレイヤーの位置とカメラ補正
	this->main_camera.TrackingByTargetPositionX(this->hero.getPositionX() + (this->hero.getSizeX() / 2));

	//カメラとマップチップの判定で、カメラの補正
	this->checkCameraAndMapForLeftRight();

	this->main_camera.TrackingByTargetPositionY(this->hero.getPositionY() - (this->hero.getSizeY() / 2));

	this->checkCameraAndMapForTopBottom();

	//描画削除
	this->draw.CallClearDrawScreen();

	//ステージの描画（画面に映るものだけにしたい
	this->ProcessStage();

	//ヒーローや敵の描画
	this->draw.DrawGame(this->hero, this->main_camera);

	if (DebugMode::isDebugMode()) {
		CollisionService::drawCollisionByRect(this->hero.getCollision(), 0, 255, 0, this->main_camera);
	}
	if (DebugMode::isDebugMode()) {
		DrawFormatString(0, 0, GetColor(0, 0, 255), "LX座標%f:RX座標%f:TY座標%f:BY座標%f",
			this->hero.getCollision().getCurrentXLeft(),
			this->hero.getCollision().getCurrentXRight(),
			this->hero.getCollision().getCurrentYTop(),
			this->hero.getCollision().getCurrentYBottom()
		);
		MainCamera camera_debug = this->main_camera;
		RectCollision debug_collision = camera_debug.createRectCollision();
		DrawFormatString(0, 50, GetColor(0, 0, 255), "LX座標%f:RX座標%f:TY座標%f:BY座標%f",
			debug_collision.getCurrentXLeft(),
			debug_collision.getCurrentXRight(),
			debug_collision.getCurrentYTop(),
			debug_collision.getCurrentYBottom()
		);
		MapTip map = this->demo_stage.getMapTip(1,16);
		DrawFormatString(0, 100, GetColor(0, 0, 255), "LX座標%f:RX座標%f:TY座標%f:BY座標%f",
			map.getCollision().getCurrentXLeft(),
			map.getCollision().getCurrentXRight(),
			map.getCollision().getCurrentYTop(),
			map.getCollision().getCurrentYBottom()
		);
		/*MapTip maptip_debug = this->demo_stage.getMapTip(1,1);
		RectCollision debug_collision2 = maptip_debug.getCollision();
		DrawFormatString(0, 100, GetColor(0, 0, 255), "LX座標%f:RX座標%f:TY座標%f:BY座標%f",
			debug_collision2.getCurrentXLeft(),
			debug_collision2.getCurrentXRight(),
			debug_collision2.getCurrentYTop(),
			debug_collision2.getCurrentYBottom()
		);*/
	}
	

	this->draw.CallScreenFlip();
}


void DemoScene::checkPlayerAndMapForLeftRight()
{
	switch (this->current_stage_id)
	{
		case DemoScene::STAGE_ID_DEMO:
			for (int y = 0; y < DemoStage::Y_SQUARES_NUMBER; ++y) {
				for (int x = 0; x < DemoStage::X_SQUARES_NUMBER; ++x) {
					MapTip map_tip = this->demo_stage.getMapTip(x, y);
					if (map_tip.hasCollision()) {
						if (CollisionService::checkCollisionByRectAndRect(this->hero.getCollision(), map_tip.getCollision())) {
							if (this->input.IsInputLeft()) {
								float difference = CollisionService::differenceXLeftByRectandRect(this->hero.getCollision(), map_tip.getCollision());
								this->hero.MoveRight((int)difference);
							}

							if (this->input.IsInputRight()) {
								float difference = CollisionService::differenceXRightByRectandRect(this->hero.getCollision(), map_tip.getCollision());
								this->hero.MoveLeft((int)difference);
							}
						}

					}
				}
			}
			return;
	}

	return;
}

void DemoScene::checkPlayerAndMapForTopBottom()
{
	switch (this->current_stage_id)
	{
		case DemoScene::STAGE_ID_DEMO:
			for (int y = 0; y < DemoStage::Y_SQUARES_NUMBER; ++y) {
				for (int x = 0; x < DemoStage::X_SQUARES_NUMBER; ++x) {
					MapTip map_tip = this->demo_stage.getMapTip(x, y);
					if (map_tip.hasCollision()) {
						if (CollisionService::checkCollisionByRectAndRect(this->hero.getCollision(), map_tip.getCollision())) {
							if (this->hero.isFall()) {
								float difference = CollisionService::differenceYBottomByRectandRect(this->hero.getCollision(), map_tip.getCollision());
								this->hero.MoveUp((int)difference);
							}

							if (hero.isJump()) {
								float difference = CollisionService::differenceYTopByRectandRect(this->hero.getCollision(), map_tip.getCollision());
								DebugMode::floatVariable = difference;
								this->hero.MoveDown((int)difference);
								
							}
						}

						//下が足場かどうか確認
						if (!this->is_checked_scaffold_for_hero) {
							RectCollision expected_rect_collision = this->hero.getCollision();
							expected_rect_collision.moveCollisionY(-1);
							if (!CollisionService::checkCollisionByRectAndRect(expected_rect_collision, map_tip.getCollision())) {
								this->hero.OnFallStatus();//後程消すと思う
							}
							else {
								this->hero.OffFallStatus();
								this->is_checked_scaffold_for_hero = true;
							}
							expected_rect_collision.moveCollisionY(1);

						}
					}
				}
			}
			return;
	}
	return;
}


void DemoScene::checkCameraAndMapForLeftRight()
{
	//ここも恐らく上下左右同時に行うとバグるので、片方ずつ。
	switch (this->current_stage_id) {
		case DemoScene::STAGE_ID_DEMO:
			bool isChecked = false;
			for (int y = 0; y < DemoStage::Y_SQUARES_NUMBER; ++y) {
				for (int x = 0; x < DemoStage::X_SQUARES_NUMBER; ++x) {
					MapTip map_tip = this->demo_stage.getMapTip(x, y);
					if (map_tip.isCameraMovementRestriction()) {
						if (CollisionService::checkCollisionByRectAndRect(this->main_camera.createRectCollision(), map_tip.getCollision())) {
							if (isChecked == false) {
								if (this->main_camera.isCameraMovedLeft()) {
									float difference = CollisionService::differenceXLeftByRectandRect(this->main_camera.createRectCollision(), map_tip.getCollision());
									this->main_camera.moveRightX((int)difference);
								}

								if (this->main_camera.isCameraMovedRight()) {
									float difference = CollisionService::differenceXRightByRectandRect(this->main_camera.createRectCollision(), map_tip.getCollision());
									this->main_camera.moveLeftX((int)difference);
								}
								isChecked = true;
							}
							
						}
					}
				}
			}
		return;
	}
	return;
}

void DemoScene::checkCameraAndMapForTopBottom()
{
	switch (this->current_stage_id) {
		case DemoScene::STAGE_ID_DEMO:
			bool isChecked = false;
			for (int y = 0; y < DemoStage::Y_SQUARES_NUMBER; ++y) {
				for (int x = 0; x < DemoStage::X_SQUARES_NUMBER; ++x) {
					MapTip map_tip = this->demo_stage.getMapTip(x, y);
					if (map_tip.isCameraMovementRestriction()) {
						RectCollision b = this->main_camera.createRectCollision();
						RectCollision c = map_tip.getCollision();
						if (CollisionService::checkCollisionByRectAndRect(this->main_camera.createRectCollision(), map_tip.getCollision())) {
							if (isChecked == false) {
								if (this->main_camera.isCameraMovedUp()) {
									float difference = CollisionService::differenceYTopByRectandRect(this->main_camera.createRectCollision(), map_tip.getCollision());
									this->main_camera.moveDownY((int)difference);
								}

								if (this->main_camera.isCameraMovedDown()) {
									float difference = CollisionService::differenceYBottomByRectandRect(this->main_camera.createRectCollision(), map_tip.getCollision());
									this->main_camera.moveUpY((int)difference);

								}
								isChecked = true;
							}
							int a = 1;
						}
					}
				}
			}
			return;
	}
	return;
}

//マップチップのループで当たり判定しておく方が良い？ループ節約(処理の順番見直しの為に下記は消すかも
void DemoScene::ProcessStage()
{
	switch (this->current_stage_id)
	{
		case DemoScene::STAGE_ID_DEMO:
			for (int y = 0; y < DemoStage::Y_SQUARES_NUMBER; ++y) {
				for (int x = 0; x < DemoStage::X_SQUARES_NUMBER; ++x) {
					MapTip map_tip = this->demo_stage.getMapTip(x, y);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           

					//描画 
					if (map_tip.hasMapTipHandle()) {
						this->draw.StageDraw(map_tip, x, y, this->main_camera);

						if (map_tip.hasCollision()) {
							if (DebugMode::isDebugMode()) {
								CollisionService::drawCollisionByRect(map_tip.getCollision(), 255, 0, 0, this->main_camera);
							}
						}
					} 
					
				}
			}
			return;
	}

}
