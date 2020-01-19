#pragma once
#include <Siv3D.hpp> // OpenSiv3D v0.4.0
#include <initializer_list>

class SelectEntity
{
private:
	Texture cursor_triangle = Texture(Resource(U"Resource/Common/select_triangle.png"));
	int cursor_triangle_position_x = 0;
	int cursor_triangle_position_y = 0;
	std::vector<int> select_id_vector;

	int selected_id = 0;

	int interval_size_y = 0;

	int selected_number = 0;
public:
	SelectEntity(std::vector<int> select_id_vector, int font_size);
	Texture getCursorTriangleImage();
	int getCursorTrainglePositionX();
	int getCursorTrainglePositionY();
	void setCursorTraianglePositionX(int x);
	void setCursorTraianglePositionY(int y);
	void moveCursorTraianglePositionY(bool isUp);
	std::vector<int> getIdList();

	int getIntervalSizeY();
};