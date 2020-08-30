#pragma once

#include "../Map/Map.h"

// Output file details
const std::string file_name = "testLevel";
const std::string file_extension = "PTRoom";

struct codeHeader {
	//! Room's width in blocks
	int blockWidth;
	//! Room's height in blocks
	int blockHeight;
	//! Bytes amount to jump to blocks declaration
	int blocksPtr;
	//! Bytes amount to jump to wallblocks declaration
	int wallblocksPtr;
	// Bytes amount to jump to entities declaration
	int entitiesPtr;
	// Amount of entities in the room
	int entitiesCount;
};

typedef struct codeHeader codeHeader;

class LevelCoder {
public:
	static void CODE(std::string _name, Map* _map);
	static void DECODE(std::string _name, Map* _map, Vector2I start_pos);
};
