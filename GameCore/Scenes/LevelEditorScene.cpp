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

const unsigned editor_block_size = 20;

LevelEditorScene::LevelEditorScene() {
	currentMap = new Map();
	block_button = nullptr;
	currentBlock = nullptr;
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

	EditorPanel *editor_str_panel = new EditorPanel();
	editor_str_panel->Init(nullptr);
	editor_str_panel->setScene(this);
	editor_str_panel->setSpriteID(Textures::EDITOR_PANEL);
	editor_str_panel->SetView(Views::MAIN_MENU);
	editor_str_panel->setLayer(3);
	editor_str_panel->SetPos( { 90, 360 });
	editor_str_panel->SetSize( { 130, 330 });
	widgets->push_back(editor_str_panel);

	EditorCurrentBlockBar *block_bar = new EditorCurrentBlockBar();
	block_bar->Init(nullptr);
	block_bar->setScene(this);
	block_bar->setSpriteID(Textures::EDITOR_CURRENT_BLOCK);
	block_bar->SetView(Views::MAIN_MENU);
	block_bar->SetPos( { 90, 120 });
	block_bar->setLayer(3);
	block_bar->SetSize( { 119, 119 });
	widgets->push_back(block_bar);

	EditorCurrentBlock *cur_block = new EditorCurrentBlock();
	cur_block->Init(nullptr);
	cur_block->setScene(this);
	cur_block->SetView(Views::MAIN_MENU);
	cur_block->SetPos(block_bar->GetPos());
	cur_block->SetSize( { editor_block_size * 4, editor_block_size * 4 });
	cur_block->setLayer(4);
	block_button = cur_block;
	widgets->push_back(cur_block);

	EditorChooseBlock *dirt_block = new EditorChooseBlock(cur_block);
	dirt_block->Init(nullptr);
	dirt_block->setScene(this);
	dirt_block->setBlock(
			dynamic_cast<Block*>(Blocks::ALL_BLOCKS[Blocks::DIRT_BLOCK->getID()]->Clone()));
	dirt_block->SetView(Views::MAIN_MENU);
	dirt_block->SetPos( { 60, 820 });
	dirt_block->SetSize( { editor_block_size * 2, editor_block_size * 2 });
	dirt_block->setLayer(4);
	widgets->push_back(dirt_block);

	EditorChooseBlock *grass_block = new EditorChooseBlock(cur_block);
	grass_block->Init(nullptr);
	grass_block->setScene(this);
	grass_block->setBlock(
			dynamic_cast<Block*>(Blocks::ALL_BLOCKS[Blocks::GRASS_BLOCK->getID()]->Clone()));
	grass_block->SetView(Views::MAIN_MENU);
	grass_block->SetPos( { 120, 820 });
	grass_block->SetSize( { editor_block_size * 2, editor_block_size * 2 });
	grass_block->setLayer(4);
	widgets->push_back(grass_block);

	EditorChooseBlock *tree = new EditorChooseBlock(cur_block);
	tree->Init(nullptr);
	tree->setScene(this);
	tree->setBlock(
			dynamic_cast<Block*>(Blocks::ALL_BLOCKS[Blocks::TREE->getID()]->Clone()));
	tree->SetView(Views::MAIN_MENU);
	tree->SetPos( { 90, 400 });
	tree->SetSize( { 4 * editor_block_size, 4 * editor_block_size });
	tree->setLayer(4);
	widgets->push_back(tree);

	// CURRENT BLOCK HERE
	currentBlock = dirt_block->getBlock();
	cur_block->setBlock(currentBlock);

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
	updateWidgets();
	drawWidgets();

	currentMap->Update();
	currentBlock = block_button->getBlock();

	if (InputManager::IsPressed(Controls::BACK)) {
		SceneManager::CreateScene(new MainMenuScene());
		SceneManager::CloseScene(this);
		return;
	}

	unsigned move_dist =
			GraphicManager::GetView(Views::EDITOR_CAM)->virtual_size.x
					* 0.0000005 * TimeManager::GetDeltaTime();

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
		GraphicManager::GetView(Views::EDITOR_CAM)->virtual_size.x += -0.0000005
				* GraphicManager::GetView(Views::EDITOR_CAM)->virtual_size.x
				* TimeManager::GetDeltaTime();
		GraphicManager::GetView(Views::EDITOR_CAM)->virtual_size.y += -0.0000005
				* GraphicManager::GetView(Views::EDITOR_CAM)->virtual_size.y
				* TimeManager::GetDeltaTime();
	}
	if (InputManager::IsDown(Controls::MINUS)) {
		GraphicManager::GetView(Views::EDITOR_CAM)->virtual_size.x += 0.0000005
				* GraphicManager::GetView(Views::EDITOR_CAM)->virtual_size.x
				* TimeManager::GetDeltaTime();
		;
		GraphicManager::GetView(Views::EDITOR_CAM)->virtual_size.y += 0.0000005
				* GraphicManager::GetView(Views::EDITOR_CAM)->virtual_size.y
				* TimeManager::GetDeltaTime();
		;
	}

	if (InputManager::IsDown(MouseKey::Mouse_Left)) {
		Vector2F pos = GraphicManager::ConvertRealToView(
				InputManager::GetMousePos(), Views::EDITOR_CAM);

		Vector2F _pos = GraphicManager::ConvertRealToView(
				InputManager::GetMousePos(), Views::MAIN_MENU);

		printf("Y = %g", _pos.y);

		if (!((_pos.x <= 160 && _pos.x >= 20) && (_pos.y <= 880 &&  _pos.y >= 50)))
			switch (block_button->getBlockType()) {
			case NONE:
				std::cerr << "Error! Block type is NONE!\n";
				break;
			case STANDART:
				currentMap->replaceWithBlock(currentMap->getGridCoords(pos),
						(Block*) currentBlock->Clone());
				break;
			case MULTI:
				currentMap->replaceWithMultiblock(
						currentMap->getGridCoords(pos),
						(Multiblock*) currentBlock->Clone());
				break;
			}
	}
}

void LevelEditorScene::Destroy() {
	delete currentMap->getLevel();

	currentMap->Destroy();
	delete currentMap;

	destroyWidgets();

	printf("LevelEditorScene destroyed!\n");
	std::cout.flush();
}

LevelEditorScene::~LevelEditorScene() {
}
