#include "Map.h"

#include <stddef.h>

#include "Level.h"

void Map::setLevel(Level * level) {
	this->level = level;
}

Level* Map::getLevel() {
	return this->level;
}

void Map::Init() {
	GameField::Init();
	this->level->generate(this);
}

void Map::Update() {
	GameField::Update();
}

void Map::Destroy() {
	GameField::Destroy();
}
