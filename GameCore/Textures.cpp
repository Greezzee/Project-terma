#include "Textures.h"
#include "../Engine/AllEngine.h"
// Redefine

int Textures::GRID = 0;

void Textures::LOAD_ALL_TEXTURES() {
	GRID = GraphicManager::LoadSprite(
			GraphicPrefabData(std::string("./Resources/DirtBlock.png"),
					Vector2F(616, 618), 1));
}
