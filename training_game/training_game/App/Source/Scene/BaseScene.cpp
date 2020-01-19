#include "BaseScene.h"

BaseScene::BaseScene()
{

}

bool BaseScene::SholdChangeScene()
{
	//sceneが変わるとインスタンスが破棄されるからnext_scene_idの初期化処理は作らない
	return this->m_next_scene_id != SceneType::eSceneId::e_scene_none_id;
}

SceneType::eSceneId BaseScene::GetNextSceneId()
{
	return this->m_next_scene_id;
}

void BaseScene::SetNextSceneId(SceneType::eSceneId next_scene_id)
{
	this->m_next_scene_id = next_scene_id;
}