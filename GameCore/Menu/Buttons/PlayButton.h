#pragma once

#include "Button.h"

#include "../../Scenes/MenuScene.h"

class PlayButton : public Button
{
public:
	PlayButton();

	void clickReact() override;
	void focusReact() override;
	void disfocusReact() override;
	void Init(GameObject* owner) override;
	void Destroy() override;
};
