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
		this->y -= 8;
	}
	if (input.IsInputDown()) {
		this->y += 8;
	}
}

int Hero::getPositionX() const
{
	return this->x;
}

int Hero::getPositionY() const
{
	return this->y;
}

std::string Hero::getImagePath() const
{
	return this->image_path;
}