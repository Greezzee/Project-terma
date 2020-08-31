#include "LevelEditorScene.h"

#include <iostream>
#include <vector>

#include "../../Engine/Control/InputManager.h"
#include "../../Engine/Graphics/DrawData.h"
#include "../../Engine/Graphics/GraphicManager.h"
#include "../../Engine/SceneManagment/SceneManager.h"
#include "../../Engine/Time/TimeManager.h"
#include "../../Engine/Utility/Coordinate.h"
#include "../Blocks/Blocks.h"
#include "../Blocks/MultiblockStructures/Multiblock.h"
#include "../Controls.h"
#include "../Map/EmptyLevel.h"
#include "../Map/Map.h"
#include "../Menu/Buttons/EditorColliders.h"
#include "../Menu/Buttons/EditorCross.h"
#include "../Menu/Buttons/EditorGrid.h"
#include "../Menu/Buttons/EditorLight.h"
#include "../Menu/Buttons/EditorSave.h"
#include "../Menu/MenuWidget.h"
#include "../PTC.h"
#include "../Textures.h"
#include "../Views.h"
#include "MainMenuScene.h"

const unsigned editor_block_size = 20;

LevelEditorScene::LevelEditorScene() {
	currentMap = new Map();
	block_button = nullptr;
	currentBlock = nullptr;
	mode = FRONT;
	to_delete = NO;
	draw_background = true;
	_delay = 0;
}

void LevelEditorScene::Init() {
	widgets = new std::vector<MenuWidget*>;

	createWidgets();

	currentMap->setLevel(new EmptyLevel());
	currentMap->Init();

	currentMap->setPlayersView(Views::EDITOR_CAM);
	currentMap->setMayDrawBackground(false);
	currentMap->setIgnoreLight(true);
	currentMap->setMayDrawGrid(true);
	currentMap->setMayDrawWallBlockCrosses(true);
	currentMap->setMayDrawColliders(true);
	currentMap->Update();
	currentMap->pauseGame();

	PTC::sayCreated("LevelEditorScene");
}

void LevelEditorScene::Update() {
	updateWidgets();
	drawWidgets();
	drawBackground();

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

	if (_delay <= 1 * 500000) {
		_delay += TimeManager::GetDeltaTime();
		return;
	}

	if (InputManager::IsDown(MouseKey::Mouse_Left)) {
		Vector2F pos = GraphicManager::ConvertRealToView(
				InputManager::GetMousePos(), Views::EDITOR_CAM);

		Vector2F _pos = GraphicManager::ConvertRealToView(
				InputManager::GetMousePos(), Views::MAIN_MENU);

		if (!((_pos.x <= 160 && _pos.x >= 20) && (_pos.y <= 880 && _pos.y >= 50))
				&& !(_pos.x >= 1472 && _pos.y >= 176))
			switch (block_button->getBlockType()) {
			case NONE:
				std::cerr << "Error! Block type is NONE!\n";
				break;
			case STANDART:
				switch (mode) {
				case FRONT:
					switch (to_delete) {
					case YES:
						currentMap->removeBlock(currentMap->getGridCoords(pos));
						break;
					case NO:
						currentMap->replaceWithBlock(
								currentMap->getGridCoords(pos),
								(Block*) currentBlock->Clone());
						break;
					}
					break;
				case WALL:
					switch (to_delete) {
					case YES:
						currentMap->removeWallBlock(
								currentMap->getGridCoords(pos));
						break;
					case NO:
						currentMap->replaceWithWallBlock(
								currentMap->getGridCoords(pos),
								(Block*) currentBlock->Clone());
						break;
					}
					break;
				}
				break;
			case MULTI:
				switch (to_delete) {
				case YES:
					currentMap->removeWallBlock(currentMap->getGridCoords(pos));
					break;
				case NO:
					currentMap->replaceWithMultiblock(
							currentMap->getGridCoords(pos),
							(Multiblock*) currentBlock->Clone());
					break;
				}
			}
	}
}

void LevelEditorScene::Destroy() {
	delete currentMap->getLevel();

	currentMap->Destroy();
	delete currentMap;

	destroyWidgets();

	PTC::sayDestroyed("LevelEditorScene");
}

LevelEditorScene::~LevelEditorScene() {
}

enum BLOCK_SITUATION LevelEditorScene::getMode() const {
	return mode;
}

void LevelEditorScene::setMode(enum BLOCK_SITUATION mode) {
	this->mode = mode;
}

