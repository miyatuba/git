#include "BattleScene.h"

BattleScene::BattleScene()
{
	// ファイルから読み込み
	//this->test1 = Texture(U"example/windmill.png");
	this->test1 = Texture(Resource(U"Resource/Character/test1.png"), TextureDesc::Mipped);
	this->test2 = Texture(Resource(U"Resource/Character/test.jpg"), TextureDesc::Mipped);

	// 埋め込みリソースから読み込み
	//this->test2 = Texture(Resource(U"example/windmill.png"), TextureDesc::Mipped);

	int initialize_x_position = 200;
	int initialize_y_position = 100;
	int initialize_x_size = 70;
	int initialize_y_size = 70;
	this->grid_1_1 = Rect(initialize_x_position + initialize_x_size * 0, initialize_y_position + initialize_y_size * 0, initialize_x_size, initialize_y_size);
	this->grid_2_1 = Rect(initialize_x_position + initialize_x_size * 1, initialize_y_position + initialize_y_size * 0, initialize_x_size, initialize_y_size);
	this->grid_3_1 = Rect(initialize_x_position + initialize_x_size * 2, initialize_y_position + initialize_y_size * 0, initialize_x_size, initialize_y_size);
	this->grid_4_1 = Rect(initialize_x_position + initialize_x_size * 3, initialize_y_position + initialize_y_size * 0, initialize_x_size, initialize_y_size);
	this->grid_5_1 = Rect(initialize_x_position + initialize_x_size * 4, initialize_y_position + initialize_y_size * 0, initialize_x_size, initialize_y_size);
	this->grid_6_1 = Rect(initialize_x_position + initialize_x_size * 5, initialize_y_position + initialize_y_size * 0, initialize_x_size, initialize_y_size);
	this->grid_1_2 = Rect(initialize_x_position + initialize_x_size * 0, initialize_y_position + initialize_y_size * 1, initialize_x_size, initialize_y_size);
	this->grid_2_2 = Rect(initialize_x_position + initialize_x_size * 1, initialize_y_position + initialize_y_size * 1, initialize_x_size, initialize_y_size);
	this->grid_3_2 = Rect(initialize_x_position + initialize_x_size * 2, initialize_y_position + initialize_y_size * 1, initialize_x_size, initialize_y_size);
	this->grid_4_2 = Rect(initialize_x_position + initialize_x_size * 3, initialize_y_position + initialize_y_size * 1, initialize_x_size, initialize_y_size);
	this->grid_5_2 = Rect(initialize_x_position + initialize_x_size * 4, initialize_y_position + initialize_y_size * 1, initialize_x_size, initialize_y_size);
	this->grid_6_2 = Rect(initialize_x_position + initialize_x_size * 5, initialize_y_position + initialize_y_size * 1, initialize_x_size, initialize_y_size);
	this->grid_1_3 = Rect(initialize_x_position + initialize_x_size * 0, initialize_y_position + initialize_y_size * 2, initialize_x_size, initialize_y_size);
	this->grid_2_3 = Rect(initialize_x_position + initialize_x_size * 1, initialize_y_position + initialize_y_size * 2, initialize_x_size, initialize_y_size);
	this->grid_3_3 = Rect(initialize_x_position + initialize_x_size * 2, initialize_y_position + initialize_y_size * 2, initialize_x_size, initialize_y_size);
	this->grid_4_3 = Rect(initialize_x_position + initialize_x_size * 3, initialize_y_position + initialize_y_size * 2, initialize_x_size, initialize_y_size);
	this->grid_5_3 = Rect(initialize_x_position + initialize_x_size * 4, initialize_y_position + initialize_y_size * 2, initialize_x_size, initialize_y_size);
	this->grid_6_3 = Rect(initialize_x_position + initialize_x_size * 5, initialize_y_position + initialize_y_size * 2, initialize_x_size, initialize_y_size);
	this->grid_1_4 = Rect(initialize_x_position + initialize_x_size * 0, initialize_y_position + initialize_y_size * 3, initialize_x_size, initialize_y_size);
	this->grid_2_4 = Rect(initialize_x_position + initialize_x_size * 1, initialize_y_position + initialize_y_size * 3, initialize_x_size, initialize_y_size);
	this->grid_3_4 = Rect(initialize_x_position + initialize_x_size * 2, initialize_y_position + initialize_y_size * 3, initialize_x_size, initialize_y_size);
	this->grid_4_4 = Rect(initialize_x_position + initialize_x_size * 3, initialize_y_position + initialize_y_size * 3, initialize_x_size, initialize_y_size);
	this->grid_5_4 = Rect(initialize_x_position + initialize_x_size * 4, initialize_y_position + initialize_y_size * 3, initialize_x_size, initialize_y_size);
	this->grid_6_4 = Rect(initialize_x_position + initialize_x_size * 5, initialize_y_position + initialize_y_size * 3, initialize_x_size, initialize_y_size);
	this->grid_1_5 = Rect(initialize_x_position + initialize_x_size * 0, initialize_y_position + initialize_y_size * 4, initialize_x_size, initialize_y_size);
	this->grid_2_5 = Rect(initialize_x_position + initialize_x_size * 1, initialize_y_position + initialize_y_size * 4, initialize_x_size, initialize_y_size);
	this->grid_3_5 = Rect(initialize_x_position + initialize_x_size * 2, initialize_y_position + initialize_y_size * 4, initialize_x_size, initialize_y_size);
	this->grid_4_5 = Rect(initialize_x_position + initialize_x_size * 3, initialize_y_position + initialize_y_size * 4, initialize_x_size, initialize_y_size);
	this->grid_5_5 = Rect(initialize_x_position + initialize_x_size * 4, initialize_y_position + initialize_y_size * 4, initialize_x_size, initialize_y_size);
	this->grid_6_5 = Rect(initialize_x_position + initialize_x_size * 5, initialize_y_position + initialize_y_size * 4, initialize_x_size, initialize_y_size);
	this->grid_1_6 = Rect(initialize_x_position + initialize_x_size * 0, initialize_y_position + initialize_y_size * 5, initialize_x_size, initialize_y_size);
	this->grid_2_6 = Rect(initialize_x_position + initialize_x_size * 1, initialize_y_position + initialize_y_size * 5, initialize_x_size, initialize_y_size);
	this->grid_3_6 = Rect(initialize_x_position + initialize_x_size * 2, initialize_y_position + initialize_y_size * 5, initialize_x_size, initialize_y_size);
	this->grid_4_6 = Rect(initialize_x_position + initialize_x_size * 3, initialize_y_position + initialize_y_size * 5, initialize_x_size, initialize_y_size);
	this->grid_5_6 = Rect(initialize_x_position + initialize_x_size * 4, initialize_y_position + initialize_y_size * 5, initialize_x_size, initialize_y_size);
	this->grid_6_6 = Rect(initialize_x_position + initialize_x_size * 5, initialize_y_position + initialize_y_size * 5, initialize_x_size, initialize_y_size);
}

