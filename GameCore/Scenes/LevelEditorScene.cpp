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
	currentMap->Update();
	currentMap->pauseGame();

//	GraphicManager::GetView(Views::PLAYER_CAM)->real_size =
//			GraphicManager::GetView(Views::PLAYER_CAM)->real_size * 0.7f;

	printf("LevelEditorScene created!\n");
}

void LevelEditorScene::Update() {

	currentMap->Update();

	if (InputManager::IsPressed(Controls::BACK)) {
		SceneManager::CreateScene(new MainMenuScene());
		SceneManager::CloseScene(this);
		return;
	}
}

void LevelEditorScene::Destroy() {
	currentMap->Destroy();
	currentBlock->Destroy();

	delete currentMap;
	delete currentBlock;

	widgets->clear();
	delete widgets;

	printf("LevelEditorScene destroyed!\n");
	std::cout.flush();

	GraphicManager::GetView(Views::PLAYER_CAM)->real_size =
			GraphicManager::GetView(Views::PLAYER_CAM)->real_size / 0.7f;
}

LevelEditorScene::~LevelEditorScene() {
}
