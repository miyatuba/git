#include "SceneService.h"

SceneService::SceneService()
{
	BattleScene battle_scene;
	this->m_p_scene = (BaseScene*) new BattleScene;
	this->m_next_scene_id = eSceneId::e_scene_none_id;
}

void SceneService::Initialize()
{
	
}
void SceneService::Finalize()
{

}
void SceneService::Update()
{
	if (this->m_next_scene_id != eSceneId::e_scene_none_id) {
		delete this->m_p_scene;
		switch (this->m_next_scene_id) {			
			case eSceneId::e_scene_index_id:
				this->m_p_scene = new IndexScene;
				break;
			case eSceneId::e_scene_menu_id:
				this->m_p_scene = new MenuScene;
				break;
			case eSceneId::e_scene_battle_id:
				this->m_p_scene = new BattleScene;
				break;
			case eSceneId::e_scene_field_id:
				this->m_p_scene = new FieldScene;
				break;
			case eSceneId::e_scene_shop_id:
				this->m_p_scene = new ShopScene;
				break;
		}
		this->m_next_scene_id = eSceneId::e_scene_none_id;
	}
	this->m_p_scene->Update();
	//‚¢‚Ü‚¢‚¿‚È‹Lq‚Å‚Í‚ ‚é‚ªA‚±‚¤‚µ‚È‚¢‚ÆzŠÂŠÖ”‚É‚È‚é
	if (this->m_p_scene->SholdChangeScene()) {
		SceneService::SetNextScene(this->m_p_scene->GetNextSceneId());
	}
}

void SceneService::SetNextScene(eSceneId next_scene)
{
	this->m_next_scene_id = next_scene;
}