void BattleScene::Initialize()
{

}

void BattleScene::Finalize()
{

}

void BattleScene::Update()
{
	if (MouseL.down()) {
	}
	this->Draw();
}

void BattleScene::Draw()
{
	this->grid_1_1.drawFrame(2, 0, Palette::Red);
	this->grid_2_1.drawFrame(2, 0, Palette::Red);
	this->grid_3_1.drawFrame(2, 0, Palette::Red);
	this->grid_4_1.drawFrame(2, 0, Palette::Red);
	this->grid_5_1.drawFrame(2, 0, Palette::Red);
	this->grid_6_1.drawFrame(2, 0, Palette::Red);
	this->grid_1_2.drawFrame(2, 0, Palette::Red);
	this->grid_2_2.drawFrame(2, 0, Palette::Red);
	this->grid_3_2.drawFrame(2, 0, Palette::Red);
	this->grid_4_2.drawFrame(2, 0, Palette::Red);
	this->grid_5_2.drawFrame(2, 0, Palette::Red);
	this->grid_6_2.drawFrame(2, 0, Palette::Red);
	this->grid_1_3.drawFrame(2, 0, Palette::Red);
	this->grid_2_3.drawFrame(2, 0, Palette::Red);
	this->grid_3_3.drawFrame(2, 0, Palette::Red);
	this->grid_4_3.drawFrame(2, 0, Palette::Red);
	this->grid_5_3.drawFrame(2, 0, Palette::Red);
	this->grid_6_3.drawFrame(2, 0, Palette::Red);
	this->grid_1_4.drawFrame(2, 0, Palette::Red);
	this->grid_2_4.drawFrame(2, 0, Palette::Red);
	this->grid_3_4.drawFrame(2, 0, Palette::Red);
	this->grid_4_4.drawFrame(2, 0, Palette::Red);
	this->grid_5_4.drawFrame(2, 0, Palette::Red);
	this->grid_6_4.drawFrame(2, 0, Palette::Red);
	this->grid_1_5.drawFrame(2, 0, Palette::Red);
	this->grid_2_5.drawFrame(2, 0, Palette::Red);
	this->grid_3_5.drawFrame(2, 0, Palette::Red);
	this->grid_4_5.drawFrame(2, 0, Palette::Red);
	this->grid_5_5.drawFrame(2, 0, Palette::Red);
	this->grid_6_5.drawFrame(2, 0, Palette::Red);
	this->grid_1_6.drawFrame(2, 0, Palette::Red);
	this->grid_2_6.drawFrame(2, 0, Palette::Red);
	this->grid_3_6.drawFrame(2, 0, Palette::Red);
	this->grid_4_6.drawFrame(2, 0, Palette::Red);
	this->grid_5_6.drawFrame(2, 0, Palette::Red);
	this->grid_6_6.drawFrame(2, 0, Palette::Red);

	this->test1.scaled(0.2).draw(0, 0);

	this->test2.scaled(0.2).draw(0, 320);
}