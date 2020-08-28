#pragma once

#include "Button.h"

class EditorCross: public Button {
public:
	EditorCross();

	void rightClickReact() override;
	void leftClickReact() override;

	void focusReact() override;
	void disfocusReact() override;
	void Destroy() override;
	void Init(GameObject *owner) override;

	~EditorCross();
};
