#pragma once

#include "Button.h"

class ControlsButton: public Button {
public:
	ControlsButton();

	void rightClickReact() override;
	void leftClickReact() override;

	void focusReact() override;
	void disfocusReact() override;
	void Destroy() override;
	void Init(GameObject *owner) override;

};
