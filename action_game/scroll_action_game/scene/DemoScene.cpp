#include "DemoScene.h"

DemoScene::DemoScene()
{

}

DemoScene::DemoScene(int stage_number)
{
	MainCamera main_camera(81, -81);
	this->main_camera = main_camera;
	this->current_stage_id = stage_number;
	Hero hero;
}

void DemoScene::initLoopDemoScene()
{	
	this->is_checked_scaffold_for_hero = false;
	this->main_camera.initForLoop();
}

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

	//試しにキーで操作できるカメラ操作を入れてみる
	if (this->input.IsInput1()) {
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
	}

	//プレイヤーの攻撃

	//プレイヤーの移動
	this->hero.UpdateBeforeMovingRectCollision();
	this->hero.MovePositionByInput(this->input);
	this->hero.MoveNoInput();

	this->draw.CallClearDrawScreen();

	//プレイヤーの位置とカメラ補正
	this->main_camera.TrackingByTargetPosition(this->hero.getPositionX() + (this->hero.getSizeX() / 2), this->hero.getPositionY() + (this->hero.getSizeY() / 2));

	this->ProcessStage();

	
	//敵からの攻撃や障害物


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

//マップチップのループで当たり判定しておく方が良い？ループ節約
void DemoScene::ProcessStage()
{
	switch (this->current_stage_id)
	{
		case DemoScene::STAGE_ID_DEMO:
			//ステージのカメラ操作の上下左右限界をここで判断するんだろうが、下記は描画処理を含むために、分けなくてはならない、
			//再度ループを回すのは如何なものか・・
			bool debug = true;
			for (int y = 0; y < DemoStage::Y_SQUARES_NUMBER; ++y) {
				for (int x = 0; x < DemoStage::X_SQUARES_NUMBER; ++x) {
					MapTip map_tip = this->demo_stage.getMapTip(x, y);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
					if (map_tip.hasCollision()) {
						//主人公とマップチップの当たり判定
						this->checkCollisionByHeroAndMapTip(this->hero, map_tip);

					}

					//画面外かどうかのチェック
					if (!map_tip.hasMapTipHandle()) {
						//画面外かどうかの判定
						RectCollision a = this->main_camera.createRectCollision();
						RectCollision b = map_tip.getCollision();
						if (CollisionService::checkCollisionByRectandRect(this->main_camera.createRectCollision(), map_tip.getCollision())) {
							//差分を計算して動く、画面外や画面リミットのマップチップが画面内にある場合の想定は保証しない

							//左にずれているか（左を先に確認するために、同値であった場合は右に優先的にずらすことになる。
							//1：Aの右とBの左の差分とAの左とBの右の差分を比較し前者が大きければ、
							//Aの右とBの右の差分とBの右とAの左の差分を比較し前者が大きければ
							//AはAの左とBの右の差分だけ左にずれている

							//2：Aの右とBの左の差分とAの左とBの右の差分を比較し前者が大きければ、
							//Aの右とBの右の差分とBの右とAの左の差分を比較し後者が大きければ
							//AはAの左とBの右の差分だけ左にずれている

							//3：Aの右とBの左の差分とAの左のBの右の差分を比較し同値であれば、
							//Aの右とBの右、もしくはAの左のBの左を比べて前者が大きければ、
							//AはAの左とBの右の差分だけ左にずれている

							//サイズがA<Bのタイプ時に起こりうるパターン
							//Bの左<Aの右<Bの右の場合（反対側を見る必要はない
							//Bの真ん中とAの真ん中を比べてAの真ん中の方が大きい
							//AはAの左とBの右の差分だけ左にずれている
							//これは実装しなくていい気がする

							//サイズがA>Bのタイプ時に起こりうるパターン
							//Aの左<Bの右<Aの右の場合（反対側を見る必要はない
							//Bの真ん中とAの真ん中を比べてAの真ん中の方が大きい
							//AはAの左とBの右の差分だけ左にずれている
							//これは実装しなくていい気がする

							/*if (hero.isFall()) {
								if (! CollisionService::checkCollisionLeftAndRightByRectandRect(this->main_camera.createBeforeRectCollision(), map_tip.getCollision()) &&
									(this->input.IsInputLeft() || this->input.IsInputRight())) {
								}
								else {
									float difference = CollisionService::differenceYBottomByRectandRect(this->main_camera.createRectCollision(), map_tip.getCollision());
									hero.MoveUp((int)difference);
									hero.OffFallStatus();
								}
							}*/

							/*if (!CollisionService::checkCollisionUpAndDownByRectandRect(this->main_camera.createBeforeRectCollision(), map_tip.getCollision())) {
							}
							else {
								float difference = CollisionService::differenceXLeftByRectandRect(this->main_camera.createRectCollision(), map_tip.getCollision());
								this->main_camera.moveRightX((int)difference);
								debug = false;
							}*/
							/*if (CollisionService::checkShiftedToLeftByRectandRect(this->main_camera.createRectCollision(), map_tip.getCollision())) {
								//↑の判定がおかしい、上で当たっていても入ってくるバグあり？
								float difference_shifted_to_left = CollisionService::differenceXLeftByRectandRect(this->main_camera.createRectCollision(), map_tip.getCollision());

								this->main_camera.moveRightX((int) difference_shifted_to_left);
							}*/


							//右にずれているか
							//1：Aの右とBの左の差分とAの左とBの右の差分を比較し後者が大きければ、
							//Aの左とBの左の差分とBの左とAの右の差分を比較し前者が大きければ
							//AはAの右とBの左の差分だけ右にずれている

							//2：Aの右とBの左の差分とAの左とBの右の差分を比較し後者が大きければ、
							//Aの左とBの左の差分とBの左とAの右の差分を比較し後者が大きければ
							//AはAの右とBの左の差分だけ右にずれている

							//3：Aの右とBの左の差分とAの左のBの右の差分を比較し同値であれば、
							//Aの右とBの右、もしくはAの左のBの左を比べて後者が大きければ、
							//AはAの右とBの左の差分だけ右にずれている
							//これだけは無理や。別で抜き出す

							//サイズがA<Bのタイプ時に起こりうるパターン
							//Bの左<Aの左<Bの右の場合（反対側を見る必要はない
							//Bの真ん中とAの真ん中を比べてBの真ん中の方が大きい
							//AはAの右とBの左の差分だけ右にずれている
							//これは実装しなくていい気がする

							//サイズがA>Bのタイプ時に起こりうるパターン
							//Aの左<Bの左<Aの右の場合（反対側を見る必要はない
							//Bの真ん中とAの真ん中を比べてBの真ん中の方が大きい
							//AはAの右とBの左の差分だけ右にずれている
							//これは実装しなくていい気がする

							/*if (CollisionService::checkShiftedToRightByRectandRect(this->main_camera.createRectCollision(), map_tip.getCollision())) {
								float difference_shifted_to_right = CollisionService::differenceXRightByRectandRect(this->main_camera.createRectCollision(), map_tip.getCollision());
								this->main_camera.moveLeftX((int) difference_shifted_to_right);
							}*/

							//上下の判別

							//下にずれているか（下を先に確認するために、同値であった場合は上に優先的にずらすことになる。
							//1：Aの上とBの下の差分とAの下とBの上の差分を比較し前者が大きければ、
							//Aの上とBの上の差分とBの上とAの下の差分を比較し前者が大きければ
							//AはAの下とBの上の差分だけ下にずれている

							//2：Aの上とBの下の差分とAの下とBの上の差分を比較し前者が大きければ、
							//Aの上とBの上の差分とBの上とAの下の差分を比較し後者が大きければ
							//AはAの下とBの上の差分だけ下にずれている

							//3：Aの上とBの下の差分とAの下のBの上の差分を比較し同値であれば、
							//Aの上とBの上、もしくはAの下のBの下を比べて前者が大きければ、
							//AはAの下とBの上の差分だけ下にずれている

							//サイズがA<Bのタイプ時に起こりうるパターン
							//Bの下<Aの上<Bの上の場合（反対側を見る必要はない
							//Bの真ん中とAの真ん中を比べてAの真ん中の方が大きい
							//AはAの下とBの上の差分だけ下にずれている

							//サイズがA>Bのタイプ時に起こりうるパターン
							//Aの下<Bの上<Aの上の場合（反対側を見る必要はない
							//Bの真ん中とAの真ん中を比べてAの真ん中の方が大きい
							//AはAの下とBの上の差分だけ下にずれている

							/*if (CollisionService::checkShiftedToBottomByRectandRect(map_tip.getCollision(), this->main_camera.createRectCollision())) {
								float difference_shifted_to_bottom = CollisionService::differenceYBottomByRectandRect(map_tip.getCollision(), this->main_camera.createRectCollision());
								this->main_camera.moveUpY((int) difference_shifted_to_bottom);
							}*/


							//上にずれているか
							//1：Aの上とBの下の差分とAの下とBの上の差分を比較し後者が大きければ、
							//Aの下とBの下の差分とBの下とAの上の差分を比較し前者が大きければ
							//AはAの上とBの下の差分だけ上にずれている

							//2：Aの上とBの下の差分とAの下とBの上の差分を比較し後者が大きければ、
							//Aの下とBの下の差分とBの下とAの上の差分を比較し後者が大きければ
							//AはAの上とBの下の差分だけ上にずれている

							//3：Aの上とBの下の差分とAの下のBの上の差分を比較し同値であれば、
							//Aの上とBの上、もしくはAの下のBの下を比べて後者が大きければ、
							//AはAの上とBの下の差分だけ上にずれている

							//サイズがA<Bのタイプ時に起こりうるパターン
							//Bの下<Aの下<Bの上の場合（反対側を見る必要はない
							//Bの真ん中とAの真ん中を比べてBの真ん中の方が大きい
							//AはAの上とBの下の差分だけ上にずれている

							//サイズがA>Bのタイプ時に起こりうるパターン
							//Aの下<Bの下<Aの上の場合（反対側を見る必要はない
							//Bの真ん中とAの真ん中を比べてBの真ん中の方が大きい
							//AはAの上とBの下の差分だけ上にずれている
							/*if (CollisionService::checkShiftedToTopByRectandRect(this->main_camera.createRectCollision(), map_tip.getCollision())) {
								float difference_shifted_to_top = CollisionService::differenceYTopByRectandRect(this->main_camera.createRectCollision(), map_tip.getCollision());
								this->main_camera.moveDownY((int) difference_shifted_to_top);
							}*/
						}

					}

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

void DemoScene::checkCollisionByHeroAndMapTip(Hero& hero, MapTip map_tip)
{
	//入力状況に応じる方法をとってみた、これでうまくいかなければ、入力状況により、マップチップの処理の順番を左順or右順、上順or下順の切り替えしか思いつかない
	//上記の方法だと、プレイヤー以外のキャラが移動する場合に詰む
	if (CollisionService::checkCollisionByRectandRect(hero.getCollision(), map_tip.getCollision())) {
		
		if (hero.isFall()) {
		//if (this->input.IsInputDown()){
			if (!CollisionService::checkCollisionLeftAndRightByRectandRect(hero.getBeforeMovingRectCollision(), map_tip.getCollision()) &&
				(this->input.IsInputLeft() || this->input.IsInputRight())) {
			}
			else {
				float difference = CollisionService::differenceYBottomByRectandRect(hero.getCollision(), map_tip.getCollision());
				hero.MoveUp((int)difference);
				hero.OffFallStatus();//後程消すと思う
			}
			
		}

		if (hero.isJump()) {
		//if (this->input.IsInputUp()) {
			if (! CollisionService::checkCollisionLeftAndRightByRectandRect(hero.getBeforeMovingRectCollision(), map_tip.getCollision()) &&
				(this->input.IsInputLeft() || this->input.IsInputRight())) {
			}else {
				float difference = CollisionService::differenceYTopByRectandRect(hero.getCollision(), map_tip.getCollision());
				hero.MoveDown((int)difference);
				hero.ChangeJumpStatus();
			}

		}

		if (this->input.IsInputLeft()) {
			if (! CollisionService::checkCollisionUpAndDownByRectandRect(hero.getBeforeMovingRectCollision(), map_tip.getCollision()) &&
				//(this->input.IsInputUp() || this->input.IsInputDown())) {
				 (!hero.isFall() || !hero.isJump())) {
			} else {
				float difference = CollisionService::differenceXLeftByRectandRect(hero.getCollision(), map_tip.getCollision());
				hero.MoveRight((int)difference);
			}
		}

		if (this->input.IsInputRight()) {
			if (!CollisionService::checkCollisionUpAndDownByRectandRect(hero.getBeforeMovingRectCollision(), map_tip.getCollision()) &&
				//(this->input.IsInputUp() || this->input.IsInputDown())) {
				 (!hero.isFall() || !hero.isJump())) {
			} else {
				float difference = CollisionService::differenceXRightByRectandRect(hero.getCollision(), map_tip.getCollision());
				hero.MoveLeft((int)difference);
			}
	
		}

		
	}

	//下が足場かどうか確認
	if (!this->is_checked_scaffold_for_hero) {
		RectCollision expected_rect_collision = hero.getCollision();
		expected_rect_collision.moveCollisionY(-1);
		if (!CollisionService::checkCollisionByRectandRect(expected_rect_collision, map_tip.getCollision())) {
			hero.OnFallStatus();//後程消すと思う
		}
		expected_rect_collision.moveCollisionY(1);
		this->is_checked_scaffold_for_hero = true;
	}

}