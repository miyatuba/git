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
	//���͗p�f�o�b�O
	if (DebugMode::isDebugMode()) {
		if ((this->input.IsInputUp()) && (this->input.IsInputRight())) {
			int a = 1;
		}
	}

	//�v���C���[�̍U��

	//�v���C���[�̈ړ�
	this->hero.UpdateBeforeMovingRectCollision();//�x�N�g�����g��Ȃ����߁A�����O�̍��W���L�^���A�����蔻�肪���Eor�㉺�̔��f������
	this->hero.MovePositionByInput(this->input);
	this->hero.MoveNoInput();


	this->draw.CallClearDrawScreen();

	
	this->ProcessStage();

	//�G����̍U�����Q��


	this->draw.DrawGame(this->hero);
	if (DebugMode::isDebugMode()) {
		CollisionService::drawCollisionByRect(this->hero.getCollision(), 0, 255, 0);
	}

	if (DebugMode::isDebugMode()) {
		DrawFormatString(0, 0, GetColor(0, 0, 255), "LX���W%f:RX���W%f:TY���W%f:BY���W%f",
			this->hero.getCollision().getCurrentXLeft(),
			this->hero.getCollision().getCurrentXRight(),
			this->hero.getCollision().getCurrentYTop(),
			this->hero.getCollision().getCurrentYBottom()
		);
		DrawFormatString(0, 50, GetColor(0, 0, 255), "LX���W%f:RX���W%f:TY���W%f:BY���W%f",
			this->hero.getBeforeMovingRectCollision().getCurrentXLeft(),
			this->hero.getBeforeMovingRectCollision().getCurrentXRight(),
			this->hero.getBeforeMovingRectCollision().getCurrentYTop(),
			this->hero.getBeforeMovingRectCollision().getCurrentYBottom()
		);
		MapTip map_tip_debug = this->demo_stage.getMapTip(3, 3);
		DrawFormatString(0, 100, GetColor(0, 0, 255), "LX���W%f:RX���W%f:TY���W%f:BY���W%f",
			map_tip_debug.getCollision().getCurrentXLeft(),
			map_tip_debug.getCollision().getCurrentXRight(),
			map_tip_debug.getCollision().getCurrentYTop(),
			map_tip_debug.getCollision().getCurrentYBottom()
		);
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

					//��C�ɂ��Ɩ󂪕�����Ȃ��̂Ńf�o�b�O�p�Ƀs�b�N�A�b�v
					if (map_tip.hasCollision()) {
						//��l���ƃ}�b�v�`�b�v�̓����蔻��
						this->checkCollisionByHeroAndMapTip(this->hero, map_tip);

					}

					//�`��
					this->draw.StageDraw(map_tip, x, y);

					//��C�ɂ��Ɩ󂪕�����Ȃ��̂Ńf�o�b�O�p�Ƀs�b�N�A�b�v
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

//�΂߈ړ��A���ۂ͗������Ȃ���Ƃ��W�����v���Ȃ���̍��E�ړ��̋������Ɖ������́A�������ϋl�߂�K�v������
void DemoScene::checkCollisionByHeroAndMapTip(Hero& hero, MapTip map_tip)
{
	//���͏󋵂ɉ�������@���Ƃ��Ă݂��A����ł��܂������Ȃ���΁A���͏󋵂ɂ��A�}�b�v�`�b�v�̏����̏��Ԃ�����or�E���A�㏇or�����̐؂�ւ������v�����Ȃ�
	//��L�̕��@���ƁA�v���C���[�ȊO�̃L�������ړ�����ꍇ�ɋl��
	if (CollisionService::checkCollisionByRectandRect(hero.getCollision(), map_tip.getCollision())) {
		
		if (hero.isFall()) {
		//if (this->input.IsInputDown()){
			if (!CollisionService::checkCollisionLeftAndRightByRectandRect(hero.getBeforeMovingRectCollision(), map_tip.getCollision()) &&
				(this->input.IsInputLeft() || this->input.IsInputRight())) {
			}
			else {
				float difference = CollisionService::differenceYBottomByRectandRect(hero.getCollision(), map_tip.getCollision());
				hero.MoveUp(difference);
				hero.ChangeFallStatusFalse();//��������Ǝv��
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

	//�������ꂩ�ǂ����m�F
	if (!this->is_checked_scaffold_for_hero) {
		RectCollision expected_rect_collision = hero.getCollision();
		expected_rect_collision.moveCollisionY(-1);
		if (!CollisionService::checkCollisionByRectandRect(expected_rect_collision, map_tip.getCollision())) {
			hero.ChangeFallStatusTrue();//��������Ǝv��
		}
		expected_rect_collision.moveCollisionY(1);
		this->is_checked_scaffold_for_hero = true;
	}

}