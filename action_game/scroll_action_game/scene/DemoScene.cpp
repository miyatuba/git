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
	this->hero.MoveNoInput();


	this->draw.CallClearDrawScreen();

	
	this->ProcessStage();

	//敵からの攻撃や障害物


	this->draw.DrawGame(this->hero);
	if (DebugMode::isDebugMode()) {
		CollisionService::drawCollisionByRect(this->hero.getCollision());
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
					//主人公とマップチップの当たり判定
					DemoScene::checkCollisionByHeroAndMapTip(this->hero, map_tip);
					if (DebugMode::isDebugMode()) {
						//CollisionService::drawCollisionByRect(map_tip.getCollision());
					}

					//描画
					this->draw.StageDraw(map_tip, x, y);
					
				}
			}
			return;
	}

}

//制作途中
void DemoScene::checkCollisionByHeroAndMapTip(Hero hero, MapTip map_tip)
{

	if (this->input.IsInputLeft()) {
		float difference = CollisionService::differenceXLeftByRectandRect(hero.getCollision(), map_tip.getCollision());
		hero.MoveLeft((int) difference);
	}
	if (this->input.IsInputRight()) {
		float difference = CollisionService::differenceXRightByRectandRect(hero.getCollision(), map_tip.getCollision());
		hero.MoveRight((int) difference);
	}
	if (hero.isFall()) {
		float difference = CollisionService::differenceYBottomByRectandRect(hero.getCollision(), map_tip.getCollision());
		hero.MoveTop((int) difference);
	}
	if (hero.isJump()) {
		float difference = CollisionService::differenceYTopByRectandRect(hero.getCollision(), map_tip.getCollision());
		hero.MoveBottom((int) difference);
	}
}