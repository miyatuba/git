#pragma once
#include <Siv3D.hpp> // OpenSiv3D v0.4.0
#include "../Type/SceneType.h"

class BaseScene
{
private:
	SceneType::eSceneId m_next_scene_id = SceneType::eSceneId::e_scene_none_id;
public:
	BaseScene();
	virtual ~BaseScene() {};
	virtual void Initialize() {};
	virtual void Finalize() {};
	virtual void Update() = 0;
	virtual void Draw() = 0;
	bool SholdChangeScene();
	SceneType::eSceneId GetNextSceneId();
protected:
	void SetNextSceneId(SceneType::eSceneId next_scene_id);
};