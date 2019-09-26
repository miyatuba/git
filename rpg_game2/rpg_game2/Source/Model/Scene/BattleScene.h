#pragma once
# include <Siv3D.hpp> // OpenSiv3D v0.4.0
# include "BaseScene.h"

class BattleScene: public BaseScene 
{
private:
	Rect test;
public:
	BattleScene();
	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw() override;
protected:
};