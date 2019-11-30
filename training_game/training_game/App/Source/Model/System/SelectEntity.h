#pragma once
#include <Siv3D.hpp> // OpenSiv3D v0.4.0
#include <string.h>
#include <initializer_list>

class SelectEntity
{
private:
	Texture cursor_triangle = Texture(Resource(U"Resource/Common/select_triangle.png"));
	int cursor_triangle_position_x = 0;
	int cursor_triangle_position_y = 0;
	std::vector<std::string> select_option_text_vector;
	int selected_id = 0;

	int interval_size_y = 0;
public:
	SelectEntity(std::vector<std::string> select_option_text_vector, int font_size);
	Texture getCursorTriangleImage();
	int getCursorTrainglePositionX();
	int getCursorTrainglePositionY();
	void setCursorTraianglePositionX(int x);
	void setCursorTraianglePositionY(int y);
	std::vector<std::string> getSelectOptionTextVector();
	void moveCursorTraianglePositionY(bool isUp);

	int getIntervalSizeY();
};