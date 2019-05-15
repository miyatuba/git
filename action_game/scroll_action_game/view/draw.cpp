#include "Draw.h"


void Draw::GameDraw(Hero hero) {
	ClearDrawScreen();
	int hero_x = hero.getPositionX();
	int hero_y = hero.getPositionY();
	std::string hero_image_path = hero.getImagePath();

	LoadGraphScreen(hero_x, hero_y, hero_image_path.c_str(), TRUE);
	ScreenFlip();

	WaitTimer(20);

}