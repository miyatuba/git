#include "Draw.h"

//namespace使ったら？
void Draw::CallClearDrawScreen()
{
	ClearDrawScreen();
}

void Draw::DrawCharacter(IDraw& drawObject, MainCamera main_camera) 
{
	int x = drawObject.getPositionX() - main_camera.MovingDistanceX();
	int y = -(drawObject.getPositionY() - main_camera.MovingDistanceY()); //DXライブラリでは表示のY座標が逆になるため
	int draw_image_handle = drawObject.getImageHandle();

	int result = DrawGraph(x, y, draw_image_handle, TRUE);
	if (result == -1) {
		std::string message = "Characterの描画失敗";
		throw message;
	}
}

void Draw::DrawTurnCharacter(IDraw& drawObject, MainCamera main_camera)
{
	int x = drawObject.getPositionX() - main_camera.MovingDistanceX();
	int y = -(drawObject.getPositionY() - main_camera.MovingDistanceY());
	int draw_image_handle = drawObject.getImageHandle();

	int result = DrawTurnGraph(x, y, draw_image_handle, TRUE);
	if (result == -1) {
		std::string message = "CharacterTurnの描画失敗";
		throw message;
	}
}

void Draw::StageDraw(MapTip& map, int x, int y, MainCamera main_camera)
{
	int map_handol = map.getMapTipHandol();
	int position_x = (x * BaseStage::DIVIDED_MAP_TIP_X_SIZE) - main_camera.MovingDistanceX();
	int position_y = (y * BaseStage::DIVIDED_MAP_TIP_Y_SIZE) + main_camera.MovingDistanceY();//DXライブラリでは上から下に向かって正の加算であるため
	
	int result = DrawGraph(position_x, position_y, map_handol, FALSE);
	if (result == -1) {
		std::string message = "maptipの描画失敗";
		throw message;
	}
}

//namespace使ったら？
void Draw::CallScreenFlip()
{
	ScreenFlip();
}