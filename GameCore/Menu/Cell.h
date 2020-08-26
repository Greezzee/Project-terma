#pragma once

#include "Buttons/ItemButton.h"

class Cell {
	ItemButton* button;
public:
	Cell();

	// Draw this cell (or not if its NULL)
	void drawCell();


	~Cell();

	ItemButton* getButton() {
		return button;
	}

	void setButton(ItemButton *button) {
		this->button = button;
	}
};
