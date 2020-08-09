#pragma once

#include "Button.h"

#include "../../items/Item.h"

class ItemButton: public Button {
	// Button's item
	Item* item;
	// Save the original position (in case it gets equipped and change its position)
	Vector2F original_pos;
public:
	ItemButton(Item* _item);

	void clickReact() override;
	void focusReact() override;
	void disfocusReact() override;
	void Destroy() override;
	void Init(GameObject *owner) override;

	void Update() override;

	// Sets the original position of this button (in the inventory)
	void setOriginalPos(Vector2F original);
	// Get the original position
	Vector2F getOriginalPos();

	~ItemButton();

	// Shows if this button has been focused before (for inventory item_focus)
	bool was_focused;
};