void LevelEditorScene::toDelete() {
	to_delete = YES;
}

void LevelEditorScene::toAdd() {
	to_delete = NO;
}

enum BLOCK_DELETE LevelEditorScene::isDelete() {
	return to_delete;
}

const unsigned EDITOR_MODE_START = 560;

void LevelEditorScene::createWidgets() {
	EditorPanel *editor_panel = new EditorPanel();
	editor_panel->Init(nullptr);
	editor_panel->setScene(this);
	editor_panel->setSpriteID(Textures::EDITOR_PANEL);
	editor_panel->SetView(Views::MAIN_MENU);
	editor_panel->setLayer(EDITOR_BARS_LAYER);
	editor_panel->SetPos( { 90, 710 });
	editor_panel->SetSize( { 130, 330 });
	widgets->push_back(editor_panel);

	EditorPanel *editor_str_panel = new EditorPanel();
	editor_str_panel->Init(nullptr);
	editor_str_panel->setScene(this);
	editor_str_panel->setSpriteID(Textures::EDITOR_PANEL);
	editor_str_panel->SetView(Views::MAIN_MENU);
	editor_str_panel->setLayer(EDITOR_BARS_LAYER);
	editor_str_panel->SetPos( { 90, 360 });
	editor_str_panel->SetSize( { 130, 330 });
	widgets->push_back(editor_str_panel);

	EditorCurrentBlockBar *block_bar = new EditorCurrentBlockBar();
	block_bar->Init(nullptr);
	block_bar->setScene(this);
	block_bar->setSpriteID(Textures::EDITOR_CURRENT_BLOCK);
	block_bar->SetView(Views::MAIN_MENU);
	block_bar->SetPos( { 90, 120 });
	block_bar->setLayer(EDITOR_BARS_LAYER);
	block_bar->SetSize( { 119, 119 });
	widgets->push_back(block_bar);

	EditorCurrentBlock *cur_block = new EditorCurrentBlock();
	cur_block->Init(nullptr);
	cur_block->setScene(this);
	cur_block->SetView(Views::MAIN_MENU);
	cur_block->SetPos(block_bar->GetPos());
	cur_block->SetSize( { editor_block_size * 4, editor_block_size * 4 });
	cur_block->setLayer(EDITOR_BUTTONS_LAYER);
	block_button = cur_block;
	widgets->push_back(cur_block);

	EditorModeButton *mode_button = new EditorModeButton();
	mode_button->Init(nullptr);
	mode_button->setScene(this);
	mode_button->SetView(Views::MAIN_MENU);
	mode_button->SetPos( { 1530, 830 });
	mode_button->setSpriteID(Textures::EDITOR_MODE_DISACTIVE);
	mode_button->SetSize( { 119, 119 });
	mode_button->setLayer(EDITOR_BARS_LAYER);
	widgets->push_back(mode_button);

	EditorDeleteButton *delete_button = new EditorDeleteButton();
	delete_button->Init(nullptr);
	delete_button->setScene(this);
	delete_button->SetView(Views::MAIN_MENU);
	delete_button->SetPos( { 1530, 700 });
	delete_button->setSpriteID(Textures::EDITOR_DELETE_DISACTIVE);
	delete_button->SetSize( { 119, 119 });
	delete_button->setLayer(EDITOR_BARS_LAYER);
	widgets->push_back(delete_button);

	EditorDisplayBar *display_bar = new EditorDisplayBar();
	display_bar->Init(nullptr);
	display_bar->setScene(this);
	display_bar->SetView(Views::MAIN_MENU);
	display_bar->SetPos( { 1530, 400 });
	display_bar->SetSize( { 119, 448 });
	display_bar->setSpriteID(Textures::EDITOR_DISPLAY_BAR);
	display_bar->setLayer(EDITOR_BARS_LAYER);
	widgets->push_back(display_bar);

	EditorBackground *b_background = new EditorBackground();
	b_background->Init(nullptr);
	b_background->setScene(this);
	b_background->SetView(Views::MAIN_MENU);
	b_background->SetPos( { 1530, EDITOR_MODE_START });
	b_background->SetSize( { 76, 76 });
	b_background->setLayer(EDITOR_BUTTONS_LAYER);
	b_background->setSpriteID(Textures::EDITOR_BACKGROUND);
	widgets->push_back(b_background);

	EditorLight *b_light = new EditorLight();
	b_light->Init(nullptr);
	b_light->setScene(this);
	b_light->SetView(Views::MAIN_MENU);
	b_light->SetPos( { 1530, EDITOR_MODE_START - 80 });
	b_light->SetSize( { 76, 76 });
	b_light->setLayer(EDITOR_BUTTONS_LAYER);
	b_light->setSpriteID(Textures::EDITOR_LIGHT);
	widgets->push_back(b_light);

	EditorGrid *b_grid = new EditorGrid();
	b_grid->Init(nullptr);
	b_grid->setScene(this);
	b_grid->SetView(Views::MAIN_MENU);
	b_grid->SetPos( { 1530, EDITOR_MODE_START - 80 * 2 });
	b_grid->SetSize( { 76, 76 });
	b_grid->setLayer(EDITOR_BUTTONS_LAYER);
	b_grid->setSpriteID(Textures::EDITOR_GRID);
	widgets->push_back(b_grid);

	EditorCross *b_cross = new EditorCross();
	b_cross->Init(nullptr);
	b_cross->setScene(this);
	b_cross->SetView(Views::MAIN_MENU);
	b_cross->SetPos( { 1530, EDITOR_MODE_START - 80 * 3 });
	b_cross->SetSize( { 76, 76 });
	b_cross->setLayer(EDITOR_BUTTONS_LAYER);
	b_cross->setSpriteID(Textures::EDITOR_CROSS);
	widgets->push_back(b_cross);

	EditorColliders *b_colliders = new EditorColliders();
	b_colliders->Init(nullptr);
	b_colliders->setScene(this);
	b_colliders->SetView(Views::MAIN_MENU);
	b_colliders->SetPos( { 1530, EDITOR_MODE_START - 80 * 4 });
	b_colliders->SetSize( { 76, 76 });
	b_colliders->setLayer(EDITOR_BUTTONS_LAYER);
	b_colliders->setSpriteID(Textures::EDITOR_COLLIDERS);
	widgets->push_back(b_colliders);

	EditorSave* save = new EditorSave(currentMap);
	save->Init(nullptr);
	save->setScene(this);
	save->SetView(Views::MAIN_MENU);
	save->setSpriteID(Textures::EDITOR_SAVE);
	save->setLayer(EDITOR_BUTTONS_LAYER);
	save->SetPos({1530, 110});
	save->SetSize({119, 119});
	widgets->push_back(save);

	// CYCLE HIT
	unsigned column_block = 0;
	unsigned row_block = 0;
	unsigned row_multi = 0;

	for (auto [id, block] : Blocks::ALL_BLOCKS) {
		EditorChooseBlock *_block = new EditorChooseBlock(cur_block);
		_block->Init(nullptr);
		_block->setScene(this);
		_block->setBlock((Block*) block->Clone());
		_block->SetView(Views::MAIN_MENU);
		_block->setLayer(EDITOR_BUTTONS_LAYER);

		if (dynamic_cast<Multiblock*>(block) != nullptr) {
			_block->SetPos(
					Vector2F(90,
							470 - 4 * (editor_block_size + 4) * row_multi));
			_block->SetSize( { 4 * editor_block_size, 4 * editor_block_size });

			row_multi++;
		} else {
			_block->SetPos(
					Vector2F(60 + column_block * (editor_block_size + 9.5) * 2,
							820 - row_block * (editor_block_size + 9.5) * 2));
			_block->SetSize( { 2 * editor_block_size, 2 * editor_block_size });

			if (column_block >= 1) {
				column_block = 0;
				row_block++;
			} else {
				column_block++;
			}
		}

		if (id == Blocks::DIRT_BLOCK->getID()) {
			currentBlock = block;
		}

		widgets->push_back(_block);
	}

	// CURRENT BLOCK HERE
	cur_block->setBlock(currentBlock);
}

bool LevelEditorScene::isDrawBackground() const {
	return draw_background;
}

void LevelEditorScene::setDrawBackground(bool drawBackground) {
	draw_background = drawBackground;
}

void LevelEditorScene::drawBackground() {
	if (draw_background) {

		DrawData info = { };
		info.position = { 800, 450 };

		info.size = { 1600, 900 };

		info.origin = { 0.5, 0.5 };

		info.frame = 0;
		info.layer = BACKGROUND_LAYER;

		info.spriteID = Textures::TEST_BACKGROUND;
		GraphicManager::Draw(info, Views::MAIN_MENU);
	}
}
