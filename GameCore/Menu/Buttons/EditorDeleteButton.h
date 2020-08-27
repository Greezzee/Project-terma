#pragma once

#include "Button.h"

class EditorDeleteButton: public Button {
	bool delete_active;
public:
	EditorDeleteButton();

	void active();
	void disactive();
	bool getStatus();

	void rightClickReact() override;
	void leftClickReact() override;

	void focusReact() override;
	void disfocusReact() override;
	void Destroy() override;
	void Init(GameObject *owner) override;

	~EditorDeleteButton();
};
