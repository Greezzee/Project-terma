#pragma once

//! В этом файле лежат все текстуры, которые мы используем в проекте.

#include "../Engine/Graphics/GraphicManager.h"

class Textures {
public:
	// ALL IDs
	// BLOCKS
	static int DIRT_BLOCK_TEXTURE, STONE_BLOCK_TEXTURE, ANIMATED_BLOCK_TEXTURE;
	static int GRASS_BLOCK_TEXTURE;

	// ENTITIES
	static int PLAYER_STAND_TEXTURE;

	// Background
	static int TEST_BACKGROUND;

	// TEST BUTTON
	static int MAIN_MENU_PLAY_BUTTON;
	static int MAIN_MENU_QUIT_BUTTON;

	//! Texture loader. LOAD EVERY TEXTURE HERE!!! BUT FIRST DEFINE IT IN THIS CLASS!!!
	static void LOAD_ALL_TEXTURES();
};

