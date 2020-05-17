#include "SceneService.h"

SceneService::SceneService()
{
	//デモ作成のため、とりあえずステージをいきなり起動する
	this->current_scene_type_id = SceneService::SCENE_TYPE_STAGE;

	int stage_no = 1;
	this->p_current_scene = (BaseScene*) new StageScene(stage_no);
}

void SceneService::Play()
{
	this->p_current_scene->Play();
}

bool SceneService::isGameEnd()
{
	return this->p_current_scene->isGameEnd();	
}