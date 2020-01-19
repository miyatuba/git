#include "SceneService.h"

SceneService::SceneService()
{
	BattleScene battle_scene;
	this->m_p_scene = (BaseScene*) new BattleScene;
	this->m_next_scene_id = SceneType::eSceneId::e_scene_none_id;
}

void SceneService::Initialize()
{

}
void SceneService::Finalize()
{

}
void SceneService::Update()
{
	if (this->m_next_scene_id != SceneType::eSceneId::e_scene_none_id) {
		delete this->m_p_scene;
		switch (this->m_next_scene_id) {
		case SceneType::eSceneId::e_scene_battle_id:
			this->m_p_scene = new BattleScene;
			break;
		}
		this->m_next_scene_id = SceneType::eSceneId::e_scene_none_id;
	}
	this->m_p_scene->Update();
	//���܂����ȋL�q�ł͂��邪�A�������Ȃ��Əz�֐��ɂȂ�
	if (this->m_p_scene->SholdChangeScene()) {
		SceneService::SetNextScene(this->m_p_scene->GetNextSceneId());
	}
}

void SceneService::SetNextScene(SceneType::eSceneId next_scene)
{
	this->m_next_scene_id = next_scene;
}
