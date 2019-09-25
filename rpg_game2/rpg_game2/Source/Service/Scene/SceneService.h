#pragma once
# include <Siv3D.hpp> // OpenSiv3D v0.4.0

# include "../../Model/Scene/BattleScene.h"
# include "../../Model/Scene/FieldScene.h"
# include "../../Model/Scene/IndexScene.h"
# include "../../Model/Scene/BattleScene.h"
# include "../../Model/Scene/ShopScene.h"
# include "../../Model/Scene/MenuScene.h"

typedef enum {
	e_scene_index_id,    
	e_scene_battle_id,
	e_scene_field_id,
	e_scene_menu_id,
	e_scene_shop_id,

	e_scene_none_id,    
} eSceneId;

class SceneService
{
	private:
		BaseScene* m_p_scene;
		eSceneId m_next_scene_id;
	public:
		SceneService();
		void Initialize();
		void Finalize();
		void Update();
		void ChangeScene(eSceneId next_scene);
};