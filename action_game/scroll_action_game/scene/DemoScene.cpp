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

void DemoScene::Play()
{
	this->initLoopDemoScene();
	BaseScene::Play();
	//���͗p�f�o�b�O�w�肵���L�[�݂̂Ńu���[�N�������Ƃ���
	if (DebugMode::isDebugMode()) {
		if ((this->input.IsInputUp()) && (this->input.IsInputRight())) {
			int a = 1;
		}
	}

	//�����ɃL�[�ő���ł���J������������Ă݂�
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

	//�v���C���[�̍U��

	//�v���C���[�̈ړ��A���E
	this->hero.MovePositionByInput(this->input);

	//�v���C���[�ƃ}�b�v�̔���ŁA�v���C���[�̉\�ȏ�Ԃ𐮗��A���E�ړ��i����A��ʓ��݂̂ɕς���
	this->checkPlayerAndMapForLeftRight();

	//�v���C���[�̈ړ��A�㉺
	this->hero.MoveNoInput();

	//�v���C���[�ƃ}�b�v�̔���ŁA�v���C���[�̉\�ȏ�Ԃ𐮗��A�㉺�ړ��i����A��ʓ��݂̂ɕς���
	this->checkPlayerAndMapForTopBottom();

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

	//�X�e�[�W�̕`��i��ʂɉf����̂����ɂ�����
	this->ProcessStage();


	//�q�[���[��G�̕`��
	this->draw.DrawGame(this->hero, this->main_camera);

	if (DebugMode::isDebugMode()) {
		CollisionService::drawCollisionByRect(this->hero.getCollision(), 0, 255, 0, this->main_camera);
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


void DemoScene::checkPlayerAndMapForLeftRight()
{
	switch (this->current_stage_id)
	{
		case DemoScene::STAGE_ID_DEMO:
			for (int y = 0; y < DemoStage::Y_SQUARES_NUMBER; ++y) {
				for (int x = 0; x < DemoStage::X_SQUARES_NUMBER; ++x) {
					MapTip map_tip = this->demo_stage.getMapTip(x, y);
					/*RectCollision heroRectCollision = this->hero.getCollision();
					RectCollision HeroCalculationRectCollision(float x_left, float x_right, float y_top, float y_bottom);*/
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

						//�������ꂩ�ǂ����m�F
						if (!this->is_checked_scaffold_for_hero) {
							RectCollision expected_rect_collision = this->hero.getCollision();
							expected_rect_collision.moveCollisionY(-1);
							if (!CollisionService::checkCollisionByRectAndRect(expected_rect_collision, map_tip.getCollision())) {
								this->hero.OnFallStatus();//��������Ǝv��
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

//�}�b�v�`�b�v�̃��[�v�œ����蔻�肵�Ă��������ǂ��H���[�v�ߖ�(�����̏��Ԍ������ׂ̈ɉ��L�͏�������
void DemoScene::ProcessStage()
{
	switch (this->current_stage_id)
	{
		case DemoScene::STAGE_ID_DEMO:
			//�X�e�[�W�̃J��������̏㉺���E���E�������Ŕ��f����񂾂낤���A���L�͕`�揈�����܂ނ��߂ɁA�����Ȃ��Ă͂Ȃ�Ȃ��A
			//�ēx���[�v���񂷂͔̂@���Ȃ��̂��E�E
			for (int y = 0; y < DemoStage::Y_SQUARES_NUMBER; ++y) {
				for (int x = 0; x < DemoStage::X_SQUARES_NUMBER; ++x) {
					MapTip map_tip = this->demo_stage.getMapTip(x, y);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
					/*if (map_tip.hasCollision()) {
						//��l���ƃ}�b�v�`�b�v�̓����蔻��
						this->checkCollisionByHeroAndMapTip(this->hero, map_tip);

					}*/

					//��ʊO���ǂ����̃`�F�b�N
					/*if (!map_tip.hasMapTipHandle()) {
						//��ʊO���ǂ����̔���
						RectCollision a = this->main_camera.createRectCollision();
						RectCollision b = map_tip.getCollision();
						if (CollisionService::checkCollisionByRectAndRect(this->main_camera.createRectCollision(), map_tip.getCollision())) {
							//�������v�Z���ē����A��ʊO���ʃ��~�b�g�̃}�b�v�`�b�v����ʓ��ɂ���ꍇ�̑z��͕ۏ؂��Ȃ�

							//���ɂ���Ă��邩�i�����Ɋm�F���邽�߂ɁA���l�ł������ꍇ�͉E�ɗD��I�ɂ��炷���ƂɂȂ�B
							//1�FA�̉E��B�̍��̍�����A�̍���B�̉E�̍������r���O�҂��傫����΁A
							//A�̉E��B�̉E�̍�����B�̉E��A�̍��̍������r���O�҂��傫�����
							//A��A�̍���B�̉E�̍����������ɂ���Ă���

							//2�FA�̉E��B�̍��̍�����A�̍���B�̉E�̍������r���O�҂��傫����΁A
							//A�̉E��B�̉E�̍�����B�̉E��A�̍��̍������r����҂��傫�����
							//A��A�̍���B�̉E�̍����������ɂ���Ă���

							//3�FA�̉E��B�̍��̍�����A�̍���B�̉E�̍������r�����l�ł���΁A
							//A�̉E��B�̉E�A��������A�̍���B�̍����ׂđO�҂��傫����΁A
							//A��A�̍���B�̉E�̍����������ɂ���Ă���

							//�T�C�Y��A<B�̃^�C�v���ɋN���肤��p�^�[��
							//B�̍�<A�̉E<B�̉E�̏ꍇ�i���Α�������K�v�͂Ȃ�
							//B�̐^�񒆂�A�̐^�񒆂��ׂ�A�̐^�񒆂̕����傫��
							//A��A�̍���B�̉E�̍����������ɂ���Ă���
							//����͎������Ȃ��Ă����C������

							//�T�C�Y��A>B�̃^�C�v���ɋN���肤��p�^�[��
							//A�̍�<B�̉E<A�̉E�̏ꍇ�i���Α�������K�v�͂Ȃ�
							//B�̐^�񒆂�A�̐^�񒆂��ׂ�A�̐^�񒆂̕����傫��
							//A��A�̍���B�̉E�̍����������ɂ���Ă���
							//����͎������Ȃ��Ă����C������

							if (CollisionService::checkCollisionUpAndDownByRectandRect(this->main_camera.createBeforeRectCollision(), map_tip.getCollision())) {
								float difference = CollisionService::differenceXLeftByRectandRect(this->main_camera.createRectCollision(), map_tip.getCollision());
								//this->main_camera.moveRightX((int)difference);
							}

							if (CollisionService::checkCollisionLeftAndRightByRectandRect(this->main_camera.createBeforeRectCollision(), map_tip.getCollision())) {
								float difference = CollisionService::differenceYBottomByRectandRect(this->main_camera.createRectCollision(), map_tip.getCollision());
								//this->main_camera.moveUpY((int)difference);
							}
							
							
							


							//�E�ɂ���Ă��邩
							//1�FA�̉E��B�̍��̍�����A�̍���B�̉E�̍������r����҂��傫����΁A
							//A�̍���B�̍��̍�����B�̍���A�̉E�̍������r���O�҂��傫�����
							//A��A�̉E��B�̍��̍��������E�ɂ���Ă���

							//2�FA�̉E��B�̍��̍�����A�̍���B�̉E�̍������r����҂��傫����΁A
							//A�̍���B�̍��̍�����B�̍���A�̉E�̍������r����҂��傫�����
							//A��A�̉E��B�̍��̍��������E�ɂ���Ă���

							//3�FA�̉E��B�̍��̍�����A�̍���B�̉E�̍������r�����l�ł���΁A
							//A�̉E��B�̉E�A��������A�̍���B�̍����ׂČ�҂��傫����΁A
							//A��A�̉E��B�̍��̍��������E�ɂ���Ă���
							//���ꂾ���͖�����B�ʂŔ����o��

							//�T�C�Y��A<B�̃^�C�v���ɋN���肤��p�^�[��
							//B�̍�<A�̍�<B�̉E�̏ꍇ�i���Α�������K�v�͂Ȃ�
							//B�̐^�񒆂�A�̐^�񒆂��ׂ�B�̐^�񒆂̕����傫��
							//A��A�̉E��B�̍��̍��������E�ɂ���Ă���
							//����͎������Ȃ��Ă����C������

							//�T�C�Y��A>B�̃^�C�v���ɋN���肤��p�^�[��
							//A�̍�<B�̍�<A�̉E�̏ꍇ�i���Α�������K�v�͂Ȃ�
							//B�̐^�񒆂�A�̐^�񒆂��ׂ�B�̐^�񒆂̕����傫��
							//A��A�̉E��B�̍��̍��������E�ɂ���Ă���
							//����͎������Ȃ��Ă����C������

							if (CollisionService::checkShiftedToRightByRectandRect(this->main_camera.createRectCollision(), map_tip.getCollision())) {
								float difference_shifted_to_right = CollisionService::differenceXRightByRectandRect(this->main_camera.createRectCollision(), map_tip.getCollision());
								this->main_camera.moveLeftX((int) difference_shifted_to_right);
							}

							//�㉺�̔���

							//���ɂ���Ă��邩�i�����Ɋm�F���邽�߂ɁA���l�ł������ꍇ�͏�ɗD��I�ɂ��炷���ƂɂȂ�B
							//1�FA�̏��B�̉��̍�����A�̉���B�̏�̍������r���O�҂��傫����΁A
							//A�̏��B�̏�̍�����B�̏��A�̉��̍������r���O�҂��傫�����
							//A��A�̉���B�̏�̍����������ɂ���Ă���

							//2�FA�̏��B�̉��̍�����A�̉���B�̏�̍������r���O�҂��傫����΁A
							//A�̏��B�̏�̍�����B�̏��A�̉��̍������r����҂��傫�����
							//A��A�̉���B�̏�̍����������ɂ���Ă���

							//3�FA�̏��B�̉��̍�����A�̉���B�̏�̍������r�����l�ł���΁A
							//A�̏��B�̏�A��������A�̉���B�̉����ׂđO�҂��傫����΁A
							//A��A�̉���B�̏�̍����������ɂ���Ă���

							//�T�C�Y��A<B�̃^�C�v���ɋN���肤��p�^�[��
							//B�̉�<A�̏�<B�̏�̏ꍇ�i���Α�������K�v�͂Ȃ�
							//B�̐^�񒆂�A�̐^�񒆂��ׂ�A�̐^�񒆂̕����傫��
							//A��A�̉���B�̏�̍����������ɂ���Ă���

							//�T�C�Y��A>B�̃^�C�v���ɋN���肤��p�^�[��
							//A�̉�<B�̏�<A�̏�̏ꍇ�i���Α�������K�v�͂Ȃ�
							//B�̐^�񒆂�A�̐^�񒆂��ׂ�A�̐^�񒆂̕����傫��
							//A��A�̉���B�̏�̍����������ɂ���Ă���

							if (CollisionService::checkShiftedToBottomByRectandRect(map_tip.getCollision(), this->main_camera.createRectCollision())) {
								float difference_shifted_to_bottom = CollisionService::differenceYBottomByRectandRect(map_tip.getCollision(), this->main_camera.createRectCollision());
								this->main_camera.moveUpY((int) difference_shifted_to_bottom);
							}


							//��ɂ���Ă��邩
							//1�FA�̏��B�̉��̍�����A�̉���B�̏�̍������r����҂��傫����΁A
							//A�̉���B�̉��̍�����B�̉���A�̏�̍������r���O�҂��傫�����
							//A��A�̏��B�̉��̍���������ɂ���Ă���

							//2�FA�̏��B�̉��̍�����A�̉���B�̏�̍������r����҂��傫����΁A
							//A�̉���B�̉��̍�����B�̉���A�̏�̍������r����҂��傫�����
							//A��A�̏��B�̉��̍���������ɂ���Ă���

							//3�FA�̏��B�̉��̍�����A�̉���B�̏�̍������r�����l�ł���΁A
							//A�̏��B�̏�A��������A�̉���B�̉����ׂČ�҂��傫����΁A
							//A��A�̏��B�̉��̍���������ɂ���Ă���

							//�T�C�Y��A<B�̃^�C�v���ɋN���肤��p�^�[��
							//B�̉�<A�̉�<B�̏�̏ꍇ�i���Α�������K�v�͂Ȃ�
							//B�̐^�񒆂�A�̐^�񒆂��ׂ�B�̐^�񒆂̕����傫��
							//A��A�̏��B�̉��̍���������ɂ���Ă���

							//�T�C�Y��A>B�̃^�C�v���ɋN���肤��p�^�[��
							//A�̉�<B�̉�<A�̏�̏ꍇ�i���Α�������K�v�͂Ȃ�
							//B�̐^�񒆂�A�̐^�񒆂��ׂ�B�̐^�񒆂̕����傫��
							//A��A�̏��B�̉��̍���������ɂ���Ă���
							if (CollisionService::checkShiftedToTopByRectandRect(this->main_camera.createRectCollision(), map_tip.getCollision())) {
								float difference_shifted_to_top = CollisionService::differenceYTopByRectandRect(this->main_camera.createRectCollision(), map_tip.getCollision());
								this->main_camera.moveDownY((int) difference_shifted_to_top);
							}
						}

					}*/

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

void DemoScene::checkCollisionByHeroAndMapTip(Hero& hero, MapTip map_tip)
{
	//���͏󋵂ɉ�������@���Ƃ��Ă݂��A����ł��܂������Ȃ���΁A���͏󋵂ɂ��A�}�b�v�`�b�v�̏����̏��Ԃ�����or�E���A�㏇or�����̐؂�ւ������v�����Ȃ�
	//��L�̕��@���ƁA�v���C���[�ȊO�̃L�������ړ�����ꍇ�ɋl��
	if (CollisionService::checkCollisionByRectAndRect(hero.getCollision(), map_tip.getCollision())) {
		
		if (hero.isFall()) {
		//if (this->input.IsInputDown()){
			if (!CollisionService::checkCollisionLeftAndRightByRectandRect(hero.getBeforeMovingRectCollision(), map_tip.getCollision()) &&
				(this->input.IsInputLeft() || this->input.IsInputRight())) {
			}
			else {
				float difference = CollisionService::differenceYBottomByRectandRect(hero.getCollision(), map_tip.getCollision());
				hero.MoveUp((int)difference);
			}
			
		}

		if (hero.isJump()) {
		//if (this->input.IsInputUp()) {
			if (! CollisionService::checkCollisionLeftAndRightByRectandRect(hero.getBeforeMovingRectCollision(), map_tip.getCollision()) &&
				(this->input.IsInputLeft() || this->input.IsInputRight())) {
			}else {
				float difference = CollisionService::differenceYTopByRectandRect(hero.getCollision(), map_tip.getCollision());
				hero.MoveDown((int)difference);
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
		if (!CollisionService::checkCollisionByRectAndRect(expected_rect_collision, map_tip.getCollision())) {
			hero.OnFallStatus();//��������Ǝv��
		}
		else {
			hero.OffFallStatus();
			this->is_checked_scaffold_for_hero = true;
		}
		expected_rect_collision.moveCollisionY(1);
		
	}

}