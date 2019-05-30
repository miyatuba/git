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


void DemoScene::Play()
{
	BaseScene::Play();

	//プレイヤーの攻撃

	//プレイヤーの移動
	this->hero.MovePositionByInput(this->input);
	this->hero.UpdateBeforeMovingRectCollision();//ベクトルを使わないため、動く前の座標を記録し、当たり判定が左右or上下の判断をする
	this->hero.MoveNoInput();


	this->draw.CallClearDrawScreen();

	
	this->ProcessStage();

	//敵からの攻撃や障害物


	this->draw.DrawGame(this->hero);
	if (DebugMode::isDebugMode()) {
		CollisionService::drawCollisionByRect(this->hero.getCollision(), 0, 255, 0);
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
					if ((x == 3 && y == 3) || (x == 3 && y == 4) || (x == 5 && y == 3)) {
						//主人公とマップチップの当たり判定
						this->checkCollisionByHeroAndMapTip(this->hero, map_tip);

					}

					//描画
					this->draw.StageDraw(map_tip, x, y);

					//一気にやると訳が分からないのでデバッグ用にピックアップ
					if ((x == 3 && y == 3) || (x == 3 && y == 4) || (x == 5 && y == 3)) {
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
	//上下と左右どちらの当たり判定を先にするか、状況に応じる構成にしないとうまく動かない
	//移動前の座標も保持し、そちらの当たり上下、左右別々に判別。→スマートじゃないと思う方法
	if (CollisionService::checkCollisionByRectandRect(hero.getCollision(), map_tip.getCollision())) {
		if (hero.isFall()) {
			float difference = CollisionService::differenceYBottomByRectandRect(hero.getCollision(), map_tip.getCollision());
			hero.MoveUp((int)difference);
			hero.ChangeFallStatusFalse();//後程消すと思う
		}

		if (hero.isJump()) {
			float difference = CollisionService::differenceYTopByRectandRect(hero.getCollision(), map_tip.getCollision());
			hero.MoveDown((int)difference);
			hero.ChangeJumpStatus();
		}
	}

	if (CollisionService::checkCollisionByRectandRect(hero.getCollision(), map_tip.getCollision())) {
		if (this->input.IsInputLeft()) {
			float difference = CollisionService::differenceXLeftByRectandRect(hero.getCollision(), map_tip.getCollision());
			hero.MoveRight((int)difference);
		}
		if (this->input.IsInputRight()) {
			float difference = CollisionService::differenceXRightByRectandRect(hero.getCollision(), map_tip.getCollision());
			hero.MoveLeft((int)difference);
		}

		
	}

	//下が足場かどうか確認
	RectCollision expected_rect_collision = hero.getCollision();
	expected_rect_collision.moveCollisionY(-1);
	if (! CollisionService::checkCollisionByRectandRect(expected_rect_collision, map_tip.getCollision())) {
			hero.ChangeFallStatusTrue();//後程消すと思う
	}
	expected_rect_collision.moveCollisionY(1);

}