#pragma once

#include "MenuScene.h"
#include "../Menu/Cell.h"

class Inventory;
class ItemFocus;
class Map;

// Constant vectors for item buttons
const Vector2F itemIconSize = { 75, 80 };
const Vector2F itemStartPos = { 117, 610 };
const unsigned maxColumns = 9;
const unsigned maxRows = 7;

const unsigned INV_BG_LAYER = 5;
const unsigned INV_BARS_LAYER = 6;
const unsigned INV_WIDGETS_LAYER = 7;

class InventoryScene: public MenuScene {
	// Current map
	Map *gamefield;
	// Inventory of the main character
	Inventory* inventory;
	// cellNet
	Cell cells[maxColumns * maxRows];
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
