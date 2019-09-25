#include "SceneService.h"

SceneService::SceneService()
{
	BattleScene battle_scene;
	this->m_p_scene = (BaseScene*) new BattleScene;
}

void SceneService::Initialize()
{
	
}
void SceneService::Finalize()
{

}
void SceneService::Update()
{
	if (this->m_next_scene_id != e_scene_none_id) {
		switch (this->m_next_scene_id) {
			delete this->m_p_scene;
			case e_scene_index_id:
				this->m_p_scene = new IndexScene;
				break;
			case e_scene_menu_id:
				this->m_p_scene = new MenuScene;
				break;
			case e_scene_battle_id:
				this->m_p_scene = new BattleScene;
				break;
			case e_scene_field_id:
				this->m_p_scene = new FieldScene;
				break;
			case e_scene_shop_id:
				this->m_p_scene = new ShopScene;
				break;
		}
		this->m_next_scene_id = e_scene_none_id;
	}
	this->m_p_scene->Update();
}

void SceneService::ChangeScene(eSceneId next_scene)
{
	this->m_next_scene_id = next_scene;
}

