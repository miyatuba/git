#include "Draw.h"

//namespace�g������H
void Draw::CallClearDrawScreen()
{
	ClearDrawScreen();
}

void Draw::DrawGame(const IDraw& drawObject) {
	int x = drawObject.getPositionX();
	int y = -drawObject.getPositionY(); //DX���C�u�����ł͕\����Y���W���t�ɂȂ邽��
	std::string draw_image_path = drawObject.getImagePath();

	LoadGraphScreen(x, y, draw_image_path.c_str(), TRUE);

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