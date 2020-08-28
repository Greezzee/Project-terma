#pragma once

//! � ���� ����� ����� ��� ��������, ������� �� ���������� � �������.


class Textures {
public:
	// ALL IDs
	// BLOCKS
	static int DIRT_BLOCK_TEXTURE, STONE_BLOCK_TEXTURE, ANIMATED_BLOCK_TEXTURE, WHITE_BLOCK;
	static int GRASS_BLOCK_TEXTURE;
	static int RED_STONE_TOP, RED_STONE_BOTTOM, RED_STONE_MIDDLE;

	// MULTIBLOCKS
	static int TREE;
	static int LANTERN;

	// ENTITIES
	static int PLAYER_STAND_TEXTURE;

	// MOBS
	static int RED_STAR;

	// Background
	static int TEST_BACKGROUND;

	// MENU BUTTONS
	static int MAIN_MENU_PLAY_BUTTON;
	static int MAIN_MENU_PLAY_BUTTON_FOCUS;
	static int MAIN_MENU_QUIT_BUTTON;
	static int MAIN_MENU_OPTIONS_BUTTON;

	static int MAIN_OPTIONS_MENU_BACK_BUTTON;
	static int CONTROLS_BUTTON;
	static int RESOLUTION_BUTTON;
	static int SHREK;
	static int MAIN_MENU_EDITOR;

	static int INVENTORY;
	static int SWORD;

	//! Resolutions
	static int RES1920x1080;
	static int RES1600x900;
	static int RES1024x576;

	static int ITEM_FOCUS;

	// EDITOR
	static int EDITOR_PANEL;
	static int EDITOR_CURRENT_BLOCK;
	static int EDITOR_MODE_DISACTIVE;
	static int EDITOR_MODE_ACTIVE;
	static int EDITOR_DELETE_ACTIVE;
	static int EDITOR_DELETE_DISACTIVE;
	static int EDITOR_DISPLAY_BAR;
	static int EDITOR_COLLIDERS;
	static int EDITOR_CROSS;
	static int EDITOR_BACKGROUND;
	static int EDITOR_GRID;
	static int EDITOR_LIGHT;

	//! Texture loader. LOAD EVERY TEXTURE HERE!!! BUT FIRST DEFINE IT IN THIS CLASS!!!
	static void LOAD_ALL_TEXTURES();
};

