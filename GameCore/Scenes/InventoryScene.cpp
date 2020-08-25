#include "InventoryScene.h"

#include <cstdio>
#include <iostream>
#include <vector>

#include "../../Engine/Control/InputManager.h"
#include "../../Engine/SceneManagment/SceneManager.h"
#include "../../Engine/Time/TimeManager.h"
#include "../../Engine/Utility/Coordinate.h"
#include "../Controls.h"
#include "../Items/Item.h"
#include "../Map/Map.h"
#include "../Menu/Buttons/ItemButton.h"
#include "../Menu/ImageWidgets/Background.h"
#include "../Menu/ImageWidgets/ItemFocus.h"
#include "../Player/Inventory.h"
#include "../Player/Player.h"
#include "../Textures.h"
#include "../Views.h"

InventoryScene::InventoryScene(Map *_map) {
	delay = 0;
	gamefield = _map;
	inventory = gamefield->player->inventory;
	focused_item = nullptr;
}

void InventoryScene::Init() {
	widgets = new std::vector<MenuWidget*>;

	//! Initializing the inventory background
	Background *background = new Background();
	background->Init(nullptr);
	background->setScene(this);
	background->setSpriteID(Textures::INVENTORY);
	background->SetView(Views::MAIN_MENU);
	background->setLayer(2);
	background->SetPos( { 800, 450 });
	background->SetSize( { 1600, 900 });
	widgets->push_back(background);

	// Create each item's button
	unsigned column = 0;
	unsigned row = 0;

	std::vector<Item*> *items = inventory->getItems();
	for (unsigned i = 0; i < inventorySize; i++) {
		// Check if this item exists
		if (items->at(i) != nullptr) {

			ItemButton *_button = new ItemButton(items->at(i));
			_button->Init(nullptr);
			_button->setScene(this);
			_button->setSpriteID(items->at(i)->getIconID());
			_button->SetPos(
					{ itemStartPos.x + column * itemIconSize.x, itemStartPos.y
							- row * itemIconSize.y });
			items->at(i)->SetPos(_button->GetPos());
			_button->setLayer(2);
			_button->setOriginalPos(_button->GetPos());
			_button->SetSize(itemIconSize);
			_button->SetView(Views::MAIN_MENU);
			widgets->push_back(_button);
		}

		// Go to the next cell anyway
		if (column >= maxColumns) {
			column = 0;
			row++;
		} else {
			column++;
		}

		if (row >= maxRows) {
			printf("Error! Too many items!\n");
			break;
		}
	}

	// Create focus item image widget
	ItemFocus *item_focus = new ItemFocus();
	item_focus->Init(nullptr);
	item_focus->setScene(this);
	item_focus->setSpriteID(Textures::ITEM_FOCUS);
	item_focus->SetPos( { 0, 0 });
	item_focus->SetSize(itemIconSize);
	item_focus->SetView(Views::MAIN_MENU);
	this->focused_item = item_focus;
	widgets->push_back(item_focus);

	printf("InventoryScene created!\n");
}

void InventoryScene::Update() {
	delay += TimeManager::GetDeltaTime();

	updateWidgets();
	drawWidgets();

	if (InputManager::IsPressed(Controls::OPEN_INV) && delay > 100000) {
		gamefield->unpauseGame();
		SceneManager::CloseScene(this);
	}
}

void InventoryScene::Destroy() {
	destroyWidgets();

	printf("InventoryScene destroyed!\n");
	std::cout.flush();
}

void InventoryScene::setItemFocus(ItemFocus *_item) {
	focused_item = _item;
}
