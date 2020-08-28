#pragma once

#include "Button.h"

class EditorColliders: public Button {
public:
	EditorColliders();

	void rightClickReact() override;
	void leftClickReact() override;

	void focusReact() override;
	void disfocusReact() override;
	void Destroy() override;
	void Init(GameObject *owner) override;

	~EditorColliders();
};
