#include "SelectEntity.h"


SelectEntity::SelectEntity(std::vector<int> select_id_vector, int interval_size_y)
{
	this->select_id_vector = select_id_vector;

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
	//ここに、選択しのindexの情報も切り替える。
	if (isUp) {
		this->cursor_triangle_position_y += this->interval_size_y * (this->select_id_vector.size() - 1);
		this->selected_id += this->select_id_vector.size() - 1;
	}
	else {
		this->cursor_triangle_position_y += this->interval_size_y;
		this->selected_id += 1;
	}

	if (this->cursor_triangle_position_y >= this->select_id_vector.size() * this->interval_size_y) {
		this->cursor_triangle_position_y %= this->select_id_vector.size() * this->interval_size_y;
		this->selected_id %= this->select_id_vector.size();
	}
	/*if (this->selected_id >= this->select_option_text_vector.size()) {
		
	}*/

}

//多分使わない
void SelectEntity::setCursorTraianglePositionY(int y)
{
	this->cursor_triangle_position_y = y;

}

std::vector<int> SelectEntity::getIdList()
{
	return this->select_id_vector;
}



int SelectEntity::getIntervalSizeY()
{
	return this->interval_size_y;
}