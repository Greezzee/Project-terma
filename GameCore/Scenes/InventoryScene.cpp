#include "InventoryScene.h"

#include <cstdio>
#include <iostream>
#include <vector>

#include "../../Engine/Control/InputManager.h"
#include "../../Engine/Graphics/DrawData.h"
#include "../../Engine/SceneManagment/SceneManager.h"
#include "../../Engine/Time/TimeManager.h"
#include "../../Engine/Utility/Coordinate.h"

#include "../Map.h"
#include "../Menu/ImageWidgets/Background.h"
#include "../Menu/Buttons/ItemButton.h"
#include "../Textures.h"

InventoryScene::InventoryScene(Map *_map) {
	delay = 0;
	gamefield = _map;
	inventory = gamefield->getInventory();
}

// Constant vectors for item buttons
const Vector2F itemIconSize = {75, 80};
const Vector2F itemStartPos = {110, 610};
const unsigned maxColumns = 8;
const unsigned maxRows = 7;

void InventoryScene::Init() {
	widgets = new std::vector<MenuWidget*>;

	//! Initializing the inventory background
	Background *background = new Background();
	background->Init(nullptr);
	background->setScene(this);
	background->setSpriteID(Textures::INVENTORY);
	background->SetView(Views::MAIN_MENU);
	background->SetPos({800, 450});
	background->SetSize({1600, 900});
	widgets->push_back(background);

	// Create each item's button
	unsigned column = 0;
	unsigned row = 0;

	std::vector<Item*>* items = inventory->getItems();
	for (auto item : *items) {
		ItemButton *_button = new ItemButton(item);
		_button->Init(nullptr);
		_button->setScene(this);
		_button->setSpriteID(item->getIconID());
		_button->SetPos({itemStartPos.x + column * itemIconSize.x, itemStartPos.y - row * itemIconSize.y});
		_button->SetSize(itemIconSize);
		_button->SetGap({0, 0});
		widgets->push_back(_button);

		if (column >= maxColumns) {
			column = 0;
			row++;
		}
		else {
			column++;
		}

		if (row >= maxRows) {
			printf("Error! Too many items!\n");
			break;
		}
	}

	printf("InventoryScene created!\n");
}

void InventoryScene::Update() {
	delay += TimeManager::GetDeltaTime();

	if (InputManager::IsPressed(KeyboardKey::OPEN_INV) && delay > 100000) {
		gamefield->unpauseGame();
		SceneManager::CloseScene(this);
	}

	updateWidgets();
	drawWidgets();
}

void InventoryScene::Destroy() {
	for (auto widget : *widgets) {
		widget->Destroy();
		delete widget;
	}
	widgets->clear();

	delete widgets;

	printf("InventoryScene destroyed!\n");
	std::cout.flush();
}
