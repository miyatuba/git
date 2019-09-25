#pragma once
# include <Siv3D.hpp> // OpenSiv3D v0.4.0
# include "BaseScene.h"

class BattleScene: public BaseScene 
{
private:

public:
	BattleScene();
	void Initialize() override;
	void Finalize() override;
	void Update() override;
protected:
};