#pragma once

#include "Button.h"

class OptionsButton: public Button {
public:
	OptionsButton();

	bool isClicked() override;
	void clickReact() override;
	void focusReact() override;

	void Draw() override;
	virtual void Init(GameObject *owner) override;
	virtual void Destroy() override;
};
