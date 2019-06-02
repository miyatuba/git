#include "DemoScene.h"

DemoScene::DemoScene()
{

}

DemoScene::DemoScene(int stage_number)
{
	Hero hero;
	this->hero = hero;
	DemoStage demo_stage;
	this->demo_stage = demo_stage;
	this->current_stage_id = DemoScene::STAGE_ID_DEMO;
}

void DemoScene::initLoopDemoScene()
{	
	this->is_checked_scaffold_for_hero = false;
}

void DemoScene::Play()
{
	this->initLoopDemoScene();
	BaseScene::Play();
	//入力用デバッグ
	if (DebugMode::isDebugMode()) {
		if ((this->input.IsInputUp()) && (this->input.IsInputRight())) {
			int a = 1;
		}
	}

	//プレイヤーの攻撃

	//プレイヤーの移動
	this->hero.UpdateBeforeMovingRectCollision();//ベクトルを使わないため、動く前の座標を記録し、当たり判定が左右or上下の判断をする
	this->hero.MovePositionByInput(this->input);
	this->hero.MoveNoInput();


	this->draw.CallClearDrawScreen();

	
	this->ProcessStage();

	//敵からの攻撃や障害物


	this->draw.DrawGame(this->hero);
	if (DebugMode::isDebugMode()) {
		CollisionService::drawCollisionByRect(this->hero.getCollision(), 0, 255, 0);
	}

	if (DebugMode::isDebugMode()) {
		DrawFormatString(0, 0, GetColor(0, 0, 255), "LX座標%f:RX座標%f:TY座標%f:BY座標%f",
			this->hero.getCollision().getCurrentXLeft(),
			this->hero.getCollision().getCurrentXRight(),
			this->hero.getCollision().getCurrentYTop(),
			this->hero.getCollision().getCurrentYBottom()
		);
		DrawFormatString(0, 50, GetColor(0, 0, 255), "LX座標%f:RX座標%f:TY座標%f:BY座標%f",
			this->hero.getBeforeMovingRectCollision().getCurrentXLeft(),
			this->hero.getBeforeMovingRectCollision().getCurrentXRight(),
			this->hero.getBeforeMovingRectCollision().getCurrentYTop(),
			this->hero.getBeforeMovingRectCollision().getCurrentYBottom()
		);
		MapTip map_tip_debug = this->demo_stage.getMapTip(3, 3);
		DrawFormatString(0, 100, GetColor(0, 0, 255), "LX座標%f:RX座標%f:TY座標%f:BY座標%f",
			map_tip_debug.getCollision().getCurrentXLeft(),
			map_tip_debug.getCollision().getCurrentXRight(),
			map_tip_debug.getCollision().getCurrentYTop(),
			map_tip_debug.getCollision().getCurrentYBottom()
		);
	}
	

	this->draw.CallScreenFlip();
}

//マップチップのループで当たり判定しておく方が良い？ループ節約
void DemoScene::ProcessStage()
{
	switch (this->current_stage_id)
	{
		case DemoScene::STAGE_ID_DEMO:
			for (int y = 0; y < DemoStage::Y_SQUARES_NUMBER; ++y) {
				for (int x = 0; x < DemoStage::X_SQUARES_NUMBER; ++x) {
					MapTip map_tip = this->demo_stage.getMapTip(x, y);

					//一気にやると訳が分からないのでデバッグ用にピックアップ
					if (map_tip.hasCollision()) {
						//主人公とマップチップの当たり判定
						this->checkCollisionByHeroAndMapTip(this->hero, map_tip);

					}

					//描画
					this->draw.StageDraw(map_tip, x, y);

					//一気にやると訳が分からないのでデバッグ用にピックアップ
					if (map_tip.hasCollision()) {
						if (DebugMode::isDebugMode()) {
							CollisionService::drawCollisionByRect(map_tip.getCollision(), 255, 0, 0);
						}
					}

				}
			}
			return;
	}

}

//斜め移動、実際は落下しながらとかジャンプしながらの左右移動の挙動だと怪しいの、そこを煮詰める必要がある
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
				hero.MoveUp(difference);
				hero.ChangeFallStatusFalse();//後程消すと思う
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
			hero.ChangeFallStatusTrue();//後程消すと思う
		}
		expected_rect_collision.moveCollisionY(1);
		this->is_checked_scaffold_for_hero = true;
	}

}