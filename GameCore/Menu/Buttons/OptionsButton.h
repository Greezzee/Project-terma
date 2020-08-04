#pragma once

#include "Button.h"

class OptionsButton: public Button {
public:
	OptionsButton();

	void clickReact() override;
	void focusReact() override;
	void disfocusReact() override;
	virtual void Init(GameObject *owner) override;
	virtual void Destroy() override;
};
