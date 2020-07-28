#include "Textures.h"

// Redefine
int Textures::DIRT_BLOCK_TEXTURE = 0;

void Textures::LOAD_ALL_TEXTURES() {
	GraphicManager::SetSpritesMaxCount(1);
	Textures::DIRT_BLOCK_TEXTURE = GraphicManager::LoadSprite("./Resources/DirtBlock.png");
}
