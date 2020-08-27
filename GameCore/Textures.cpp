#include "Textures.h"
#include "../Engine/AllEngine.h"
// Redefine
int Textures::RED_STAR = -1;
int Textures::PLAYER_STAND_TEXTURE = -1;
int Textures::DIRT_BLOCK_TEXTURE = -1;
int Textures::STONE_BLOCK_TEXTURE = -1;
int Textures::ANIMATED_BLOCK_TEXTURE = -1;
int Textures::TEST_BACKGROUND = -1;
int Textures::GRASS_BLOCK_TEXTURE = -1;
int Textures::MAIN_MENU_PLAY_BUTTON = -1;
int Textures::MAIN_MENU_PLAY_BUTTON_FOCUS = -1;
int Textures::MAIN_MENU_QUIT_BUTTON = -1;
int Textures::MAIN_MENU_OPTIONS_BUTTON = -1;
int Textures::MAIN_OPTIONS_MENU_BACK_BUTTON = -1;
int Textures::TREE = -1;
int Textures::RED_STONE_BOTTOM = -1;
int Textures::RED_STONE_MIDDLE = -1;
int Textures::RED_STONE_TOP = -1;
int Textures::SHREK = -1;
int Textures::INVENTORY = -1;
int Textures::CONTROLS_BUTTON = -1;
int Textures::WHITE_BLOCK = -1;
int Textures::RESOLUTION_BUTTON = -1;
int Textures::LANTERN = -1;
int Textures::SWORD = -1;
int Textures::ITEM_FOCUS = -1;
int Textures::MAIN_MENU_EDITOR = -1;
int Textures::RES1920x1080 = -1;
int Textures::RES1600x900 = -1;
int Textures::RES1024x576 = -1;
int Textures::EDITOR_PANEL = -1;
int Textures::EDITOR_CURRENT_BLOCK = -1;
int Textures::EDITOR_MODE_DISACTIVE = -1;
int Textures::EDITOR_MODE_ACTIVE = -1;

