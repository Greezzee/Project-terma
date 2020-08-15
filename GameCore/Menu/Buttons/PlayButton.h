#pragma once

#include "Button.h"
#include "../../../Engine/AllEngine.h"

class GameObject;

class PlayButton: public Button {
public:
	PlayButton();

	void rightClickReact() override;
	void leftClickReact() override;

	void focusReact() override;
	void disfocusReact() override;
	void Init(GameObject *owner) override;
	void Destroy() override;
};
