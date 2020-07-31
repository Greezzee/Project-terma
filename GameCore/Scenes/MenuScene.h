#pragma once

#include "../../Engine/SceneManagment/Scene.h"
#include "../Buttons/PlayButton.h"

class GameField;


class MenuScene: public Scene {
	PlayButton *play_button;
public:
	MenuScene();
	//! Draws the background
	void drawBackground();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Destroy() override;
};
