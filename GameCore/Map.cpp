#include "Map.h"

#include <stddef.h>

#include "Level.h"

void Map::setLevel(Level * level) {
	this->level = level;
}

Level* Map::getLevel() {
	return this->level;
}

void Map::addBlock(int x, int y, Block*block) {
	this->blocks[x][y] = block;
}

void Map::Init() {
	this->level->generate(this);
}

void Map::Update() {
}

void Map::Destroy() {
}
