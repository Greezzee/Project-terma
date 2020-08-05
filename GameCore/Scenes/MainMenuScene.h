#pragma once

#include "MenuScene.h"

class MainMenuScene : public MenuScene
{
	// Delay before game can be closed with ESC
	unsigned _delay;
public:
	MainMenuScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Destroy() override;
};
