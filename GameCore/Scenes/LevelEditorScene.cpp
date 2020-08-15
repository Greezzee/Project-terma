#include "LevelEditorScene.h"

#include <cstdio>
#include <iostream>
#include <vector>

#include "../../Engine/Control/InputManager.h"
#include "../../Engine/Graphics/DrawData.h"
#include "../../Engine/Graphics/GraphicManager.h"
#include "../../Engine/SceneManagment/SceneManager.h"
#include "../../Engine/Utility/Coordinate.h"
#include "../Blocks/Blocks.h"
#include "../Controls.h"
#include "../Map/EmptyLevel.h"
#include "../Map/Map.h"
#include "../Menu/MenuWidget.h"
#include "../Views.h"
#include "MainMenuScene.h"

LevelEditorScene::LevelEditorScene() {
	currentMap = new Map();
	currentBlock = (Block*) DIRT_BLOCK->Clone();
}

void LevelEditorScene::Init() {
	widgets = new std::vector<MenuWidget*>;
	currentMap->setLevel(new EmptyLevel());

	currentMap->Init();

	currentMap->setMayDrawBackground(false);

	currentMap->setPlayersView(Views::EDITOR_CAM);
	currentMap->setIgnoreLight(true);
	currentMap->setMayDrawGrid(true);
	currentMap->Update();
	currentMap->pauseGame();
	printf("LevelEditorScene created!\n");
}

void LevelEditorScene::Update() {

	currentMap->Update();

	if (InputManager::IsPressed(Controls::BACK)) {
		SceneManager::CreateScene(new MainMenuScene());
		SceneManager::CloseScene(this);
		return;
	}
	if (InputManager::IsDown(Controls::LEFT)) {
		GraphicManager::GetView(Views::EDITOR_CAM)->virtual_position.x += -1;
	}
	if (InputManager::IsDown(Controls::RIGHT)) {
		GraphicManager::GetView(Views::EDITOR_CAM)->virtual_position.x += 1;
	}
	if (InputManager::IsDown(Controls::UP)) {
		GraphicManager::GetView(Views::EDITOR_CAM)->virtual_position.y += 1;
	}

	if (InputManager::IsDown(MouseKey::Mouse_Left)) {
		Vector2F pos = GraphicManager::ConvertRealToView(
					InputManager::GetMousePos(), Views::EDITOR_CAM);
		currentMap->addBlock(pos, (Block*)currentBlock->Clone());
	}

}

void LevelEditorScene::Destroy() {
	currentMap->Destroy();
	currentBlock->Destroy();

	delete currentMap;
	delete currentBlock;

	destroyWidgets();

	printf("LevelEditorScene destroyed!\n");
	std::cout.flush();
}

LevelEditorScene::~LevelEditorScene() {
}
