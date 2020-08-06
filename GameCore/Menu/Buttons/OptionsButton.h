#pragma once

#include "Button.h"

class OptionsButton: public Button {
public:
	OptionsButton();

	void clickReact() override;
	void focusReact() override;
	void disfocusReact() override;
	void Destroy() override;
	void Init(GameObject *owner) override;
};
