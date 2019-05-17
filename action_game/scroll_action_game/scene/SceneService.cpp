#include "SceneService.h"

SceneService::SceneService()
{
	DemoScene demo_scene;
	this->current_scene = demo_scene;
}

void SceneService::Play()
{
	this->current_scene.Play();
}

bool SceneService::isGameEnd()
{
	return this->current_scene.isGameEnd();
}