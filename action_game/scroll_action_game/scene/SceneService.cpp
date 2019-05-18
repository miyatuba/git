#include "SceneService.h"

SceneService::SceneService()
{
	this->current_scene_type_id = SceneService::SCENE_TYPE_DEMO;

	DemoScene demo_scene;
	this->demo_scene = demo_scene;
}

void SceneService::Play()
{
	//���̏���������ł��Ȃ��̂��ȁE�E����̗ʂ�΂���
	switch (this->current_scene_type_id) {
		case SceneService::SCENE_TYPE_DEMO:
			this->demo_scene.Play();
			return;
	}

}

bool SceneService::isGameEnd()
{
	switch (this->current_scene_type_id) {
		case SceneService::SCENE_TYPE_DEMO:
		return this->demo_scene.isGameEnd();
	}

	return false;

	
}