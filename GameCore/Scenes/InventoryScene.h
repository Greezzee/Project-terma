#pragma once

#include "MenuScene.h"

class Inventory;
class ItemFocus;
class Map;

// Constant vectors for item buttons
const Vector2F itemIconSize = { 75, 80 };
const Vector2F itemStartPos = { 114, 612 };
const unsigned maxColumns = 9;
const unsigned maxRows = 7;

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
