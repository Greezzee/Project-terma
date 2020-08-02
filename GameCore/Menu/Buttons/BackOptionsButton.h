#pragma once

#include "Button.h"

class BackOptionsButton: public Button
{
public:
	BackOptionsButton();

	bool isClicked() override;
	void clickReact() override;
	void focusReact() override;

	void Init(GameObject *owner) override;
	void Draw() override;
	void Destroy() override;
};
