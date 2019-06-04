#include "Draw.h"

//namespace使ったら？
void Draw::CallClearDrawScreen()
{
	ClearDrawScreen();
}

void Draw::DrawGame(const IDraw& drawObject, MainCamera main_camera) {
	int x = drawObject.getPositionX() - main_camera.MovingDistanceX();
	int y = -(drawObject.getPositionY() + main_camera.MovingDistanceY()); //DXライブラリでは表示のY座標が逆になるため
	int draw_image_handle = drawObject.getImageHandle();

	//タブーメモhttps://dixq.net/g/h_11.html
	//下記の関数は重い為にデバッグ以外で使用するべきではないらしいLoadGraphとDrawGraphを使用する処理に変えよう
	DrawGraph(x, y, draw_image_handle, TRUE);

}

void Draw::StageDraw(MapTip& map, int x, int y, MainCamera main_camera)
{
	int map_handol = map.getMapTipHandol();
	int position_x = (x * BaseStage::DIVIDED_MAP_TIP_X_SIZE) - main_camera.MovingDistanceX();
	int position_y = (y * BaseStage::DIVIDED_MAP_TIP_Y_SIZE) - main_camera.MovingDistanceY();
	DrawGraph(position_x, position_y, map_handol, FALSE);
}

//namespace使ったら？
void Draw::CallScreenFlip()
{
	ScreenFlip();
}