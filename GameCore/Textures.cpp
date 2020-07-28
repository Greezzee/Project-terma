#include "Textures.h"

// Redefine
int Textures::DIRT_BLOCK_TEXTURE = 0;

void Textures::LOAD_ALL_TEXTURES() {
	Textures::DIRT_BLOCK_TEXTURE = GraphicManager::LoadSprite("/Resources/DirtBlock.png");
}
