#pragma once

#include "Button.h"

class BackOptionsButton: public Button
{
public:
	BackOptionsButton();

	void clickReact() override;
	void focusReact() override;

	void Init(GameObject *owner) override;
	void Destroy() override;
};
