#pragma once

//! В этом файле лежат все текстуры, которые мы используем в проекте.

#include "../Engine/Graphics/GraphicManager.h"

class Textures {
public:
	// ALL IDs
	// BLOCKS
	static int DIRT_BLOCK_TEXTURE;

	// ENTITIES
	static int PLAYER_STAND_TEXTURE;

	//! Texture loader. LOAD EVERY TEXTURE HERE!!! BUT FIRST DEFINE IT IN THIS CLASS!!!
	static void LOAD_ALL_TEXTURES();
};

