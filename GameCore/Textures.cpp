#include "Textures.h"

// Redefine
int Textures::PLAYER_STAND_TEXTURE = -1;
int Textures::DIRT_BLOCK_TEXTURE = -1;
int Textures::STONE_BLOCK_TEXTURE = -1;
int Textures::ANIMATED_BLOCK_TEXTURE = -1;
int Textures::TEST_BACKGROUND = -1;
int Textures::GRASS_BLOCK_TEXTURE = -1;

void Textures::LOAD_ALL_TEXTURES() {
	GraphicManager::SetSpritesMaxCount(6);
	Textures::DIRT_BLOCK_TEXTURE = GraphicManager::LoadSprite(GraphicPrefabData(std::string("./Resources/DirtBlock.png"), Vector2F(8 ,8), 1));
	Textures::STONE_BLOCK_TEXTURE = GraphicManager::LoadSprite(GraphicPrefabData(std::string("./Resources/StoneBlock.png"), Vector2F(32, 32), 1));
	Textures::ANIMATED_BLOCK_TEXTURE = GraphicManager::LoadSprite(GraphicPrefabData(std::string("./Resources/AnimatedBlock.png"), Vector2F(32, 32), 5));
	Textures::PLAYER_STAND_TEXTURE = GraphicManager::LoadSprite(GraphicPrefabData("./Resources/player.png", Vector2F(122, 231), 1));
	Textures::TEST_BACKGROUND = GraphicManager::LoadSprite(GraphicPrefabData("./Resources/Background.png", Vector2F(1200, 659), 1));
	Textures::GRASS_BLOCK_TEXTURE = GraphicManager::LoadSprite(GraphicPrefabData("./Resources/GrassBlock.png", Vector2F(16, 16), 1));
}
