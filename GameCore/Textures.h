#pragma once

//! В этом файле лежат все текстуры, которые мы используем в проекте.

#include "../Engine/Graphics/GraphicManager.h"

class Textures {
public:
	// ALL IDs
	// BLOCKS
	static int DIRT_BLOCK_TEXTURE, STONE_BLOCK_TEXTURE, ANIMATED_BLOCK_TEXTURE, WHITE_BLOCK;
	static int GRASS_BLOCK_TEXTURE;
	static int RED_STONE_TOP, RED_STONE_BOTTOM, RED_STONE_MIDDLE;

	// MULTIBLOCKS
	static int TREE;

	// ENTITIES
	static int PLAYER_STAND_TEXTURE;

	// MOBS
	static int RED_STAR;

	// Background
	static int TEST_BACKGROUND;

	// TEST BUTTON
	static int MAIN_MENU_PLAY_BUTTON;
	static int MAIN_MENU_QUIT_BUTTON;
	static int MAIN_MENU_OPTIONS_BUTTON;

	static int MAIN_OPTIONS_MENU_BACK_BUTTON;
	static int CONTROLS_BUTTON;
	static int RESOLUTION_BUTTON;
	static int SHREK;

	static int INVENTORY;

	//! Texture loader. LOAD EVERY TEXTURE HERE!!! BUT FIRST DEFINE IT IN THIS CLASS!!!
	static void LOAD_ALL_TEXTURES();
};

