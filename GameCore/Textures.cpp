#include "Textures.h"

// Redefine
int Textures::RED_STAR = -1;
int Textures::PLAYER_STAND_TEXTURE = -1;
int Textures::DIRT_BLOCK_TEXTURE = -1;
int Textures::STONE_BLOCK_TEXTURE = -1;
int Textures::ANIMATED_BLOCK_TEXTURE = -1;
int Textures::TEST_BACKGROUND = -1;
int Textures::GRASS_BLOCK_TEXTURE = -1;
int Textures::MAIN_MENU_PLAY_BUTTON = -1;
int Textures::MAIN_MENU_QUIT_BUTTON = -1;
int Textures::MAIN_MENU_OPTIONS_BUTTON = -1;
int Textures::MAIN_OPTIONS_MENU_BACK_BUTTON = -1;
int Textures::TREE = -1;
int Textures::RED_STONE_BOTTOM = -1;
int Textures::RED_STONE_MIDDLE = -1;
int Textures::RED_STONE_TOP = -1;
int Textures::WHITE_BLOCK = -1;

void Textures::LOAD_ALL_TEXTURES() {
	GraphicManager::SetSpritesMaxCount(200);

	Textures::RED_STONE_BOTTOM = GraphicManager::LoadSprite(GraphicPrefabData(std::string("./Resources/RedStoneBottom.png"), Vector2F(64, 64), 1));
	Textures::RED_STONE_MIDDLE = GraphicManager::LoadSprite(GraphicPrefabData(std::string("./Resources/RedStoneMiddle.png"), Vector2F(64, 64), 1));
	Textures::RED_STONE_TOP = GraphicManager::LoadSprite(GraphicPrefabData(std::string("./Resources/RedStoneTop.png"), Vector2F(64, 64), 1));
	Textures::TREE = GraphicManager::LoadSprite(GraphicPrefabData(std::string("./Resources/Tree.png"), Vector2F(432, 450), 1));
	Textures::DIRT_BLOCK_TEXTURE = GraphicManager::LoadSprite(GraphicPrefabData(std::string("./Resources/DirtBlock.png"), Vector2F(8 ,8), 1));
	Textures::STONE_BLOCK_TEXTURE = GraphicManager::LoadSprite(GraphicPrefabData(std::string("./Resources/StoneBlock.png"), Vector2F(32, 32), 1));
	Textures::ANIMATED_BLOCK_TEXTURE = GraphicManager::LoadSprite(GraphicPrefabData(std::string("./Resources/AnimatedBlock.png"), Vector2F(32, 32), 5));
	Textures::PLAYER_STAND_TEXTURE = GraphicManager::LoadSprite(GraphicPrefabData("./Resources/player.png", Vector2F(96, 96), 1));
	Textures::TEST_BACKGROUND = GraphicManager::LoadSprite(GraphicPrefabData("./Resources/Background.png", Vector2F(1200, 659), 1));
	Textures::GRASS_BLOCK_TEXTURE = GraphicManager::LoadSprite(GraphicPrefabData("./Resources/GrassBlock.png", Vector2F(16, 16), 1));
	Textures::MAIN_MENU_PLAY_BUTTON = GraphicManager::LoadSprite(GraphicPrefabData("./Resources/play_button.png", Vector2F(410, 240), 1));
	Textures::MAIN_MENU_QUIT_BUTTON = GraphicManager::LoadSprite(GraphicPrefabData("./Resources/quit_button.png", Vector2F(490, 190), 1));
	Textures::RED_STAR = GraphicManager::LoadSprite(GraphicPrefabData("./Resources/RedStar.png", Vector2F(20, 19), 1));
	Textures::MAIN_MENU_OPTIONS_BUTTON = GraphicManager::LoadSprite(GraphicPrefabData("./Resources/options_button.png", Vector2F(760, 230), 1));
	Textures::MAIN_OPTIONS_MENU_BACK_BUTTON = GraphicManager::LoadSprite(GraphicPrefabData("./Resources/back_button.png", Vector2F(280, 280), 1));
	Textures::WHITE_BLOCK = GraphicManager::LoadSprite(GraphicPrefabData("./Resources/WhiteBlock.png", Vector2F(32, 32), 1));
}
