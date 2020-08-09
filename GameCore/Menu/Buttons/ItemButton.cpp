#include "ItemButton.h"

#include "../../Scenes/InventoryScene.h"

#include <cstdio>
#include <iostream>

ItemButton::ItemButton(Item *_item) {
	item = _item;
	was_focused = false;
}

void ItemButton::clickReact() {
	// Nothing for now
}

void ItemButton::focusReact() {
	// Show that this item is focused - indicate this item for item_focus image widget
	InventoryScene *_scene = dynamic_cast<InventoryScene*>(current_scene);
	_scene->focused_item->focusItem(this->item);
	was_focused = true;
	// printf("FOCUS ITEMBUTTON! ADDRESS - %x\n", _scene);
}

void ItemButton::disfocusReact() {
	/*
	 printf("=============\n");
	 printf("DISFOCUSED ITEMBUTTON NOW!\n");
	 printf("=============\n");
	 */

	// Disfocus (if have been focused)
	InventoryScene *_scene = dynamic_cast<InventoryScene*>(this->current_scene);

	if (was_focused) {
		_scene->focused_item->disfocus();
		was_focused = false;
	}
}

void ItemButton::Destroy() {
	printf("ItemButton destroyed!\n");
	std::cout.flush();
}

void ItemButton::Init(GameObject *owner) {
	printf("ItemButton created!\n");
}

ItemButton::~ItemButton() {
	item = nullptr;
}
