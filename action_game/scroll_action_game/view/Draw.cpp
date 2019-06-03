#include "Draw.h"

//namespace�g������H
void Draw::CallClearDrawScreen()
{
	ClearDrawScreen();
}

void Draw::DrawGame(const IDraw& drawObject) {
	int x = drawObject.getPositionX();
	int y = -drawObject.getPositionY(); //DX���C�u�����ł͕\����Y���W���t�ɂȂ邽��
	int draw_image_handle = drawObject.getImageHandle();

	//�^�u�[����https://dixq.net/g/h_11.html
	//���L�̊֐��͏d���ׂɃf�o�b�O�ȊO�Ŏg�p����ׂ��ł͂Ȃ��炵��LoadGraph��DrawGraph���g�p���鏈���ɕς��悤
	DrawGraph(x, y, draw_image_handle, TRUE);

}

void Draw::StageDraw(MapTip& map, int x, int y)
{
	int map_handol = map.getMapTipHandol();
	DrawGraph(x * BaseStage::DIVIDED_MAP_TIP_X_SIZE, y * BaseStage::DIVIDED_MAP_TIP_Y_SIZE, map_handol, FALSE);
}

//namespace�g������H
void Draw::CallScreenFlip()
{
	ScreenFlip();
}