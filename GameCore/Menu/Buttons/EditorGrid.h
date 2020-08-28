#pragma once

#include "Button.h"

class EditorGrid: public Button {
public:
	EditorGrid();

	void rightClickReact() override;
	void leftClickReact() override;

	void focusReact() override;
	void disfocusReact() override;
	void Destroy() override;
	void Init(GameObject *owner) override;

	~EditorGrid();
};
