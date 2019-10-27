#pragma once
#include <Siv3D.hpp> // OpenSiv3D v0.4.0
#include "../Type/SceneType.h"

class BaseScene
{
private:
	eSceneId m_next_scene_id = eSceneId::e_scene_none_id;
public:
	BaseScene();
	virtual ~BaseScene() {};
	virtual void Initialize() {};
	virtual void Finalize() {};
	virtual void Update() = 0;
	virtual void Draw() = 0;
	bool SholdChangeScene();
	eSceneId GetNextSceneId();
protected:
	void SetNextSceneId(eSceneId next_scene_id);
};