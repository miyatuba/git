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

	//�v���C���[�̍U��

	//�v���C���[�̈ړ�
	this->hero.MovePositionByInput(this->input);
	this->hero.MoveNoInput();


	this->draw.CallClearDrawScreen();

	
	this->ProcessStage();

	//�G����̍U�����Q��


	this->draw.DrawGame(this->hero);
	if (DebugMode::isDebugMode()) {
		CollisionService::drawCollisionByRect(this->hero.getCollision(), 0, 255, 0);
	}


	this->draw.CallScreenFlip();
}

//�}�b�v�`�b�v�̃��[�v�œ����蔻�肵�Ă��������ǂ��H���[�v�ߖ�
void DemoScene::ProcessStage()
{
	switch (this->current_stage_id)
	{
		case DemoScene::STAGE_ID_DEMO:
			for (int y = 0; y < DemoStage::Y_SQUARES_NUMBER; ++y) {
				for (int x = 0; x < DemoStage::X_SQUARES_NUMBER; ++x) {
					MapTip map_tip = this->demo_stage.getMapTip(x, y);

					//��C�ɂ��Ɩ󂪕�����Ȃ��̂Ńf�o�b�O�p��1�s�b�N�A�b�v
					if (x == 3 && y == 5) {
						//��l���ƃ}�b�v�`�b�v�̓����蔻��
						this->checkCollisionByHeroAndMapTip(this->hero, map_tip);

					}

					//�`��
					this->draw.StageDraw(map_tip, x, y);

					//��C�ɂ��Ɩ󂪕�����Ȃ��̂Ńf�o�b�O�p��1�s�b�N�A�b�v
					if (x == 3 && y == 5) {
						if (DebugMode::isDebugMode()) {
							CollisionService::drawCollisionByRect(map_tip.getCollision(), 255, 0, 0);
						}
					}

				}
			}
			return;
	}

}

//�����A�f�o�b�O�Œǂ��Ă݂����A��������map_tip��Y���W����������
void DemoScene::checkCollisionByHeroAndMapTip(Hero &hero, MapTip map_tip)
{

	if (this->input.IsInputLeft()) {
		if (CollisionService::checkCollisionFromLeftByRectandRect(hero.getCollision(), map_tip.getCollision())) {
			float difference = CollisionService::differenceXLeftByRectandRect(hero.getCollision(), map_tip.getCollision());
			hero.MoveRight((int)difference);
		}
		
	}
	if (this->input.IsInputRight()) {
		if (CollisionService::checkCollisionFromRightByRectandRect(hero.getCollision(), map_tip.getCollision())) {
			float difference = CollisionService::differenceXRightByRectandRect(hero.getCollision(), map_tip.getCollision());
			hero.MoveLeft((int)difference);
		}
	}

	/*if (this->input.IsInputDown()) {
		float difference = CollisionService::differenceYBottomByRectandRect(hero.getCollision(), map_tip.getCollision());
		hero.MoveUp((int) difference);
	}*/

	/*if (hero.isFall()) {
		float difference = CollisionService::differenceYBottomByRectandRect(hero.getCollision(), map_tip.getCollision());
		hero.MoveUp((int) 100);
	}*/
	/*if (hero.isJump()) {
		float difference = CollisionService::differenceYTopByRectandRect(hero.getCollision(), map_tip.getCollision());
		hero.MoveBottom((int) difference);
	}*/
}