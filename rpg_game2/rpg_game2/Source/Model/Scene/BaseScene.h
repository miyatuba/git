#pragma once
# include <Siv3D.hpp> // OpenSiv3D v0.4.0

class BaseScene
{
private:
	//virtual void Draw() = 0;//継承だからprivateでは無理では？
public:
	BaseScene();
	virtual ~BaseScene() {};
	virtual void Initialize() {};
	virtual void Finalize() {};
	virtual void Update() = 0;
protected:
};