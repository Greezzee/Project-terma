#pragma once

#include "MenuScene.h"

class MainMenuScene : public MenuScene
{
public:
	MainMenuScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Destroy() override;
};
