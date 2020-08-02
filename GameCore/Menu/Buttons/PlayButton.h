#pragma once

#include "Button.h"

#include "../../Scenes/MenuScene.h"

class PlayButton : public Button
{
public:
	PlayButton();

	bool isClicked() override;
	void clickReact() override;
	void focusReact() override;

	void Init(GameObject* owner) override;
	void Draw() override;
	void Destroy() override;
};
