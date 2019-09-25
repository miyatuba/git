#pragma once
# include <Siv3D.hpp> // OpenSiv3D v0.4.0

class BaseScene
{
private:
	//virtual void Draw() = 0;//Œp³‚¾‚©‚çprivate‚Å‚Í–³—‚Å‚ÍH
public:
	BaseScene();
	virtual ~BaseScene() {};
	virtual void Initialize() {};
	virtual void Finalize() {};
	virtual void Update() = 0;
protected:
};