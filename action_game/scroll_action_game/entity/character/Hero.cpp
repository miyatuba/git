#include "Hero.h"

Hero::Hero() {

}

void Hero::MovePositionByInput(Input input)
{
	if (input.IsInputLeft()) {
		this->x -= 8;
	}
	if (input.IsInputRight()) {
		this->x += 8;
	}
	if (input.IsInputUp()) {
		this->y += 8;
	}
	if (input.IsInputDown()) {
		this->y -= 8;
	}
}

int Hero::getPositionX()
{
	return this->x;
}

int Hero::getPositionY()
{
	return this->y;
}

std::string Hero::getImagePath()
{
	return this->image_path;
}