void Textures::LOAD_ALL_TEXTURES() {
	GraphicManager::SetSpritesMaxCount(200);

	Textures::LANTERN = GraphicManager::LoadSprite(
			GraphicPrefabData(std::string("./Resources/Lantern.png"),
					Vector2F(38, 71), 1));
	Textures::RED_STONE_BOTTOM = GraphicManager::LoadSprite(
			GraphicPrefabData(std::string("./Resources/RedStoneBottom.png"),
					Vector2F(8, 8), 1));
	Textures::RED_STONE_MIDDLE = GraphicManager::LoadSprite(
			GraphicPrefabData(std::string("./Resources/RedStoneMiddle.png"),
					Vector2F(8, 8), 1));
	Textures::RED_STONE_TOP = GraphicManager::LoadSprite(
			GraphicPrefabData(std::string("./Resources/RedStoneTop.png"),
					Vector2F(8, 8), 1));
	Textures::TREE = GraphicManager::LoadSprite(
			GraphicPrefabData(std::string("./Resources/Tree.png"),
					Vector2F(432, 450), 1));
	Textures::DIRT_BLOCK_TEXTURE = GraphicManager::LoadSprite(
			GraphicPrefabData(std::string("./Resources/DirtBlock.png"),
					Vector2F(8, 8), 1));
	Textures::STONE_BLOCK_TEXTURE = GraphicManager::LoadSprite(
			GraphicPrefabData(std::string("./Resources/StoneBlock.png"),
					Vector2F(32, 32), 1));
	Textures::ANIMATED_BLOCK_TEXTURE = GraphicManager::LoadSprite(
			GraphicPrefabData(std::string("./Resources/AnimatedBlock.png"),
					Vector2F(32, 32), 5));
	Textures::PLAYER_STAND_TEXTURE = GraphicManager::LoadSprite(
			GraphicPrefabData("./Resources/player.png", Vector2F(96, 96), 1));
	Textures::TEST_BACKGROUND = GraphicManager::LoadSprite(
			GraphicPrefabData("./Resources/Background.png", Vector2F(1200, 659),
					1));
	Textures::GRASS_BLOCK_TEXTURE = GraphicManager::LoadSprite(
			GraphicPrefabData("./Resources/GrassBlock.png", Vector2F(16, 16),
					1));

	Textures::MAIN_MENU_OPTIONS_BUTTON = GraphicManager::LoadSprite(
			GraphicPrefabData("./Resources/options_button.png",
					Vector2F(620, 130), 1));
	Textures::MAIN_OPTIONS_MENU_BACK_BUTTON = GraphicManager::LoadSprite(
			GraphicPrefabData("./Resources/back_button.png", Vector2F(280, 280),
					1));
	Textures::MAIN_MENU_PLAY_BUTTON = GraphicManager::LoadSprite(
			GraphicPrefabData("./Resources/play_button.png", Vector2F(128, 32),
					1));
	Textures::MAIN_MENU_PLAY_BUTTON_FOCUS = GraphicManager::LoadSprite(
			GraphicPrefabData("./Resources/play_button_focus.png",
					Vector2F(128, 32), 1));
	Textures::MAIN_MENU_QUIT_BUTTON = GraphicManager::LoadSprite(
			GraphicPrefabData("./Resources/quit_button.png", Vector2F(470, 170),
					1));
	Textures::MAIN_MENU_EDITOR = GraphicManager::LoadSprite(
			GraphicPrefabData("./Resources/editor_button.png",
					Vector2F(330, 130), 1));

	Textures::RED_STAR = GraphicManager::LoadSprite(
			GraphicPrefabData("./Resources/RedStar.png", Vector2F(20, 19), 1));

	Textures::SHREK = GraphicManager::LoadSprite(
			GraphicPrefabData("./Resources/shrek.png", Vector2F(750, 650), 1));
	Textures::INVENTORY = GraphicManager::LoadSprite(
			GraphicPrefabData("./Resources/inventory.png", Vector2F(1272, 679),
					1));
	Textures::CONTROLS_BUTTON = GraphicManager::LoadSprite(
			GraphicPrefabData("./Resources/controls_button.png",
					Vector2F(62, 13), 1));
	Textures::WHITE_BLOCK = GraphicManager::LoadSprite(
			GraphicPrefabData("./Resources/WhiteBlock.png", Vector2F(32, 32),
					1));
	Textures::RESOLUTION_BUTTON = GraphicManager::LoadSprite(
			GraphicPrefabData("./Resources/resolution_button.png",
					Vector2F(62, 13), 1));
	Textures::SWORD = GraphicManager::LoadSprite(
			GraphicPrefabData("./Resources/sword.png", Vector2F(300, 320), 1));

	Textures::ITEM_FOCUS = GraphicManager::LoadSprite(
			GraphicPrefabData("./Resources/item_focus.png", Vector2F(300, 320),
					1));
	Textures::RES1024x576 = GraphicManager::LoadSprite(
			GraphicPrefabData("./Resources/1024x576.png", Vector2F(62, 13),
					1));
	Textures::RES1600x900 = GraphicManager::LoadSprite(
				GraphicPrefabData("./Resources/1600x900.png", Vector2F(62, 13),
						1));
	Textures::RES1920x1080 = GraphicManager::LoadSprite(
				GraphicPrefabData("./Resources/1920x1080.png", Vector2F(62, 13),
						1));
	Textures::EDITOR_PANEL = GraphicManager::LoadSprite(
			GraphicPrefabData("./Resources/editor_panel.png", Vector2F(130, 330),
					1));
	Textures::EDITOR_CURRENT_BLOCK = GraphicManager::LoadSprite(
			GraphicPrefabData("./Resources/editor_current_block.png", Vector2F(17, 17),
					1));
	Textures::EDITOR_MODE_DISACTIVE = GraphicManager::LoadSprite(
			GraphicPrefabData("./Resources/editor_wallmode.png", Vector2F(17, 17),
					1));
	Textures::EDITOR_MODE_ACTIVE = GraphicManager::LoadSprite(
				GraphicPrefabData("./Resources/editor_wallmode_active.png", Vector2F(17, 17),
						1));
}
