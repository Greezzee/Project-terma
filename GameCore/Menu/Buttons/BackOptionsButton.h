#pragma once

#include "Button.h"

class BackOptionsButton: public Button
{
public:
	BackOptionsButton();

	void rightClickReact() override;
	void leftClickReact() override;
	void focusReact() override;
	void disfocusReact() override;


	void Init(GameObject *owner) override;
	void Destroy() override;
};
