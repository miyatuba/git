#pragma once
#include <Siv3D.hpp> // OpenSiv3D v0.4.0

#include "../../Scene/BattleScene.h"
#include "../../Type/SceneType.h"



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
	void SetNextScene(eSceneId next_scene);
};