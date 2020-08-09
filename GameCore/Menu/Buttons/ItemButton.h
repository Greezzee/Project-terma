#pragma once

#include "Button.h"

#include "../../items/Item.h"

class ItemButton: public Button {
	// Button's item
	Item* item;
public:
	ItemButton(Item* _item);

	void clickReact() override;
	void focusReact() override;
	void disfocusReact() override;
	void Destroy() override;
	void Init(GameObject *owner) override;

	~ItemButton();

	// Shows if this button has been focused before (for inventory item_focus)
	bool was_focused;
};
