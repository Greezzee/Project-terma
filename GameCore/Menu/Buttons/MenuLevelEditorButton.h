#pragma once

#include "Button.h"

class MenuLevelEditorButton : public Button {
public:
	MenuLevelEditorButton();

	void clickReact() override;
	void focusReact() override;
	void disfocusReact() override;
	void Destroy() override;
	void Init(GameObject *owner) override;

	~MenuLevelEditorButton();
};
