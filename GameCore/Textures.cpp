#include "Textures.h"

// Redefine
int Textures::DIRT_BLOCK_TEXTURE = 0;
int Textures::PLAYER_STAND_TEXTURE = 0;

void Textures::LOAD_ALL_TEXTURES() {
	GraphicManager::SetSpritesMaxCount(2);
	Textures::DIRT_BLOCK_TEXTURE = GraphicManager::LoadSprite("./Resources/DirtBlock.png");
	Textures::PLAYER_STAND_TEXTURE = GraphicManager::LoadSprite("./Resources/player.png");
}
