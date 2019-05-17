#include "SceneService.h"

SceneService::SceneService()
{
	this->current_scene_type_id = SceneService::SCENE_TYPE_DEMO;

	DemoScene demo_scene;
	this->demo_scene = demo_scene;
}

void SceneService::Play()
{
	//‚±‚Ì‘‚«•û‰ñ”ð‚Å‚«‚È‚¢‚Ì‚©‚ÈEE•ªŠò‚Ì—Ê‚â‚Î‚»‚¤
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