#pragma once
#include <Siv3D.hpp> // OpenSiv3D v0.4.0
#include "BaseScene.h"
#include "../Model/Monster/AllyMonsterEntity.h"
#include "../Model/Monster/EnemyMonsterEntity.h"
#include "../Model/System/SelectEntity.h"
#include "../Type/BattleCommandType.h"
#include <string.h>
#include <initializer_list>

class BattleScene : public BaseScene
{
private:
	Rect grid_1_1;
	Rect grid_2_1;
	Rect grid_3_1;
	Rect grid_4_1;
	Rect grid_5_1;
	Rect grid_6_1;
	Rect grid_1_2;
	Rect grid_2_2;
	Rect grid_3_2;
	Rect grid_4_2;
	Rect grid_5_2;
	Rect grid_6_2;
	Rect grid_1_3;
	Rect grid_2_3;
	Rect grid_3_3;
	Rect grid_4_3;
	Rect grid_5_3;
	Rect grid_6_3;
	Rect grid_1_4;
	Rect grid_2_4;
	Rect grid_3_4;
	Rect grid_4_4;
	Rect grid_5_4;
	Rect grid_6_4;
	Rect grid_1_5;
	Rect grid_2_5;
	Rect grid_3_5;
	Rect grid_4_5;
	Rect grid_5_5;
	Rect grid_6_5;
	Rect grid_1_6;
	Rect grid_2_6;
	Rect grid_3_6;
	Rect grid_4_6;
	Rect grid_5_6;
	Rect grid_6_6;

	SelectEntity* select;

	AllyMonsterEntity* player_monster1;
	int player_monster1_x_hosei;//Ç†Ç∆Ç≈çÌèú
	int player_monster1_y_hosei;//Ç†Ç∆Ç≈çÌèú

	AllyMonsterEntity* player_monster2;
	AllyMonsterEntity* player_monster3;
	AllyMonsterEntity* player_monster4;
	AllyMonsterEntity* player_monster5;

	EnemyMonsterEntity* enemy_monster1;
	EnemyMonsterEntity* enemy_monster2;
	EnemyMonsterEntity* enemy_monster3;
	EnemyMonsterEntity* enemy_monster4;
	EnemyMonsterEntity* enemy_monster5;

	Texture test1;
	Texture test2;
	
	void DrawSelectOptionTexts();

	//âºÅAëΩï™DrawÉNÉâÉXÇçÏÇ¡ÇƒÇªÇøÇÁÇ…à⁄Ç∑
	Font font;

	enum class SelectMode {
		Main,
		ActivityTargetSelect,
	};

	SelectMode select_mode = SelectMode::Main;
	
	BattleCommandType* battle_command_type;

	void CommandMain();

	void CommandActivityTargetSelect();
	

public:
	BattleScene();
	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw() override;
	
protected:
};