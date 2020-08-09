#pragma once

#include "MenuScene.h"

#include "../Map.h"
#include "../Menu/ImageWidgets/ItemFocus.h"

class InventoryScene: public MenuScene {
	// Current map
	Map *gamefield;
	// Inventory of the main character
	Inventory* inventory;
	// The widget that appears when some item is focused
	ItemFocus* focused_item;
public:
	InventoryScene(Map *_map);

	void Init() override;
	void Update() override;
	void Destroy() override;

	// Set this widget
	void setItemFocus(ItemFocus* _item);

	// Delay before inventory can be closed
	unsigned delay;

	friend class ItemButton;
};
