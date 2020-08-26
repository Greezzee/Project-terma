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
#include "../Map/Map.h"

LevelEditorScene::LevelEditorScene() {
	currentMap = new Map();
	currentBlock = (Block*) DIRT_BLOCK->Clone();
}

void LevelEditorScene::Init() {
	widgets = new std::vector<MenuWidget*>;

	EditorPanel *editor_panel = new EditorPanel();
	editor_panel->Init(nullptr);
	editor_panel->setScene(this);
	editor_panel->setSpriteID(Textures::EDITOR_PANEL);
	editor_panel->SetView(Views::MAIN_MENU);
	editor_panel->setLayer(3);
	editor_panel->SetPos( { 90, 710 });
	editor_panel->SetSize( { 130, 330 });
	widgets->push_back(editor_panel);

	EditorCurrentBlockBar *block_bar = new EditorCurrentBlockBar();
	block_bar->Init(nullptr);
	block_bar->setScene(this);
	block_bar->setSpriteID(Textures::EDITOR_CURRENT_BLOCK);
	block_bar->SetView(Views::MAIN_MENU);
	block_bar->SetPos( { 90, 470 });
	block_bar->setLayer(3);
	block_bar->SetSize( { 119, 119 });
	widgets->push_back(block_bar);

	EditorCurrentBlock *cur_block = new EditorCurrentBlock();
	cur_block->Init(nullptr);
	cur_block->setScene(this);
	cur_block->setBlock(currentBlock);
	cur_block->SetView(Views::MAIN_MENU);
	cur_block->SetPos( { 90, 470 });
	cur_block->SetSize( { BLOCK_SIZE * 4, BLOCK_SIZE * 4 });
	cur_block->setLayer(4);
	widgets->push_back(cur_block);

	currentMap->setLevel(new EmptyLevel());

	currentMap->Init();

	currentMap->setPlayersView(Views::EDITOR_CAM);
	currentMap->setMayDrawBackground(false);
	currentMap->setIgnoreLight(true);
	currentMap->setMayDrawGrid(true);
	currentMap->setMayDrawColliders(true);
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

	unsigned move_dist =
			GraphicManager::GetView(Views::EDITOR_CAM)->virtual_size.x * 0.005;

	if (InputManager::IsDown(Controls::LEFT)) {
		GraphicManager::GetView(Views::EDITOR_CAM)->virtual_position.x -=
				move_dist;
	}
	if (InputManager::IsDown(Controls::RIGHT)) {
		GraphicManager::GetView(Views::EDITOR_CAM)->virtual_position.x +=
				move_dist;
	}
	if (InputManager::IsDown(Controls::UP)) {
		GraphicManager::GetView(Views::EDITOR_CAM)->virtual_position.y +=
				move_dist;
	}
	if (InputManager::IsDown(Controls::DOWN)) {
		GraphicManager::GetView(Views::EDITOR_CAM)->virtual_position.y -=
				move_dist;
	}
	if (InputManager::IsDown(Controls::PLUS)
			&& GraphicManager::GetView(Views::EDITOR_CAM)->virtual_size.x > 128
			&& GraphicManager::GetView(Views::EDITOR_CAM)->virtual_size.y
					> 72) {
		GraphicManager::GetView(Views::EDITOR_CAM)->virtual_size.x += -0.01
				* GraphicManager::GetView(Views::EDITOR_CAM)->virtual_size.x;
		GraphicManager::GetView(Views::EDITOR_CAM)->virtual_size.y += -0.01
				* GraphicManager::GetView(Views::EDITOR_CAM)->virtual_size.y;
	}
	if (InputManager::IsDown(Controls::MINUS)) {
		GraphicManager::GetView(Views::EDITOR_CAM)->virtual_size.x += 0.01
				* GraphicManager::GetView(Views::EDITOR_CAM)->virtual_size.x;
		;
		GraphicManager::GetView(Views::EDITOR_CAM)->virtual_size.y += 0.01
				* GraphicManager::GetView(Views::EDITOR_CAM)->virtual_size.y;
		;
	}

	if (InputManager::IsDown(MouseKey::Mouse_Left)) {
		Vector2F pos = GraphicManager::ConvertRealToView(
				InputManager::GetMousePos(), Views::EDITOR_CAM);
		currentMap->replaceWithBlock(currentMap->getGridCoords(pos),
				(Block*) currentBlock->Clone());
	}

	updateWidgets();
	drawWidgets();

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
