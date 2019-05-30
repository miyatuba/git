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
	this->hero.UpdateBeforeMovingRectCollision();//�x�N�g�����g��Ȃ����߁A�����O�̍��W���L�^���A�����蔻�肪���Eor�㉺�̔��f������
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

					//��C�ɂ��Ɩ󂪕�����Ȃ��̂Ńf�o�b�O�p�Ƀs�b�N�A�b�v
					if ((x == 3 && y == 3) || (x == 3 && y == 4) || (x == 5 && y == 3)) {
						//��l���ƃ}�b�v�`�b�v�̓����蔻��
						this->checkCollisionByHeroAndMapTip(this->hero, map_tip);

					}

					//�`��
					this->draw.StageDraw(map_tip, x, y);

					//��C�ɂ��Ɩ󂪕�����Ȃ��̂Ńf�o�b�O�p�Ƀs�b�N�A�b�v
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

//�΂߈ړ��A���ۂ͗������Ȃ���Ƃ��W�����v���Ȃ���̍��E�ړ��̋������Ɖ������́A�������ϋl�߂�K�v������
void DemoScene::checkCollisionByHeroAndMapTip(Hero& hero, MapTip map_tip)
{
	//�㉺�ƍ��E�ǂ���̓����蔻����ɂ��邩�A�󋵂ɉ�����\���ɂ��Ȃ��Ƃ��܂������Ȃ�
	//�ړ��O�̍��W���ێ����A������̓�����㉺�A���E�ʁX�ɔ��ʁB���X�}�[�g����Ȃ��Ǝv�����@
	if (CollisionService::checkCollisionByRectandRect(hero.getCollision(), map_tip.getCollision())) {
		if (hero.isFall()) {
			float difference = CollisionService::differenceYBottomByRectandRect(hero.getCollision(), map_tip.getCollision());
			hero.MoveUp((int)difference);
			hero.ChangeFallStatusFalse();//��������Ǝv��
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

	//�������ꂩ�ǂ����m�F
	RectCollision expected_rect_collision = hero.getCollision();
	expected_rect_collision.moveCollisionY(-1);
	if (! CollisionService::checkCollisionByRectandRect(expected_rect_collision, map_tip.getCollision())) {
			hero.ChangeFallStatusTrue();//��������Ǝv��
	}
	expected_rect_collision.moveCollisionY(1);

}