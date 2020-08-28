#pragma once

#include "Button.h"

class EditorLight: public Button {
public:
	EditorLight();

	void rightClickReact() override;
	void leftClickReact() override;

	void focusReact() override;
	void disfocusReact() override;
	void Destroy() override;
	void Init(GameObject *owner) override;

	~EditorLight();
};
