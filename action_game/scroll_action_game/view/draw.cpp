#include "Draw.h"

void Draw::GameDraw(const IDraw& drawObject) {
	ClearDrawScreen();
	int hero_x = drawObject.getPositionX();
	int hero_y = drawObject.getPositionY();
	std::string draw_image_path = drawObject.getImagePath();

	LoadGraphScreen(hero_x, hero_y, draw_image_path.c_str(), TRUE);
	ScreenFlip();

	//WaitTimer(20);

}