#include "Draw.h"

//namespace使ったら？
void Draw::CallClearDrawScreen()
{
	ClearDrawScreen();
}

void Draw::DrawGame(const IDraw& drawObject) {
	int hero_x = drawObject.getPositionX();
	int hero_y = drawObject.getPositionY();
	std::string draw_image_path = drawObject.getImagePath();

	LoadGraphScreen(hero_x, hero_y, draw_image_path.c_str(), TRUE);

}

void Draw::StageDraw(MapTip& map, int x, int y)
{
	int map_handol = map.getMapTipHandol();
	DrawGraph(x * BaseStage::DIVIDED_MAP_TIP_X_SIZE, y * BaseStage::DIVIDED_MAP_TIP_Y_SIZE, map_handol, FALSE);
}

//namespace使ったら？
void Draw::CallScreenFlip()
{
	ScreenFlip();
}