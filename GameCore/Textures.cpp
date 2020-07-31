#include "Textures.h"

// Redefine
int Textures::PLAYER_STAND_TEXTURE = 0;
int Textures::DIRT_BLOCK_TEXTURE = -1;
int Textures::STONE_BLOCK_TEXTURE = -1;
int Textures::ANIMATED_BLOCK_TEXTURE = -1;

void Textures::LOAD_ALL_TEXTURES() {
	GraphicManager::SetSpritesMaxCount(4);
	Textures::DIRT_BLOCK_TEXTURE = GraphicManager::LoadSprite(GraphicPrefabData(std::string("./Resources/DirtBlock.png"), Vector2F(8 ,8), 1));
	Textures::STONE_BLOCK_TEXTURE = GraphicManager::LoadSprite(GraphicPrefabData(std::string("./Resources/StoneBlock.png"), Vector2F(32, 32), 1));
	Textures::ANIMATED_BLOCK_TEXTURE = GraphicManager::LoadSprite(GraphicPrefabData(std::string("./Resources/AnimatedBlock.png"), Vector2F(32, 32), 5));
	Textures::PLAYER_STAND_TEXTURE = GraphicManager::LoadSprite(GraphicPrefabData("./Resources/player.png", Vector2F(100, 100), 1));
}
