#pragma once
# include <Siv3D.hpp> // OpenSiv3D v0.4.0
# include "BaseScene.h"

class ShopScene : public BaseScene
{
	private:
		Rect test;
	public:
		ShopScene();
		void Initialize() override;
		void Finalize() override;
		void Update() override;
		void Draw() override;
	protected:
};