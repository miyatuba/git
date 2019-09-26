#pragma once
# include <Siv3D.hpp> // OpenSiv3D v0.4.0
#include "BaseScene.h"

class IndexScene : public BaseScene
{
	private:
		Rect test;
	public:
		IndexScene();
		void Initialize() override;
		void Finalize() override;
		void Update() override;
		void Draw() override;
	protected:
};