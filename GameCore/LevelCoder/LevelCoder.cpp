#include "LevelCoder.h"

#include <bits/types/FILE.h>
#include <stddef.h>
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <string>

#include "../../Engine/Utility/Coordinate.h"
#include "../Blocks/Blocks.h"
#include "../Blocks/MultiblockStructures/StructureBlock.h"
#include "../PTC.h"

size_t fileSize(FILE *_file) {
	size_t _size;
	fseek(_file, 0, SEEK_END);
	_size = ftell(_file);
	rewind(_file);

	return _size;
}

const int SIZE = 1100000;

void LevelCoder::CODE(std::string _name, Map *_map) {
	FILE *file = fopen(_name.c_str(), "wb");

	char *buffer = (char*) calloc(sizeof(char), SIZE);
	codeHeader *header = (codeHeader*) buffer;

	header->blockWidth = MAX_LEVEL_SIZE;
	header->blockHeight = MAX_LEVEL_SIZE;
	// Will change soon
	header->blocksPtr = 0;
	header->wallblocksPtr = 0;
	header->entitiesPtr = 0;
	header->entitiesCount = 0;

	char *curr = buffer + sizeof(codeHeader);

	for (int i = 0; i < header->blockHeight; i++)
		for (int j = 0; j < header->blockWidth; j++) {
			std::cerr << "BLOCK NUMBER " << (i * header->blockWidth + j)
					<< "\n";

			Block *_block = _map->blocks[j][i];

			if (_block == nullptr) {
				// None block is there
				*((int*) (curr)) = 0;
				curr += 4;

				continue;
			}

			int _id = 0;

			if (!dynamic_cast<StructureBlock*>(_block)) {
				_id = _block->getID();
			}

			*((int*) (curr)) = _id;
			curr += 4;

			_block->code(curr);
		}

	fwrite(buffer, sizeof(char),
			sizeof(codeHeader) + header->blockWidth * header->blockHeight * 4,
			file);

	fclose(file);
	free(buffer);
}

void LevelCoder::DECODE(std::string _name, Map *_map, Vector2I start_pos) {
	codeHeader *header = nullptr;
	char *buffer = nullptr;

	FILE *file = fopen(_name.c_str(), "rb");

	if (!file) {
		PTC::say("Can't open the file!", error, high);
	}

	size_t file_size = fileSize(file);
	buffer = (char*) calloc(sizeof(char), file_size);
	fread(buffer, sizeof(char), file_size, file);

	// Header is decoded first
	header = (codeHeader*) buffer;

	char *curr = buffer + sizeof(codeHeader);

	for (int i = start_pos.y; i < header->blockHeight; i++)
		for (int j = start_pos.x; j < header->blockWidth; j++) {
			int _id = *((int*) (curr));
			curr += 4;

			if (_id == 0) {
				// Structure block
				continue;
			}

			std::cerr << "ID IS " << _id << std::endl;

			Block *_block = Blocks::createBlock(_id);

			if (dynamic_cast<Multiblock*>(_block)) {
				// If this block is a multiblock structure

				_map->placeMultiblock(Vector2I(j, i), (Multiblock*) _block);
			} else {
				_map->placeBlock(Vector2I(j, i), _block);
			}
		}

	free(buffer);
	fclose(file);
}
