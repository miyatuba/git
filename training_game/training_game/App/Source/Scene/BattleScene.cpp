#include "BattleScene.h"

BattleScene::BattleScene()
{
	// ファイルから読み込み
	this->player_monster1 = new AllyMonsterEntity();
	std::vector<std::string> player_monster1_wait_image_path_vector = {"Resource/Character/player1.png"};
	this->player_monster1->setBattleWaitImages(player_monster1_wait_image_path_vector);

	this->player_monster2 = new AllyMonsterEntity();
	std::vector<std::string> player_monster2_wait_image_path_vector = {"Resource/Character/test.jpg"};
	this->player_monster2->setBattleWaitImages(player_monster2_wait_image_path_vector);

	this->player_monster3 = new AllyMonsterEntity();
	std::vector<std::string> player_monster3_wait_image_path_vector = { "Resource/Character/test3.png" };
	this->player_monster3->setBattleWaitImages(player_monster3_wait_image_path_vector);

	this->player_monster4 = new AllyMonsterEntity();
	std::vector<std::string> player_monster4_wait_image_path_vector = { "Resource/Character/test4.png" };
	this->player_monster4->setBattleWaitImages(player_monster4_wait_image_path_vector);

	this->player_monster5 = new AllyMonsterEntity();
	std::vector<std::string> player_monster5_wait_image_path_vector = { "Resource/Character/test5.png" };
	this->player_monster5->setBattleWaitImages(player_monster5_wait_image_path_vector);

	this->enemy_monster1 = new EnemyMonsterEntity();
	std::vector<std::string> enemy_monster1_wait_image_path_vector = { "Resource/Character/test3.png" };
	this->enemy_monster1->setBattleWaitImages(enemy_monster1_wait_image_path_vector);

	this->enemy_monster2 = new EnemyMonsterEntity();
	std::vector<std::string> enemy_monster2_wait_image_path_vector = {};
	this->enemy_monster2->setBattleWaitImages(enemy_monster2_wait_image_path_vector);

	this->enemy_monster3 = new EnemyMonsterEntity();
	std::vector<std::string> enemy_monster3_wait_image_path_vector = {};
	this->enemy_monster3->setBattleWaitImages(enemy_monster3_wait_image_path_vector);

	this->enemy_monster4 = new EnemyMonsterEntity();
	std::vector<std::string> enemy_monster4_wait_image_path_vector = {};
	this->enemy_monster4->setBattleWaitImages(enemy_monster4_wait_image_path_vector);

	this->enemy_monster5 = new EnemyMonsterEntity();
	std::vector<std::string> enemy_monster5_wait_image_path_vector = {};
	this->enemy_monster5->setBattleWaitImages(enemy_monster5_wait_image_path_vector);



	this->test2 = Texture(Resource(U"Resource/Character/test.jpg"), TextureDesc::Mipped);

	std::vector<std::string> select_text_vector{ "攻撃", "スキル", "移動"};
	this->select = new SelectEntity(select_text_vector, 20);

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

	const Font font(10);
	this->font = font;
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
		this->player_monster1_x_hosei += 1;
		if (this->player_monster1_x_hosei % 6 == 0) {
			this->player_monster1_x_hosei %= 6;
			this->player_monster1_y_hosei += 1;
			if (this->player_monster1_y_hosei % 6 == 0) {
				this->player_monster1_y_hosei %= 6;
			}

		}
	}
	if (KeyUp.down()) {
		this->select->moveCursorTraianglePositionY(true);
	}
	if (KeyDown.down()) {
		this->select->moveCursorTraianglePositionY(false);
	}
	this->Draw();
}

//そもそも、ここが別クラスに移すべきか。
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

	int initialize_x_position = 200;
	int initialize_y_position = 100;
	int initialize_x_size = 70;
	int initialize_y_size = 70;

	//別クラスに描画処理はそろえた方が良い。
	this->player_monster1->getBattleWaitImage(0).scaled(0.2).draw(205 + (this->player_monster1_x_hosei * initialize_x_size), 90 - 10 + (this->player_monster1_y_hosei * initialize_y_size));
	this->player_monster2->getBattleWaitImage(0).scaled(0.2).draw(205, 90);
	this->select->getCursorTriangleImage().scaled(0.1).draw(this->select->getCursorTrainglePositionX(), this->select->getCursorTrainglePositionY());
	this->DrawSelectOptionTexts();

}

void BattleScene::DrawSelectOptionTexts()
{
	int y = 0;
	for (std::string text : this->select->getSelectOptionTextVector()) {
		this->font(Unicode::Widen(text)).draw(50, y);
		y += this->select->getIntervalSizeY();
	}


}