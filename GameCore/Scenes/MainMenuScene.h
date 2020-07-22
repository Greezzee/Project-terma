#pragma once

#include "../../Engine/SceneManagment/Scene.h"

class MainMenuScene : public Scene
{
public:
	MainMenuScene();
	void Init();
	void Update();
	void Destroy();
private:
	int counter;
	bool started;
};
