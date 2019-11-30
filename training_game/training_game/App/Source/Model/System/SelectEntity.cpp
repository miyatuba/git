#include "SelectEntity.h"


SelectEntity::SelectEntity(std::vector<std::string> select_option_text_vector, int interval_size_y)
{
	this->select_option_text_vector = select_option_text_vector;

	this->interval_size_y = interval_size_y;
}

Texture SelectEntity::getCursorTriangleImage()
{
	return this->cursor_triangle;
}

int SelectEntity::getCursorTrainglePositionX()
{
	return this->cursor_triangle_position_x;
}

int SelectEntity::getCursorTrainglePositionY()
{
	return this->cursor_triangle_position_y;
}

//多分使わない
void SelectEntity::setCursorTraianglePositionX(int x)
{
	this->cursor_triangle_position_x = x;
}

void SelectEntity::moveCursorTraianglePositionY(bool isUp)
{
	if (isUp) {
		this->cursor_triangle_position_y += this->interval_size_y * (this->select_option_text_vector.size() - 1);
	}
	else {
		this->cursor_triangle_position_y += this->interval_size_y;
	}

	if (this->cursor_triangle_position_y >= this->select_option_text_vector.size() * this->interval_size_y) {
		this->cursor_triangle_position_y %= this->select_option_text_vector.size() * this->interval_size_y;
	}
}

//多分使わない
void SelectEntity::setCursorTraianglePositionY(int y)
{
	this->cursor_triangle_position_y = y;

}

//多分、もっと別のメソッドを作ると思う
std::vector<std::string> SelectEntity::getSelectOptionTextVector()
{
	return this->select_option_text_vector;
}

int SelectEntity::getIntervalSizeY()
{
	return this->interval_size_y;
}