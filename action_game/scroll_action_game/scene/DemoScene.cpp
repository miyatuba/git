#include "DemoScene.h"
//�U��
//�_���[�W
//�G�L����
//�W�����v�̊ɋ}
//�}�b�v�`�b�v�̓����菈���̓q�[���[��G��entity�Ȃ��ŋL�q����̂����E�̋C������B���̂܂܂��Ə���*�G������source�������Ȃ�

DemoScene::DemoScene()
{

}

DemoScene::DemoScene(int stage_number)
{
	MainCamera main_camera(80, -80);
	this->main_camera = main_camera;
	
	this->current_stage_id = stage_number;
	
	Hero hero;
	this->hero = hero;

	EnemyTest1 enemy_test1;
	this->enemy_test1 = enemy_test1;

	this->current_bgm_handle = LoadSoundMem(this->BGM_STAGE_TEST1.c_str());
	this->audio.PlayBGM(this->current_bgm_handle);

}

void DemoScene::initLoopDemoScene()
{	
	this->main_camera.initForLoop();

	this->hero.initForLoop();
	this->hero.UpdateBeforeMovingRectCollision();

	this->enemy_test1.initForLoop();
}

//�J�����Ƃ̓����蔻������؂��A��ʊO�ł���Ώ������Ȃ��悤�ɂ��悤���B
void DemoScene::Play()
{
	this->initLoopDemoScene();
	BaseScene::Play();
	//���͗p�f�o�b�O�w�肵���L�[�݂̂Ńu���[�N�������Ƃ���
	if (DebugMode::isDebugMode()) {
		if ((this->input.isInputUp()) && (this->input.isInputRight())) {
			int a = 1;
		}
	}

	//�����ɃL�[�ő���ł���J������������Ă݂�(�f�o�b�O�p�ɕK�v�ɂȂ邩��
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

	//�v���C���[�̍U��

	//�v���C���[�̈ړ��A���E
	this->hero.MovePositionByInput(this->input);

	//�v���C���[�ƃ}�b�v�̔���ŁA�v���C���[�̉\�ȏ�Ԃ𐮗��A���E�ړ��i����A��ʓ��݂̂ɕς���
	this->checkCharacterAndMapForLeftRight();

	//�v���C���[�̈ړ��A�㉺
	this->hero.MoveNoInput();

	//�v���C���[�ƃ}�b�v�̔���ŁA�v���C���[�̉\�ȏ�Ԃ𐮗��A�㉺�ړ��i����A��ʓ��݂̂ɕς���
	this->checkCharacterAndMapForTopBottom();

	//�G�s��
	this->enemy_test1.AoutAction();

	//�G�ƃ}�b�v�̔���


	//�G����̍U�����Q��

	//�v���C���[�̈ʒu�ƃJ�����␳
	this->main_camera.TrackingByTargetPositionX(this->hero.getPositionX() + (this->hero.getSizeX() / 2));

	//�J�����ƃ}�b�v�`�b�v�̔���ŁA�J�����̕␳
	this->checkCameraAndMapForLeftRight();

	this->main_camera.TrackingByTargetPositionY(this->hero.getPositionY() - (this->hero.getSizeY() / 2));

	this->checkCameraAndMapForTopBottom();

	//�`��폜
	this->draw.CallClearDrawScreen();

	//�X�e�[�W�̕`��
	this->ProcessStage();

	//�q�[���[��G�̕`��
	this->DrawCharacter(this->enemy_test1);
	this->DrawCharacter(this->hero);

	if (DebugMode::isDebugMode()) {
		CollisionService::drawCollisionByRect(this->hero.getCollision(), 0, 255, 0, this->main_camera);
		CollisionService::drawCollisionByRect(this->enemy_test1.getCollision(), 0, 255, 0, this->main_camera);
	}
	if (DebugMode::isDebugMode()) {
		DrawFormatString(0, 0, GetColor(0, 0, 255), "LX���W%f:RX���W%f:TY���W%f:BY���W%f",
			this->hero.getCollision().getCurrentXLeft(),
			this->hero.getCollision().getCurrentXRight(),
			this->hero.getCollision().getCurrentYTop(),
			this->hero.getCollision().getCurrentYBottom()
		);
		MainCamera camera_debug = this->main_camera;
		RectCollision debug_collision = camera_debug.createRectCollision();
		DrawFormatString(0, 50, GetColor(0, 0, 255), "LX���W%f:RX���W%f:TY���W%f:BY���W%f",
			debug_collision.getCurrentXLeft(),
			debug_collision.getCurrentXRight(),
			debug_collision.getCurrentYTop(),
			debug_collision.getCurrentYBottom()
		);
		MapTip map = this->demo_stage.getMapTip(1,16);
		DrawFormatString(0, 100, GetColor(0, 0, 255), "LX���W%f:RX���W%f:TY���W%f:BY���W%f",
			map.getCollision().getCurrentXLeft(),
			map.getCollision().getCurrentXRight(),
			map.getCollision().getCurrentYTop(),
			map.getCollision().getCurrentYBottom()
		);
		/*MapTip maptip_debug = this->demo_stage.getMapTip(1,1);
		RectCollision debug_collision2 = maptip_debug.getCollision();
		DrawFormatString(0, 100, GetColor(0, 0, 255), "LX���W%f:RX���W%f:TY���W%f:BY���W%f",
			debug_collision2.getCurrentXLeft(),
			debug_collision2.getCurrentXRight(),
			debug_collision2.getCurrentYTop(),
			debug_collision2.getCurrentYBottom()
		);*/
	}
	

	this->draw.CallScreenFlip();
}


