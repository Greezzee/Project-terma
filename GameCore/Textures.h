#pragma once

//! � ���� ����� ����� ��� ��������, ������� �� ���������� � �������.

#include "../Engine/Graphics/GraphicManager.h"

class Textures {
public:
	// ALL IDs
	static int DIRT_BLOCK_TEXTURE, STONE_BLOCK_TEXTURE, ANIMATED_BLOCK_TEXTURE;


	//! Texture loader. LOAD EVERY TEXTURE HERE!!! BUT FIRST DEFINE IT IN THIS CLASS!!!
	static void LOAD_ALL_TEXTURES();
};

