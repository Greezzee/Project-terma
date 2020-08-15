#pragma once

#include "Button.h"

class MenuLevelEditorButton: public Button {
public:
	MenuLevelEditorButton();

	void rightClickReact() override;
	void leftClickReact() override;

	void focusReact() override;
	void disfocusReact() override;
	void Destroy() override;
	void Init(GameObject *owner) override;

	~MenuLevelEditorButton();
};