void DemoScene::checkCharacterAndMapForLeftRight()
{
	switch (this->current_stage_id)
	{
		case DemoScene::STAGE_ID_DEMO:
			for (int y = 0; y < DemoStage::Y_SQUARES_NUMBER; ++y) {
				for (int x = 0; x < DemoStage::X_SQUARES_NUMBER; ++x) {
					MapTip map_tip = this->demo_stage.getMapTip(x, y);

					//�v�Z�R�X�g�팸�̂��߁A�J�����͈͊O�͏������Ȃ�
					if (! CollisionService::checkCollisionByRectAndRect(this->main_camera.createRectCollision(), map_tip.getCollision()))
					{
						continue;
					}

					if (map_tip.hasCollision()) {

						this->hero.checkHeroAndMapForLeftRight(map_tip, this->input);

						//�G�̌v�Z�����̃^�C�~���O�ł��Ă������ǂ����m���߂�A�G�̐��͑����ׂɁA�z���foreach���������ǂ����������B
						this->enemy_test1.checkHeroAndMapForLeftRight(map_tip);

					}
				}
			}
			return;
	}

	return;
}

void DemoScene::checkCharacterAndMapForTopBottom()
{
	switch (this->current_stage_id)
	{
		case DemoScene::STAGE_ID_DEMO:
			for (int y = 0; y < DemoStage::Y_SQUARES_NUMBER; ++y) {
				for (int x = 0; x < DemoStage::X_SQUARES_NUMBER; ++x) {
					MapTip map_tip = this->demo_stage.getMapTip(x, y);

					//�v�Z�R�X�g�팸�̂��߁A�J�����͈͊O�͏������Ȃ�
					if (!CollisionService::checkCollisionByRectAndRect(this->main_camera.createRectCollision(), map_tip.getCollision()))
					{
						continue;
					}

					if (map_tip.hasCollision()) {

						this->hero.checkHeroAndMapForTopBottom(map_tip);

						//�G�̌v�Z�����̃^�C�~���O�ł��Ă������ǂ����m���߂�A�G�̐��͑����ׂɁA�z���foreach���������ǂ����������B
						this->enemy_test1.checkHeroAndMapForTopBottom(map_tip);
						

					}
				}
			}
			return;
	}
	return;
}


void DemoScene::checkCameraAndMapForLeftRight()
{
	//���������炭�㉺���E�����ɍs���ƃo�O��̂ŁA�Е����B
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
									float difference = CollisionService::differenceXLeftByRectAndRect(this->main_camera.createRectCollision(), map_tip.getCollision());
									this->main_camera.moveRightX((int)difference);
								}

								if (this->main_camera.isCameraMovedRight()) {
									float difference = CollisionService::differenceXRightByRectAndRect(this->main_camera.createRectCollision(), map_tip.getCollision());
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
						if (CollisionService::checkCollisionByRectAndRect(this->main_camera.createRectCollision(), map_tip.getCollision())) {
							if (isChecked == false) {
								if (this->main_camera.isCameraMovedUp()) {
									float difference = CollisionService::differenceYTopByRectAndRect(this->main_camera.createRectCollision(), map_tip.getCollision());
									this->main_camera.moveDownY((int)difference);
								}

								if (this->main_camera.isCameraMovedDown()) {
									float difference = CollisionService::differenceYBottomByRectAndRect(this->main_camera.createRectCollision(), map_tip.getCollision());
									this->main_camera.moveUpY((int)difference);

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

//�}�b�v�`�b�v�̃��[�v�œ����蔻�肵�Ă��������ǂ��H���[�v�ߖ�(�����̏��Ԍ������ׂ̈ɉ��L�͏�������
void DemoScene::ProcessStage()
{
	switch (this->current_stage_id)
	{
		case DemoScene::STAGE_ID_DEMO:
			for (int y = 0; y < DemoStage::Y_SQUARES_NUMBER; ++y) {
				for (int x = 0; x < DemoStage::X_SQUARES_NUMBER; ++x) {
					MapTip map_tip = this->demo_stage.getMapTip(x, y);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           

					//�`��R�X�g��}����A��ʊO�͕`�悵�Ȃ��B
					if (! CollisionService::checkCollisionByRectAndRect(this->main_camera.createRectCollision(), map_tip.getCollision())) {
						continue;
					}

					//�`�� 
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

void DemoScene::DrawCharacter(IDraw& drawObject)
{
	if (drawObject.isDirectionRight()) {
		this->draw.DrawCharacter(drawObject, this->main_camera);
	} else if (drawObject.isDirectionLeft()) {
		this->draw.DrawTurnCharacter(drawObject, this->main_camera);
	}
}