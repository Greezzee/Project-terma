#pragma once

#include "Button.h"

class EditorBackground: public Button {
public:
	EditorBackground();

	void rightClickReact() override;
	void leftClickReact() override;

	void focusReact() override;
	void disfocusReact() override;
	void Destroy() override;
	void Init(GameObject *owner) override;

	~EditorBackground();
};
