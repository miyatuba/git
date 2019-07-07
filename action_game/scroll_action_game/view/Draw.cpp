#include "Draw.h"

//namespaceg‚Á‚½‚çH
void Draw::CallClearDrawScreen()
{
	ClearDrawScreen();
}

void Draw::DrawCharacter(const IDraw& drawObject, MainCamera main_camera) 
{
	int x = drawObject.getPositionX() - main_camera.MovingDistanceX();
	int y = -(drawObject.getPositionY() - main_camera.MovingDistanceY()); //DXƒ‰ƒCƒuƒ‰ƒŠ‚Å‚Í•\¦‚ÌYÀ•W‚ª‹t‚É‚È‚é‚½‚ß
	int draw_image_handle = drawObject.getImageHandle();

	int result = DrawGraph(x, y, draw_image_handle, TRUE);
	if (result == -1) {
		std::string message = "Character‚Ì•`‰æ¸”s";
		throw message;
	}
}

void Draw::DrawTurnCharacter(const IDraw& drawObject, MainCamera main_camera)
{
	int x = drawObject.getPositionX() - main_camera.MovingDistanceX();
	int y = -(drawObject.getPositionY() - main_camera.MovingDistanceY());
	int draw_image_handle = drawObject.getImageHandle();

	int result = DrawTurnGraph(x, y, draw_image_handle, TRUE);
	if (result == -1) {
		std::string message = "CharacterTurn‚Ì•`‰æ¸”s";
		throw message;
	}
}

void Draw::StageDraw(MapTip& map, int x, int y, MainCamera main_camera)
{
	int map_handol = map.getMapTipHandol();
	int position_x = (x * BaseStage::DIVIDED_MAP_TIP_X_SIZE) - main_camera.MovingDistanceX();
	int position_y = (y * BaseStage::DIVIDED_MAP_TIP_Y_SIZE) + main_camera.MovingDistanceY();//DXƒ‰ƒCƒuƒ‰ƒŠ‚Å‚Íã‚©‚ç‰º‚ÉŒü‚©‚Á‚Ä³‚Ì‰ÁZ‚Å‚ ‚é‚½‚ß
	
	int result = DrawGraph(position_x, position_y, map_handol, FALSE);
	if (result == -1) {
		std::string message = "maptip‚Ì•`‰æ¸”s";
		throw message;
	}
}

//namespaceg‚Á‚½‚çH
void Draw::CallScreenFlip()
{
	ScreenFlip();
}