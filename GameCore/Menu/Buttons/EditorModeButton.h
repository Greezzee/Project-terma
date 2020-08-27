#pragma once

#include "Button.h"

class EditorModeButton: public Button {
public:
	EditorModeButton();

	void changeMode();

	void rightClickReact() override;
	void leftClickReact() override;

	void focusReact() override;
	void disfocusReact() override;
	void Destroy() override;
	void Init(GameObject *owner) override;

	~EditorModeButton();

};
