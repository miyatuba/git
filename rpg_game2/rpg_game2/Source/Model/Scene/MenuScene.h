#pragma once
# include <Siv3D.hpp> // OpenSiv3D v0.4.0
#include "BaseScene.h"

class MenuScene : public BaseScene
{
private:

public:
	MenuScene();
	void Initialize() override;
	void Finalize() override;
	void Update() override;
protected:
};