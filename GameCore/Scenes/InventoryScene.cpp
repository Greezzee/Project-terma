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
#include "../Textures.h"

InventoryScene::InventoryScene(Map *_map) {
	delay = 0;
	gamefield = _map;
}

void InventoryScene::Init() {
	//! Initializing the inventory background
	Background *background = new Background();
	background->Init(nullptr);
	background->setScene(this);
	background->setSpriteID(Textures::INVENTORY);
	background->SetView(Views::MAIN_MENU);
	background->SetPos({800, 450});
	background->SetSize({1600, 900});
	widgets.push_back(background);

	printf("InventoryScene created!\n");
}

void InventoryScene::Update() {
	delay += TimeManager::GetDeltaTime();

	if (InputManager::IsPressed(KeyboardKey::OPEN_INV) && delay > 100000) {
		gamefield->unpauseGame();
		SceneManager::CloseScene(this);
	}

	for (auto widget : widgets) {
		widget->Draw();
	}
	for (auto widget : widgets) {
		widget->Update();
	}
}

void InventoryScene::Destroy() {
	for (auto widget : widgets) {
		widget->Destroy();
		delete widget;
	}
	widgets.clear();

	printf("InventoryScene destroyed!\n");
	std::cout.flush();
}
